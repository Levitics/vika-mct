
#include <didactics/core/chronos/TimeoutGuard.hpp>

TimeoutGuard::TimeoutGuard() {
}

TimeoutGuard::TimeoutGuard(const TimeoutGuard & orig) {
}

TimeoutGuard::~TimeoutGuard() {
}

TimeoutGuard::TimeoutGuard(
    clock::duration timeout ,
    std::function<void ( void )> alarm ,
    clock::duration naptime
    )
    : timeout( timeout )
    , alarm( alarm )
    , naptime( naptime )
{
    idle.store( true );
    live.store( true );

    guard_thread = std::thread( std::bind( &TimeoutGuard::guard , this ) );
}

TimeoutGuard::TimeoutGuard(
    clock::duration timeout ,
    std::function<void ( void )> alarm
    )
    : TimeoutGuard( timeout , alarm , timeout )
{
};

TimeoutGuard::~TimeoutGuard()
{
    live.store( false );
    wakeup.notify_all();
    guard_thread.join();
}

void TimeoutGuard::guard ()
{
    while ( live.load() )
    {
        if ( idle.load() )
        {
            // Sleep indefinitely until either told to become active or destruct
            std::unique_lock<std::mutex> live_lock( guard_mutex );
            wakeup.wait( live_lock , [this]() {
                return !this->idle.load() || !this->live.load();
            } );
        }

        ;

        // quit the loop if destructing
        if ( !live.load() )
            break;

        // the actual timeout checking
        auto now = clock::now();

        if ( (now - touched.load() ) > timeout )
        {
            idle.store( true );
            alarm();
            continue;     // skip waiting for next timeout
        }

        {
            // sleep until next timeout check or destruction
            std::unique_lock<std::mutex> live_lock( guard_mutex );
            wakeup.wait_for( live_lock , naptime , [this]() {
                return !this->live.load();
            } );
        }
    }

    ;
}

void TimeoutGuard::watch ()
{
    touch();
    idle.store( false );
    wakeup.notify_all();
}

void TimeoutGuard::touch ()
{
    touched.store( clock::now() );
}

/*

     TEST_CLASS( TimeoutGuardTest )
    {
    public:

        bool triggered = false;

        void shoud_trigger()
        {
            triggered = true;
        }

        TEST_METHOD( TimeoutGuardExpiration )
        {
            TimeoutGuard tg{
                std::chrono::milliseconds{ 5 },
                std::bind( &TimeoutGuardTest::shoud_trigger, this )
            };

            triggered = false;
            tg.watch();
            std::this_thread::sleep_for( std::chrono::milliseconds{ 10 } );
            Assert::IsTrue( triggered, L"Failed to call the timeout alarm on the first run", LINE_INFO() );

            triggered = false;
            tg.watch();
            std::this_thread::sleep_for( std::chrono::milliseconds{ 10 } );
            Assert::IsTrue( triggered, L"Failed to call the timeout alarm on the second run", LINE_INFO() );
        }


        TEST_METHOD( TimeoutGuardNoAlarm )
        {
            TimeoutGuard tg{
                std::chrono::milliseconds{ 5 },
                std::bind( &TimeoutGuardTest::shoud_trigger, this )
            };

            triggered = false;
            tg.watch();
            std::this_thread::sleep_for( std::chrono::milliseconds{ 1 } );
            Assert::IsFalse( triggered, L"Wrongly called the timeout alarm on the first run", LINE_INFO() );

            triggered = false;
            tg.watch();
            for (auto i = 0; i < 10; ++i)
            {
                std::this_thread::sleep_for( std::chrono::milliseconds{ 1 } );
                tg.touch();
            }
            Assert::IsFalse( triggered, L"Wrongly called the timeout alarm on the second run", LINE_INFO() );
        }

 */

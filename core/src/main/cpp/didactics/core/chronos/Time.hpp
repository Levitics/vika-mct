
#ifndef TIME_HPP
#define TIME_HPP
#include <chrono>
#include <condition_variable>
#include <functional>
#include <map>
#include <memory>
#include <mutex>
#include <thread>
class Time
{
public:

    typedef std::chrono::steady_clock Clock;
    typedef std::function<void ()> Cancel;
    typedef std::function<void ()> Callback;
    /*
         {
             ScopeTimer Tmr();
             doSomeStuff();
         } here you ll have some duration
     */
    class ScopeTimer
    {
        std::chrono::high_resolution_clock::time_point start;
        ScopeTimer()
        {
            start = std::chrono::high_resolution_clock::now();
        }

        virtual ~ScopeTimer()
        {
            using std::chrono::duration_cast;
            using std::chrono::nanoseconds;
            auto end = std::chrono::high_resolution_clock::now();

            auto duration = duration_cast<nanoseconds>(end - start);
        }

    };

    Time(const Time & orig);
    virtual ~Time();

    static Cancel deferUntil (Clock::time_point timePoint , Callback & cb);
    /*    static Promise<void> promiseUntil(Clock::time_point timePoint);

        template <class Rep, class Period>
        static Promise<void> promiseFor(std::chrono::duration<Rep, Period> const& duration)
        {
            return Promise<void>([duration](std::function<void()> resolve)
            {
                deferFor(duration, resolve);
            });
        }
     */
    template <class Rep , class Period>
    static Cancel deferFor (std::chrono::duration<Rep , Period> const & duration ,
                            Callback & cb)
    {
        return deferUntil(Clock::now() + duration , cb);
    }

protected:

    Time();

private:

    void startHandler ();
    typedef std::shared_ptr<Time> Ptr;
    static Ptr & get ();
    Cancel deferImplementation (Clock::time_point timePoint , Callback cb);

    typedef std::multimap<Clock::time_point , std::shared_ptr<Callback> > Timeouts;
    Timeouts m_timeouts;
    std::mutex m_mutex;
    std::condition_variable m_cv;
    std::unique_ptr<std::thread> m_thread;


    // std::chrono::time_point<system_clock, system_clock::duration> startingTime;
    // std::time_point<system_clock, system_clock::duration> endingTime;                        // end time;
    //  duration<system_clock::rep, system_clock::period> totalTime();          // Function for calculating the time difference between start and end
};

#endif /* TIME_HPP */

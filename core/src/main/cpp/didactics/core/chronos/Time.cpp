
#include <didactics/core/chronos/Time.hpp>

Time::Time() {
}

Time::Time(const Time & orig) {
}

Time::~Time() {
}

/*
   Time::Cancel Time::deferUntil(Clock::time_point timePoint, Callback& cb)
   {
    return get()->deferImplementation(timePoint, cb);
   }

   Promise<void> Time::promiseUntil(Clock::time_point timePoint)
   {
    return Promise<void>([timePoint](std::function<void()> resolve)
    {
        deferUntil(timePoint, resolve);
    });
   }

   Time::~Time()
   {
    if (m_thread)
    {
        m_thread->join();
    }
   }

   Time::Time()
    : m_timeouts()
    , m_mutex()
    , m_cv()
    , m_thread(nullptr)
   {
   }

   Time::Ptr& Time::get()
   {
    static Ptr time(new Time);
    return time;
   }

   Time::Cancel Time::deferImplementation(Clock::time_point timePoint, Time::Callback cb)
   {
    auto task = Task::create();
    std::lock_guard<std::mutex> lock(m_mutex);
    std::shared_ptr<Callback> v(new Callback([task, cb]()
    {
        task->complete(cb);
    }));
    if (m_timeouts.empty())
    {
        if (m_thread)
        {
            m_thread->join();
        }
        m_thread.reset(new std::thread([this]()
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            while (!m_timeouts.empty())
            {
                if (Clock::now() >= m_timeouts.cbegin()->first)
                {
                    (*m_timeouts.cbegin()->second)();
                    m_timeouts.erase(m_timeouts.cbegin());
                }
                else
                {
                    m_cv.wait_until(lock, m_timeouts.cbegin()->first);
                }
            }
        }));
    }
    m_timeouts.emplace(timePoint, v);
    m_cv.notify_one();
    return [this, v]()
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        auto it = std::find_if(m_timeouts.cbegin(),
        m_timeouts.cend(),
        [v](Timeouts::value_type const& e)
        {
            return e.second == v;
        });
        if (it != m_timeouts.cend())
        {
            m_timeouts.erase(it);
        }
    };
   }


 */

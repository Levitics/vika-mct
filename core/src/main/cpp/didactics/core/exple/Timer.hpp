
#ifndef TIMER_HPP
#define TIMER_HPP
#include <log4cxx/logger.h>
class Timer
{
public:

    Timer();
    Timer(const Timer& orig);
    virtual ~Timer();
    virtual void Start (int) = 0;
    virtual void Stop () = 0;
    virtual bool IsActive () = 0;
    virtual std::string GetId () = 0;

private:

    log4cxx::LoggerPtr logger;
};

#endif

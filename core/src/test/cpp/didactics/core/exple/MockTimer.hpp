
#ifndef MOCKTIMER_HPP
#define MOCKTIMER_HPP
#include <log4cxx/logger.h>
#include <didactics/core/exple/Timer.hpp>
#include <gmock/gmock.h>

class MockTimer : public Timer
{
public:

    MockTimer();
    MockTimer(const MockTimer& orig);
    virtual ~MockTimer();
    MOCK_METHOD1(Start , void (int));
    MOCK_METHOD0(Stop , void());
    MOCK_METHOD0(IsActive , bool());
    MOCK_METHOD0(GetId , std::string());

private:

    log4cxx::LoggerPtr logger;
};

#endif

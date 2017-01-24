
#ifndef TIMERTEST_HPP
#define TIMERTEST_HPP
#include <didactics/core/exple/MockTimer.hpp>
#include <gtest/gtest.h>

class TimerTest : public ::testing::Test
{

public:

    TimerTest();
    TimerTest(const TimerTest & orig);
    virtual ~TimerTest();
    /*!
     * @brief Test set up.
     */
    virtual void SetUp ();
    /*!
     * @brief Test tear down.
     */
    virtual void TearDown ();

protected:

    static log4cxx::LoggerPtr logger;
    static MockTimer * objectUnderTest;

private:

};

#endif

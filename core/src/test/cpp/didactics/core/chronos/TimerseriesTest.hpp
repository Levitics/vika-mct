
#ifndef TIMERSERIESTEST_HPP
#define TIMERSERIESTEST_HPP
#include <didactics/core/chronos/Timerseries.hpp>
#include <gtest/gtest.h>


class TimerseriesTest  : public ::testing::Test
{
public:

    TimerseriesTest();
    TimerseriesTest(const TimerseriesTest & orig);
    virtual ~TimerseriesTest();
    /**
     * @brief Test set up.
     */
    virtual void SetUp ();
    /**
     * @brief Test tear down.
     */
    virtual void TearDown ();

protected:

    /*!
     * @brief ClockerStatistics utility test class logger.
     */
    static log4cxx::LoggerPtr logger;

private:

};

#endif

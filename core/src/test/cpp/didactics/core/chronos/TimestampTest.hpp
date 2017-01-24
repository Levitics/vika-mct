
#ifndef TIMESTAMPTEST_HPP
#define TIMESTAMPTEST_HPP

#include <didactics/core/chronos/Timestamp.hpp>
#include <gtest/gtest.h>


class TimestampTest : public ::testing::Test
{
public:

    TimestampTest();
    TimestampTest(const TimestampTest & orig);
    virtual ~TimestampTest();
    /**
     * @brief Test set up.
     */
    virtual void SetUp ();
    /**
     * @brief Test tear down.
     */
    virtual void TearDown ();

protected:

    static Timestamp * testObject;
    /*!
     * @brief ClockerStatistics utility test class logger.
     */
    static log4cxx::LoggerPtr logger;

private:

};

#endif

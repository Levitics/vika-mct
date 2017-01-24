
#ifndef BACKTRACETEST_HPP
#define BACKTRACETEST_HPP
#include <gtest/gtest.h>
#include <didactics/core/log/Logger.hpp>
#include <didactics/core/errorhandling/Backtrace.hpp>
class BacktraceTest   : public ::testing::Test
{
public:

    BacktraceTest();
    virtual ~BacktraceTest();

    /*!
     * @brief Test set up.
     */
    virtual void SetUp ();
    /*!
     * @brief Test tear down.
     */
    virtual void TearDown ();

protected:

    Backtrace * testObject;
    static log4cxx::LoggerPtr logger;

private:

};

#endif

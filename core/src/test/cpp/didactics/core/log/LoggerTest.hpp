
#ifndef LOGGERTEST_HPP
#define LOGGERTEST_HPP
#include <gtest/gtest.h>
#include <didactics/core/log/Hierarchy.hpp>
class LoggerTest  : public ::testing::Test
{
public:

    LoggerTest();
    LoggerTest(const LoggerTest & orig);
    virtual ~LoggerTest();
    /**
     * @brief Test set up.
     */
    virtual void SetUp ();
    /**
     * @brief Test tear down.
     */
    virtual void TearDown ();

protected:

    cxx::ThreadedLogging * threadedLogging;
    cxx::Hierarchy * hierarchy;
    cxx::Hierarchy2 * hierarchy2;
    cxx::Hierarchy3 * hierarchy3;
    cxx::cxx2::Hierarchy * cxx2hierarchy;
    cxx::cxx2::Hierarchy2 * cxx2hierarchy2;
    cxx::cxx2::Hierarchy3 * cxx2hierarchy3;
    /*!
     * @brief Test class logger.
     */
    log4cxx::LoggerPtr logger;

private:

};

#endif

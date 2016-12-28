
#ifndef LOGGERTEST_HPP
#define LOGGERTEST_HPP
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <didactics/core/log/Hierarchy.hpp>
class LoggerTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(LoggerTest);
    CPPUNIT_TEST(dummy);
    CPPUNIT_TEST_SUITE_END();

public:

    LoggerTest();
    LoggerTest(const LoggerTest& orig);
    virtual ~LoggerTest();
    /**
     * @brief Test set up.
     */
    void setUp ();
    /**
     * @brief Test tear down.
     */
    void tearDown ();

protected:

    void dummy ();

private:

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
    static log4cxx::LoggerPtr logger;
};

#endif

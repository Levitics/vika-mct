
#ifndef TIMERTEST_HPP
#define TIMERTEST_HPP
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <didactics/core/exple/MockTimer.hpp>
#include <didactics/core/Test.hpp>
class TimerTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TimerTest);
    CPPUNIT_TEST(testIsActive);
    // CPPUNIT_TEST(testIsActiv2);
    CPPUNIT_TEST(testName);
    CPPUNIT_TEST(testName1);
    CPPUNIT_TEST(testDynamicReturnValues);
    CPPUNIT_TEST(testDynamicReturnValues1);
    CPPUNIT_TEST(testIsActiveValueUsingVariable);
    CPPUNIT_TEST_SUITE_END();

public:

    TimerTest();
    TimerTest(const TimerTest& orig);
    virtual ~TimerTest();
    /*!
     * @brief Test set up.
     */
    virtual void setUp ();
    /*!
     * @brief Test tear down.
     */
    virtual void tearDown ();

protected:

    void testIsActive ();
    void testName ();
    // void testIsActive2();
    void testName1 ();
    void testDynamicReturnValues ();
    void testDynamicReturnValues1 ();
    void testIsActiveValueUsingVariable ();

private:

    MockTimer * objectUnderTest;
    log4cxx::LoggerPtr logger;
};

#endif

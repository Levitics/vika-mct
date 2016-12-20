#ifndef TURTLETEST_HPP
#define TURTLETEST_HPP
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include <didactics/core/exple/MockTurtle.hpp>
#include <didactics/core/exple/FakeTurtle.hpp>
#include <didactics/core/exple/DelegateMockTurtle.hpp>
#include <didactics/core/Test.hpp>

class TurtleTest : public CppUnit::TestFixture{
    
    CPPUNIT_TEST_SUITE(TurtleTest);
    CPPUNIT_TEST(testGooglePenUp);
    CPPUNIT_TEST_SUITE_END();    
public:
    TurtleTest();
    TurtleTest(const TurtleTest& orig);
    virtual ~TurtleTest();
    /*!
     * @brief Test set up.
     */
    virtual void setUp();
    /*!
     * @brief Test tear down.
     */
    virtual void tearDown();
protected:
    void testGooglePenUp();
private:
    MockTurtle * objectUnderTest;
    log4cxx::LoggerPtr logger;    
};

#endif


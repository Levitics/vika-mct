#ifndef EXTENDEDTURTLETEST_HPP
#define EXTENDEDTURTLETEST_HPP
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include <didactics/core/Test.hpp>
#include <didactics/core/exple/DelegateMockTurtle.hpp>

class ExtendedTurtleTest  : public CppUnit::TestFixture{
    
    CPPUNIT_TEST_SUITE(ExtendedTurtleTest);
    CPPUNIT_TEST(testGooglePenUp);
    CPPUNIT_TEST_SUITE_END();  
public:
    ExtendedTurtleTest();
    ExtendedTurtleTest(const ExtendedTurtleTest& orig);
    virtual ~ExtendedTurtleTest();
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
    DelegateMockTurtle * objectUnderTest;
    log4cxx::LoggerPtr logger;

};

#endif


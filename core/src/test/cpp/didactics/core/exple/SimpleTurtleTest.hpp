
#ifndef SIMPLETURTLETEST_HPP
#define SIMPLETURTLETEST_HPP
#include <didactics/core/Test.hpp>
#include <didactics/core/exple/FakeTurtle.hpp>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
class SimpleTurtleTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(SimpleTurtleTest);
    CPPUNIT_TEST(testGetX);
    CPPUNIT_TEST(testGetY);
    CPPUNIT_TEST(testGetName);
    CPPUNIT_TEST_SUITE_END();

public:

    SimpleTurtleTest();
    SimpleTurtleTest(const SimpleTurtleTest& orig);
    virtual ~SimpleTurtleTest();
    /*!
     * @brief Test set up.
     */
    virtual void setUp ();
    /*!
     * @brief Test tear down.
     */
    virtual void tearDown ();

protected:

    void testGetX ();
    void testGetY ();
    void testGetName ();

private:

    FakeTurtle * objectUnderTest;
    log4cxx::LoggerPtr logger;
};

#endif

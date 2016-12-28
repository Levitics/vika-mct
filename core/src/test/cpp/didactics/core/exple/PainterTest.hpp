
#ifndef PAINTERTEST_HPP
#define PAINTERTEST_HPP
#include <didactics/core/Test.hpp>
#include <didactics/core/exple/MockTurtle.hpp>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <gmock/gmock.h>
#include <didactics/core/exple/Painter.hpp>

using ::testing::AtLeast;

class PainterTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(PainterTest);
    CPPUNIT_TEST(canDrawSomething);
    CPPUNIT_TEST_SUITE_END();

public:

    PainterTest();
    PainterTest(const PainterTest& orig);
    virtual ~PainterTest();

protected:

    void canDrawSomething ();

private:

    Painter * objectUnderTest;
    MockTurtle * turtleMock;
    log4cxx::LoggerPtr logger;
};

#endif

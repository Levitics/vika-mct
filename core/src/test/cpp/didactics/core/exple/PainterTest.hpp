
#ifndef PAINTERTEST_HPP
#define PAINTERTEST_HPP
#include <didactics/core/exple/MockTurtle.hpp>
#include <gmock/gmock.h>
#include <didactics/core/exple/Painter.hpp>

using ::testing::AtLeast;

class PainterTest : public ::testing::Test
{

public:

    PainterTest();
    PainterTest(const PainterTest & orig);
    virtual ~PainterTest();

protected:

    void canDrawSomething ();
    static Painter * objectUnderTest;
    static MockTurtle * turtleMock;
    static log4cxx::LoggerPtr logger;

private:

};

#endif

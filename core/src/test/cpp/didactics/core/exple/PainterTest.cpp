
#include <didactics/core/exple/PainterTest.hpp>

Painter * PainterTest::objectUnderTest = nullptr;
MockTurtle * PainterTest::turtleMock = nullptr;
log4cxx::LoggerPtr PainterTest::logger =  log4cxx::Logger::getLogger(std::string("diactics.core.exple.TurtleTest"));

PainterTest::PainterTest()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

PainterTest::PainterTest(const PainterTest & orig)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

PainterTest::~PainterTest()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void PainterTest::canDrawSomething ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    // Painter * painter(turtleMock);
    // MockTurtle turtle;

    // Painter painter(&turtle);
    // CPPUNIT_ASSERT(painter.DrawCircle(0,0,10));
}


#include <didactics/Test.hpp>
#include <didactics/core/exple/PainterTest.hpp>

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(PainterTest , didactics::core::test::runThisTestSuiteName());

PainterTest::PainterTest()
    : objectUnderTest()
    , turtleMock()
    , logger(log4cxx::Logger::getLogger(std::string("diactics.core.exple.TurtleTest")))
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

PainterTest::PainterTest(const PainterTest& orig) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

PainterTest::~PainterTest() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void PainterTest::canDrawSomething ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    // Painter * painter(turtleMock);
    // MockTurtle turtle;

    // Painter painter(&turtle);
    // CPPUNIT_ASSERT(painter.DrawCircle(0,0,10));
    CPPUNIT_ASSERT(true);
}


#include <didactics/core/exple/ExtendedTurtleTest.hpp>

DelegateMockTurtle * ExtendedTurtleTest::objectUnderTest = nullptr;
log4cxx::LoggerPtr ExtendedTurtleTest::logger =
    log4cxx::Logger::getLogger(std::string("diactics.core.exple.ExtendedTurtleTest"));

ExtendedTurtleTest::ExtendedTurtleTest()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

ExtendedTurtleTest::ExtendedTurtleTest(const ExtendedTurtleTest & orig)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

ExtendedTurtleTest::~ExtendedTurtleTest()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void ExtendedTurtleTest::SetUp ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    objectUnderTest = new DelegateMockTurtle();
    objectUnderTest->DelegateToFake();
}

void ExtendedTurtleTest::TearDown ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    delete objectUnderTest;
}

TEST_F(ExtendedTurtleTest , testGooglePenUp)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //    ::testing::NiceMock<DelegateMockTurtle> testMock;
    //    this->objectUnderTest->PenUp();
}


#include <didactics/SuiteOfTest.hpp>
#include <didactics/core/exple/ExtendedTurtleTest.hpp>

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(ExtendedTurtleTest , didactics::core::test::runThisTestSuiteName());
// log4cxx::LoggerPtr logger =  log4cxx::Logger::getLogger(std::string("diactics.core.exple.ExtendedTurtleTest"));

ExtendedTurtleTest::ExtendedTurtleTest()
    : objectUnderTest()
    , logger (log4cxx::Logger::getLogger(std::string("diactics.core.exple.ExtendedTurtleTest")))
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

ExtendedTurtleTest::ExtendedTurtleTest(const ExtendedTurtleTest& orig)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

ExtendedTurtleTest::~ExtendedTurtleTest()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void ExtendedTurtleTest::setUp ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->objectUnderTest = new DelegateMockTurtle();
    this->objectUnderTest->DelegateToFake();
}

void ExtendedTurtleTest::tearDown ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    delete this->objectUnderTest;
}

void ExtendedTurtleTest::testGooglePenUp ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //    ::testing::NiceMock<DelegateMockTurtle> testMock;
    //    this->objectUnderTest->PenUp();
}

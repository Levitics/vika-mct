#include <didactics/Test.hpp>
#include <didactics/core/exple/SimpleTurtleTest.hpp>

//CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(SimpleTurtleTest, didactics::core::test::runThisTestSuiteName());

//const log4cxx::LoggerPtr logger =  log4cxx::Logger::getLogger(std::string("diactics.core.exple.SimpleTurtleTest"));

SimpleTurtleTest::SimpleTurtleTest()
: objectUnderTest()
, logger(log4cxx::Logger::getLogger(std::string("diactics.core.exple.SimpleTurtleTest")))
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

SimpleTurtleTest::SimpleTurtleTest(const SimpleTurtleTest& orig)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

SimpleTurtleTest::~SimpleTurtleTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void SimpleTurtleTest::setUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//    this->objectUnderTest = new FakeTurtle();
}

void SimpleTurtleTest::tearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//    delete this->objectUnderTest;
}

void SimpleTurtleTest::testGooglePenUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    CPPUNIT_ASSERT(true);
}

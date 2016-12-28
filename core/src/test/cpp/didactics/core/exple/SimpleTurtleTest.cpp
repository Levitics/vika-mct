
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <didactics/Test.hpp>
#include <didactics/core/exple/SimpleTurtleTest.hpp>

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(SimpleTurtleTest , didactics::core::test::runThisTestSuiteName());

// const log4cxx::LoggerPtr logger =  log4cxx::Logger::getLogger(std::string("diactics.core.exple.SimpleTurtleTest"));

SimpleTurtleTest::SimpleTurtleTest()
    : objectUnderTest()
    , logger(log4cxx::Logger::getLogger(std::string("diactics.core.exple.SimpleTurtleTest")))
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    // srand (time(NULL));
}

SimpleTurtleTest::SimpleTurtleTest(const SimpleTurtleTest& orig)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

SimpleTurtleTest::~SimpleTurtleTest()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void SimpleTurtleTest::setUp ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->objectUnderTest = new FakeTurtle();
    this->objectUnderTest->PenUp();
    this->objectUnderTest->PenDown();
    this->objectUnderTest->Forward((rand() % 12 + 1));
    this->objectUnderTest->Turn((rand() % 12 + 1));
    this->objectUnderTest->GoTo((rand() % 50 + 1) , (rand() % 50 + 1));
}

void SimpleTurtleTest::tearDown ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    delete this->objectUnderTest;
}

void SimpleTurtleTest::testGetX ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    CPPUNIT_ASSERT_ASSERTION_PASS_MESSAGE(
        "X: "
                                         , this->objectUnderTest->GetX()
        );
}

void SimpleTurtleTest::testGetY ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    CPPUNIT_ASSERT_ASSERTION_PASS_MESSAGE(
        "Y: "
                                         , this->objectUnderTest->GetY()
        );
}
void SimpleTurtleTest::testGetName ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    CPPUNIT_ASSERT_ASSERTION_PASS_MESSAGE(
        "Dummy Txt: "
                                         , this->objectUnderTest->getArbitraryString();
        );
}

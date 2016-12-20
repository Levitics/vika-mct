#include <didactics/Test.hpp>
#include <didactics/core/exple/TurtleTest.hpp>
 
//CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(TurtleTest, didactics::core::test::runThisTestSuiteName());
//log4cxx::LoggerPtr logger = log4cxx::Logger::getLogger(std::string("diactics.core.exple.TurtleTest"));

TurtleTest::TurtleTest()
: objectUnderTest()
, logger(log4cxx::Logger::getLogger(std::string("diactics.core.exple.TurtleTest")))
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TurtleTest::TurtleTest(const TurtleTest& orig) {
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TurtleTest::~TurtleTest() {
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void TurtleTest::setUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    this->objectUnderTest = new MockTurtle();
}

void TurtleTest::tearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    delete this->objectUnderTest;
}

void TurtleTest::testGooglePenUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    /*    
    std::shared_ptr<Turtle> mockt(new MockTurtle);
    EXPECT_CALL(*std::static_pointer_cast<MockTurtle>(mockt),
              PenUp()).Times(testing::AtLeast(1));

     EXPECT_CALL(MockTurtle.PenUp())
        .With(...) ?
        .Times(...) ?
        .InSequence(...) *
        .WillOnce(...) *
        .WillRepeatedly(...) ?
        .RetiresOnSaturation() ? ;
         //this->objectUnderTest->PenUp();
    */ 
    CPPUNIT_ASSERT(true);    
}


#include <didactics/core/exple/TimerTest.hpp>
#include <didactics/Test.hpp>

using ::testing::_;
using ::testing::AtLeast;
using ::testing::Gt;
using ::testing::NotNull;
using ::testing::InvokeWithoutArgs;
using ::testing::AnyNumber;
using ::testing::Return;
using ::testing::Invoke;
using ::testing::NiceMock;
using ::testing::ReturnRef;
using ::testing::SaveArg;
using ::testing::InSequence;


CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(TimerTest , didactics::core::test::runThisTestSuiteName());

TimerTest::TimerTest()
    : objectUnderTest()
    , logger(log4cxx::Logger::getLogger(std::string("diactics.core.exple.TimerTest")))
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TimerTest::TimerTest(const TimerTest& orig) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TimerTest::~TimerTest() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void TimerTest::setUp ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->objectUnderTest = new MockTimer();
}

void TimerTest::tearDown ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    delete this->objectUnderTest;
}

void TimerTest::testIsActive ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    EXPECT_CALL(*objectUnderTest , IsActive()).Times(AnyNumber());

    CPPUNIT_ASSERT_EQUAL_MESSAGE("Unexpected timer status !"
                                , false
                                , objectUnderTest->IsActive());
}

void TimerTest::testName ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    EXPECT_CALL(*objectUnderTest , GetId()).WillRepeatedly(Return(std::string("someDefaultValue")));

    CPPUNIT_ASSERT_EQUAL_MESSAGE(
        "Value mismatch !" ,
        std::string("someDefaultValue") , objectUnderTest->GetId());
}
/*
   void TimerTest::testIsActive2()
   {
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    MockTimer timer;
    EXPECT_CALL(timer, IsActive()).Times(AnyNumber());
   }
 */

void TimerTest::testName1 ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    ::testing::DefaultValue<std::string>::Set(std::string("Some Default Value"));

    EXPECT_CALL(*objectUnderTest , GetId()).Times(AnyNumber());
    CPPUNIT_ASSERT_EQUAL_MESSAGE(
        "Value mismatch !" ,
        std::string("Some Default Value") , objectUnderTest->GetId());
}

void TimerTest::testDynamicReturnValues ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    EXPECT_CALL(*objectUnderTest ,
                IsActive()).WillOnce(Return(false)).WillOnce(Return(true)).WillRepeatedly(Return(false));

    CPPUNIT_ASSERT_EQUAL(false , objectUnderTest->IsActive());
    CPPUNIT_ASSERT_EQUAL(true , objectUnderTest->IsActive());
    CPPUNIT_ASSERT_EQUAL(false , objectUnderTest->IsActive());
    CPPUNIT_ASSERT_EQUAL(false , objectUnderTest->IsActive());
    CPPUNIT_ASSERT_EQUAL(false , objectUnderTest->IsActive());
}

void TimerTest::testDynamicReturnValues1 ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    InSequence s;
    EXPECT_CALL(*objectUnderTest , IsActive()).WillOnce(Return(false));
    EXPECT_CALL(*objectUnderTest , Start(_));
    EXPECT_CALL(*objectUnderTest , IsActive()).WillOnce(Return(true));
    EXPECT_CALL(*objectUnderTest , Stop());
    EXPECT_CALL(*objectUnderTest , IsActive()).WillRepeatedly(Return(false));

    // *
    CPPUNIT_ASSERT_EQUAL(false , objectUnderTest->IsActive());
    objectUnderTest->Start(1000);
    CPPUNIT_ASSERT_EQUAL(true , objectUnderTest->IsActive());
    objectUnderTest->Stop();
    CPPUNIT_ASSERT_EQUAL(false , objectUnderTest->IsActive());

    // */

    /*
        LOG4CXX_TRACE(logger, timer.IsActive());
        timer.Start(1000);
        LOG4CXX_TRACE(logger, timer.IsActive());
        timer.Stop();
        LOG4CXX_TRACE(logger, timer.IsActive());
       //*/

}

void TimerTest::testIsActiveValueUsingVariable ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    bool timerActive = false;

    EXPECT_CALL(*objectUnderTest , IsActive()).WillRepeatedly(::testing::ReturnPointee(&timerActive));
    EXPECT_CALL(*objectUnderTest , Start(_)).WillRepeatedly(::testing::Assign(&timerActive , true));
    EXPECT_CALL(*objectUnderTest , Stop()).WillRepeatedly(::testing::Assign(&timerActive , false));

    CPPUNIT_ASSERT_EQUAL(false , objectUnderTest->IsActive());
    objectUnderTest->Start(1000);
    CPPUNIT_ASSERT_EQUAL(true , objectUnderTest->IsActive());
    objectUnderTest->Stop();
    CPPUNIT_ASSERT_EQUAL(false , objectUnderTest->IsActive());
    CPPUNIT_ASSERT_EQUAL(false , objectUnderTest->IsActive());
}

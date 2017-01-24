
#include <didactics/core/exple/TimerTest.hpp>

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

MockTimer * TimerTest::objectUnderTest = nullptr;
log4cxx::LoggerPtr TimerTest::logger = log4cxx::Logger::getLogger(std::string("didactics.core.utils.TimerTest"));

TimerTest::TimerTest()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TimerTest::TimerTest(const TimerTest & orig) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TimerTest::~TimerTest() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void TimerTest::SetUp ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //    const ::testing::TestInfo* const test_info =
    //            ::testing::UnitTest::GetInstance()->current_test_info();
    //    LOG4CXX_INFO(logger , "happyman@ubuntu" << test_info->name() <<"--"<< test_info->test_case_name());
    objectUnderTest = new MockTimer();
}

void TimerTest::TearDown ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    delete objectUnderTest;
}

TEST_F(TimerTest , testStart)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    EXPECT_CALL(*objectUnderTest , IsActive())
    .WillOnce(Return(true))
    .WillRepeatedly (Return (false));
    EXPECT_TRUE(objectUnderTest->IsActive());
    EXPECT_FALSE(objectUnderTest->IsActive());
}

TEST_F(TimerTest , testAll)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}
TEST_F(TimerTest , testStop)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}
TEST_F(TimerTest , testIsActive)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    EXPECT_CALL(*objectUnderTest , IsActive()).Times(AnyNumber());
    EXPECT_FALSE(objectUnderTest->IsActive());

}
TEST_F(TimerTest , testGetId)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(TimerTest , testName)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    EXPECT_CALL(*objectUnderTest , GetId()).WillRepeatedly(Return(std::string("someDefaultValue")));
    EXPECT_EQ(std::string("someDefaultValue") , objectUnderTest->GetId());
}


TEST_F(TimerTest , testIsActive2)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //    MockTimer timer;
    //    EXPECT_CALL(timer, IsActive()).Times(AnyNumber());
}


TEST_F(TimerTest , testName1 )
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    ::testing::DefaultValue<std::string>::Set(std::string("Some Default Value"));

    EXPECT_CALL(*objectUnderTest , GetId()).Times(AnyNumber());
    EXPECT_EQ(std::string("Some Default Value") , objectUnderTest->GetId());
}

TEST_F(TimerTest , testDynamicReturnValues)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    EXPECT_CALL(*objectUnderTest ,
                IsActive()).WillOnce(Return(false)).WillOnce(Return(true)).WillRepeatedly(Return(false));

    EXPECT_FALSE(objectUnderTest->IsActive());
    EXPECT_TRUE(objectUnderTest->IsActive());
    EXPECT_FALSE(objectUnderTest->IsActive());
    EXPECT_FALSE(objectUnderTest->IsActive());
    EXPECT_FALSE(objectUnderTest->IsActive());
}

TEST_F(TimerTest , testDynamicReturnValues1 )
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    InSequence s;
    EXPECT_CALL(*objectUnderTest , IsActive()).WillOnce(Return(false));
    EXPECT_CALL(*objectUnderTest , Start(_));
    EXPECT_CALL(*objectUnderTest , IsActive()).WillOnce(Return(true));
    EXPECT_CALL(*objectUnderTest , Stop());
    EXPECT_CALL(*objectUnderTest , IsActive()).WillRepeatedly(Return(false));

    EXPECT_FALSE(objectUnderTest->IsActive());
    objectUnderTest->Start(1000);
    EXPECT_TRUE(objectUnderTest->IsActive());
    objectUnderTest->Stop();
    EXPECT_FALSE(objectUnderTest->IsActive());


    //    LOG4CXX_TRACE(logger, objectUnderTest->IsActive());
    //        objectUnderTest->Start(1000);
    //    LOG4CXX_TRACE(logger, objectUnderTest->IsActive());
    //        objectUnderTest->Stop();
    //    LOG4CXX_TRACE(logger, objectUnderTest->IsActive());
}

TEST_F(TimerTest , testIsActiveValueUsingVariable)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    bool timerActive = false;

    EXPECT_CALL(*objectUnderTest , IsActive())
    .WillRepeatedly(::testing::ReturnPointee(&timerActive));
    EXPECT_CALL(*objectUnderTest , Start(_))
    .WillRepeatedly(::testing::Assign(&timerActive , true));
    EXPECT_CALL(*objectUnderTest , Stop())
    .WillRepeatedly(::testing::Assign(&timerActive , false));

    EXPECT_FALSE(objectUnderTest->IsActive());
    objectUnderTest->Start(1000);
    EXPECT_TRUE(objectUnderTest->IsActive());
    objectUnderTest->Stop();
    EXPECT_FALSE(objectUnderTest->IsActive());
    EXPECT_FALSE(objectUnderTest->IsActive());
}

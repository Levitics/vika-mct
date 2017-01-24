
#include <didactics/core/chronos/TimestampTest.hpp>

Timestamp * TimestampTest::testObject = nullptr;

log4cxx::LoggerPtr TimestampTest::logger =
    log4cxx::Logger::getLogger(std::string("didactics.core.utils.TimestampTest"));

TimestampTest::TimestampTest()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TimestampTest::TimestampTest(const TimestampTest & orig) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

}

TimestampTest::~TimestampTest() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void TimestampTest::SetUp ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    testObject = new Timestamp();
}

void TimestampTest::TearDown ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    delete testObject;
}

TEST_F(TimestampTest , testGetTimestamp)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    timespec ts = testObject->getTimestamp();
    long s = testObject->getSeconds();
    long ns = testObject->getNanoSeconds();

    LOG4CXX_DEBUG(logger , "Second: " <<s <<" Nano Second: " <<ns);
    LOG4CXX_DEBUG(logger , "Time: " <<this->testObject->getTime());
    LOG4CXX_DEBUG(logger , "getFrequency: " <<this->testObject->getFrequency());
}

TEST_F(TimestampTest , testGetSeconds)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(TimestampTest , testGetNanoSeconds)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(TimestampTest , testGetTime)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(TimestampTest , testSet)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(TimestampTest , testSetSeconds)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(TimestampTest , testSetNanoSeconds)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(TimestampTest , testSetNow)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(TimestampTest , testGetFrequency)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

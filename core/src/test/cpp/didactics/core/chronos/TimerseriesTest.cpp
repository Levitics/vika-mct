
#include <didactics/core/chronos/TimerseriesTest.hpp>

log4cxx::LoggerPtr TimerseriesTest::logger =
    log4cxx::Logger::getLogger(std::string("didactics.core.utils.TimerseriesTest"));

TimerseriesTest::TimerseriesTest() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TimerseriesTest::TimerseriesTest(const TimerseriesTest & orig) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TimerseriesTest::~TimerseriesTest() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void TimerseriesTest::SetUp ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void TimerseriesTest::TearDown ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(TimerseriesTest , dummy)
{

}

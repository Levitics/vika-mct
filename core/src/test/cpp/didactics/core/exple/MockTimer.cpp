
#include <didactics/core/exple/MockTimer.hpp>
MockTimer::MockTimer()
    : logger (log4cxx::Logger::getLogger(std::string("diactics.core.exple.MockTimer")))
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

MockTimer::MockTimer(const MockTimer & orig) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

MockTimer::~MockTimer() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}


#include <didactics/core/exple/Timer.hpp>

Timer::Timer()
    : logger(log4cxx::Logger::getLogger(std::string("diactics.core.exple.Timer")))
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

Timer::Timer(const Timer & orig) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

Timer::~Timer() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

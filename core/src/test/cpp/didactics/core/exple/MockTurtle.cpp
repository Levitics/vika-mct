#include <gmock/gmock.h>
#include <didactics/core/exple/MockTurtle.hpp>

MockTurtle::MockTurtle() 
: logger (log4cxx::Logger::getLogger(std::string("diactics.core.exple.MockTurtle")))
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

MockTurtle::MockTurtle(const MockTurtle& orig) {
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

MockTurtle::~MockTurtle() {
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}


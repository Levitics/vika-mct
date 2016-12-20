#include <didactics/core/exple/Turtle.hpp>

Turtle::Turtle() 
:logger(log4cxx::Logger::getLogger(std::string("diactics.core.exple.Turtle")))
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Turtle::Turtle(const Turtle& orig) {
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Turtle::~Turtle() {
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}


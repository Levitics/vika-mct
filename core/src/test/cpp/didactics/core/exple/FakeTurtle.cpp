#include <didactics/core/exple/FakeTurtle.hpp>
//log4cxx::LoggerPtr logger = log4cxx::Logger::getLogger(std::string("diactics.core.exple.FakeTurtle"));
FakeTurtle::FakeTurtle() 
:logger (log4cxx::Logger::getLogger(std::string("diactics.core.exple.FakeTurtle")))
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);    
}

FakeTurtle::FakeTurtle(const FakeTurtle& orig) {
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);    
}

FakeTurtle::~FakeTurtle() {
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);    
}

void FakeTurtle::PenUp() 
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void FakeTurtle::PenDown() 
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void FakeTurtle::Forward(int distance) 
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void FakeTurtle::Turn(int degrees) 
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void FakeTurtle::GoTo(int x, int y) 
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

int FakeTurtle::GetX() const 
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

int FakeTurtle::GetY() const 
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

std::string FakeTurtle::name() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
    

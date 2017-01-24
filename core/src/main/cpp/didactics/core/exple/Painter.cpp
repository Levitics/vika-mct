
#include <didactics/core/exple/Painter.hpp>
#include "didactics/core/log/Logger.hpp"

Painter::Painter()
    : logger(log4cxx::Logger::getLogger(std::string("diactics.core.exple.Painter")))
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

Painter::Painter(const Painter & orig)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

Painter::~Painter()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

Painter::Painter(Turtle * trtl)
    : turtle(trtl)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

bool Painter::DrawCircle (int x ,
                          int y ,
                          int r)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    LOG4CXX_DEBUG(logger , "x:" << x <<"y:" << y<<"r:" << r);
    PARAM_UNUSED(x);
    PARAM_UNUSED(y);
    PARAM_UNUSED(r);
    return (true);
}

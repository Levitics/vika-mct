
#include <didactics/core/errorhandling/ErrnoMapperMock.hpp>

ErrnoMapperMock::ErrnoMapperMock()
    : logger (log4cxx::Logger::getLogger(std::string("diactics.core.errorhandling.ErrnoMapperMock")))
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

ErrnoMapperMock::~ErrnoMapperMock() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

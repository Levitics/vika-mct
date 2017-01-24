
#ifndef ERRNOMAPPERMOCK_HPP
#define ERRNOMAPPERMOCK_HPP
#include <gmock/gmock.h>
#include <didactics/core/errorhandling/ErrnoMapper.hpp>
#include <didactics/core/log/Logger.hpp>
class ErrnoMapperMock
{
public:

    ErrnoMapperMock();
    //    ErrnoMapperMock(const ErrnoMapperMock& orig) = default;
    //    ErrnoMapperMock(ErrnoMapperMock&& orig) = default;
    //    ErrnoMapperMock & operator=(const ErrnoMapperMock& orig) = default;
    //    ErrnoMapperMock & operator=(ErrnoMapperMock && orig) = default;
    virtual ~ErrnoMapperMock(); // = delete;

    MOCK_METHOD0(onWarning , void());
    MOCK_METHOD0(error , void());
    MOCK_METHOD0(fatalError , void());
    MOCK_METHOD0(criticalError , void());
    MOCK_METHOD0(alertError , void());
    MOCK_METHOD0(emergencyError , void());

private:

    log4cxx::LoggerPtr logger;
};

#endif

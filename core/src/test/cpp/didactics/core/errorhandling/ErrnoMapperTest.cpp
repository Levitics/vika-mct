
#include <didactics/core/errorhandling/ErrnoMapperTest.hpp>
// ErrnoMapperMock * ErrnoMapperTest::testObject = nullptr;

log4cxx::LoggerPtr ErrnoMapperTest::logger =
    log4cxx::Logger::getLogger(std::string("diactics.core.errorhandling.ErrnoMapperTest"));

ErrnoMapperTest::ErrnoMapperTest()
    : testObject(nullptr)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

ErrnoMapperTest::~ErrnoMapperTest() {
}

void ErrnoMapperTest::SetUp ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //    testObject = new ErrnoMapperMock();
}

void ErrnoMapperTest::TearDown ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //    delete testObject;
}

TEST_F(ErrnoMapperTest , testOnWarning)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(ErrnoMapperTest , testError)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(ErrnoMapperTest , testFatalError)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(ErrnoMapperTest , testCriticalError)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(ErrnoMapperTest , testAlertError)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(ErrnoMapperTest , testEmergencyError)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

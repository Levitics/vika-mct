
#include <didactics/core/errorhandling/ExceptionsTest.hpp>

log4cxx::LoggerPtr ExceptionsTest::logger =
    log4cxx::Logger::getLogger(std::string("diactics.core.errorhandling.ExceptionsTest"));

ExceptionsTest::ExceptionsTest() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

ExceptionsTest::~ExceptionsTest() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void ExceptionsTest::SetUp ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void ExceptionsTest::TearDown ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(ExceptionsTest , testStdExcep)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

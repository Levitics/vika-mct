
#include <didactics/core/errorhandling/BacktraceTest.hpp>
log4cxx::LoggerPtr BacktraceTest::logger =
    log4cxx::Logger::getLogger(std::string("diactics.core.errorhandling.BacktraceTest"));
BacktraceTest::BacktraceTest() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

BacktraceTest::~BacktraceTest() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void BacktraceTest::SetUp ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void BacktraceTest::TearDown ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(BacktraceTest , testCallStack)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

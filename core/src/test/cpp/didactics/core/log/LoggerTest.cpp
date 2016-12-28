
#include <didactics/core/log/LoggerTest.hpp>
#include <didactics/SuiteOfTest.hpp>
log4cxx::LoggerPtr LoggerTest::logger = log4cxx::Logger::getLogger(std::string("didactics.core.utils.LoggerTest"));
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(LoggerTest , ts::getTestSuiteName());
LoggerTest::LoggerTest()
    : threadedLogging(NULL)
    , hierarchy(NULL)
    , hierarchy2(NULL)
    , hierarchy3(NULL)
    , cxx2hierarchy(NULL)
    , cxx2hierarchy2(NULL)
    , cxx2hierarchy3(NULL)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

LoggerTest::LoggerTest(const LoggerTest& orig)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

LoggerTest::~LoggerTest()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void LoggerTest::setUp ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->threadedLogging = new cxx::ThreadedLogging();
    this->hierarchy = new cxx::Hierarchy();
    this->hierarchy2 = new cxx::Hierarchy2();
    this->hierarchy3 = new cxx::Hierarchy3();
    this->cxx2hierarchy = new cxx::cxx2::Hierarchy();
    this->cxx2hierarchy2 = new cxx::cxx2::Hierarchy2();
    this->cxx2hierarchy3 = new cxx::cxx2::Hierarchy3();

}

void LoggerTest::tearDown ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    delete this->threadedLogging;
    delete this->hierarchy;
    delete this->hierarchy2;
    delete this->hierarchy3;
    delete this->cxx2hierarchy;
    delete this->cxx2hierarchy2;
    delete this->cxx2hierarchy3;
}

void LoggerTest::dummy ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    CPPUNIT_ASSERT(true);
}

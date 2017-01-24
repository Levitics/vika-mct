
#include <didactics/core/log/LoggerTest.hpp>
#include <didactics/SuiteOfTest.hpp>

LoggerTest::LoggerTest()
    : threadedLogging(NULL)
    , hierarchy(NULL)
    , hierarchy2(NULL)
    , hierarchy3(NULL)
    , cxx2hierarchy(NULL)
    , cxx2hierarchy2(NULL)
    , cxx2hierarchy3(NULL)
    , logger(log4cxx::Logger::getLogger(std::string("didactics.core.utils.LoggerTest")))
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

LoggerTest::LoggerTest(const LoggerTest & orig)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

LoggerTest::~LoggerTest()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void LoggerTest::SetUp ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //    this->threadedLogging = new cxx::ThreadedLogging();
    this->hierarchy = new cxx::Hierarchy();
    this->hierarchy2 = new cxx::Hierarchy2();
    this->hierarchy3 = new cxx::Hierarchy3();
    this->cxx2hierarchy = new cxx::cxx2::Hierarchy();
    this->cxx2hierarchy2 = new cxx::cxx2::Hierarchy2();
    this->cxx2hierarchy3 = new cxx::cxx2::Hierarchy3();
}

void LoggerTest::TearDown ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //    delete this->threadedLogging;
    delete this->hierarchy;
    delete this->hierarchy2;
    delete this->hierarchy3;
    delete this->cxx2hierarchy;
    delete this->cxx2hierarchy2;
    delete this->cxx2hierarchy3;
}

TEST_F(LoggerTest , testTrace)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    EXPECT_TRUE(logger->isTraceEnabled());
    //    logger->setLevel(log4cxx::Level::FATAL_INT);
    //    EXPECT_FALSE(logger->isTraceEnabled());
    EXPECT_TRUE(logger->isDebugEnabled());
    EXPECT_TRUE(logger->isInfoEnabled());
    EXPECT_TRUE(logger->isWarnEnabled());
    EXPECT_TRUE(logger->isErrorEnabled());
    EXPECT_TRUE(logger->isFatalEnabled());
    EXPECT_TRUE(logger->getAdditivity());

    this->hierarchy->logme();
    this->hierarchy2->logme();
    this->hierarchy3->logme();
    this->cxx2hierarchy->logme();
    this->cxx2hierarchy2->logme();
    this->cxx2hierarchy3->logme();
}

TEST_F(LoggerTest , testDebug)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    EXPECT_TRUE(logger->isTraceEnabled());
    //    logger->setLevel(log4cxx::Level::FATAL_INT);
    //    EXPECT_FALSE(logger->isTraceEnabled());
    EXPECT_TRUE(logger->isDebugEnabled());
    EXPECT_TRUE(logger->isInfoEnabled());
    EXPECT_TRUE(logger->isWarnEnabled());
    EXPECT_TRUE(logger->isErrorEnabled());
    EXPECT_TRUE(logger->isFatalEnabled());
    EXPECT_TRUE(logger->getAdditivity());
}

TEST_F(LoggerTest , testInfo)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    EXPECT_TRUE(logger->isTraceEnabled());
    //    logger->setLevel(log4cxx::Level::FATAL_INT);
    //    EXPECT_FALSE(logger->isTraceEnabled());
    EXPECT_TRUE(logger->isDebugEnabled());
    EXPECT_TRUE(logger->isInfoEnabled());
    EXPECT_TRUE(logger->isWarnEnabled());
    EXPECT_TRUE(logger->isErrorEnabled());
    EXPECT_TRUE(logger->isFatalEnabled());
    EXPECT_TRUE(logger->getAdditivity());
}

TEST_F(LoggerTest , testWarn)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    EXPECT_TRUE(logger->isTraceEnabled());
    //    logger->setLevel(log4cxx::Level::FATAL_INT);
    //    EXPECT_FALSE(logger->isTraceEnabled());
    EXPECT_TRUE(logger->isDebugEnabled());
    EXPECT_TRUE(logger->isInfoEnabled());
    EXPECT_TRUE(logger->isWarnEnabled());
    EXPECT_TRUE(logger->isErrorEnabled());
    EXPECT_TRUE(logger->isFatalEnabled());
    EXPECT_TRUE(logger->getAdditivity());
}

TEST_F(LoggerTest , testError)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    EXPECT_TRUE(logger->isTraceEnabled());
    //    logger->setLevel(log4cxx::Level::FATAL_INT);
    //    EXPECT_FALSE(logger->isTraceEnabled());
    EXPECT_TRUE(logger->isDebugEnabled());
    EXPECT_TRUE(logger->isInfoEnabled());
    EXPECT_TRUE(logger->isWarnEnabled());
    EXPECT_TRUE(logger->isErrorEnabled());
    EXPECT_TRUE(logger->isFatalEnabled());
    EXPECT_TRUE(logger->getAdditivity());
}

TEST_F(LoggerTest , testFatal)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    EXPECT_TRUE(logger->isTraceEnabled());
    //    logger->setLevel(log4cxx::Level::FATAL_INT);
    //    EXPECT_FALSE(logger->isTraceEnabled());
    EXPECT_TRUE(logger->isDebugEnabled());
    EXPECT_TRUE(logger->isInfoEnabled());
    EXPECT_TRUE(logger->isWarnEnabled());
    EXPECT_TRUE(logger->isErrorEnabled());
    EXPECT_TRUE(logger->isFatalEnabled());
    EXPECT_TRUE(logger->getAdditivity());
}

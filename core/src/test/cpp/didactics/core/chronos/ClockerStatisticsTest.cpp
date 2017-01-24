
#include <didactics/core/chronos/ClockerStatisticsTest.hpp>

// ClockerStatistics * ClockerStatisticsTest::objectUnderTest = nullptr;
log4cxx::LoggerPtr ClockerStatisticsTest::logger =
    log4cxx::Logger::getLogger(std::string("didactics.core.utils.ClockerStatisticsTest"));

ClockerStatisticsTest::ClockerStatisticsTest()
    : first(nullptr)
    , second(nullptr)
    , objectUnderTest(nullptr)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

ClockerStatisticsTest::ClockerStatisticsTest(const ClockerStatisticsTest & orig) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

ClockerStatisticsTest::~ClockerStatisticsTest() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void ClockerStatisticsTest::SetUp ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //    first->assign(100 , 37.0);
    //    second->assign (first->begin() , first->end());
    //    objectUnderTest = new ClockerStatistics(first);
}

void ClockerStatisticsTest::TearDown ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //    delete this->first;
    //    delete this->second;
    //    delete this->objectUnderTest;
}

TEST_F(ClockerStatisticsTest , testCalculateSlidingMean)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //    objectUnderTest->calculateSlidingMean(14);
}

TEST_F(ClockerStatisticsTest , testCalculateStatistics)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //    this->objectUnderTest->calculateStatistics();
}

TEST_F(ClockerStatisticsTest , testGetFirstQuartile)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //    objectUnderTest->getFirstQuartile();
}

TEST_F(ClockerStatisticsTest , testGetThirdQuartile)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //    objectUnderTest->getThirdQuartile();
}

TEST_F(ClockerStatisticsTest , testGetMin)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //    objectUnderTest->getMin();
}

TEST_F(ClockerStatisticsTest , testGetMax)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //    objectUnderTest->getMax();
}

TEST_F(ClockerStatisticsTest , testGetMean)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //    objectUnderTest->getMean();
}

TEST_F(ClockerStatisticsTest , testGetMedian)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //    objectUnderTest->getMedian();
}

TEST_F(ClockerStatisticsTest , testGetStddev)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //    objectUnderTest->getStddev();
}

TEST_F(ClockerStatisticsTest , testGetVariance)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //    objectUnderTest->getVariance();
}

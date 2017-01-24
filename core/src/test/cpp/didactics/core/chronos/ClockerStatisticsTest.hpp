
#ifndef CLOCKERSTATISTICSTEST_HPP
#define CLOCKERSTATISTICSTEST_HPP
#include <gtest/gtest.h>
#include <didactics/core/chronos/ClockerStatistics.hpp>

class ClockerStatisticsTest  : public ::testing::Test
{
public:

    ClockerStatisticsTest();
    ClockerStatisticsTest(const ClockerStatisticsTest & orig);
    virtual ~ClockerStatisticsTest();
    /*!
     * @brief Test set up.
     */
    virtual void SetUp ();
    /*!
     * @brief Test tear down.
     */
    virtual void TearDown ();

protected:

    ClockerStatistics * objectUnderTest;
    /*!
     * @brief ClockerStatistics utility test class logger.
     */
    static log4cxx::LoggerPtr logger;

    std::list<double> * first;
    std::list<double> * second;

private:

};

#endif

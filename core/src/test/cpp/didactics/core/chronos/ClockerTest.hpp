
#ifndef CLOCKERTEST_HPP
#define CLOCKERTEST_HPP
#include <didactics/core/chronos/Clocker.hpp>
#include <gtest/gtest.h>

class ClockerTest  : public ::testing::Test
{

public:

    ClockerTest();
    ClockerTest(const ClockerTest & orig);
    virtual ~ClockerTest();
    /**
     * @brief Test set up.
     */
    virtual void SetUp ();
    /**
     * @brief Test tear down.
     */
    virtual void TearDown ();
    //    /*!
    //     * @brief Per-test-case set-up.
    //     */
    //    static void SetUpTestCase();
    //    /*!
    //     * @brief Per-test-case tear-down.
    //     */
    //    static void TearDownTestCase();

protected:

    /*!
     * @brief ClockerStatistics utility test class logger.
     */
    static log4cxx::LoggerPtr logger;

private:

    static Clocker * testObject;
    /*!
     * @brief ClockerStatistics utility test class logger.
     */
    //    log4cxx::LoggerPtr logger;
};

#endif

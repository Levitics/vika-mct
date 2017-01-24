
#ifndef HIGHRESOLUTIONTIMERTEST_HPP
#define HIGHRESOLUTIONTIMERTEST_HPP
#include <gtest/gtest.h>
#include <didactics/core/chronos/HighResolutionTimer.hpp>

class HighResolutionTimerTest  : public ::testing::Test
{
public:

    HighResolutionTimerTest();
    HighResolutionTimerTest(const HighResolutionTimerTest & orig);
    virtual ~HighResolutionTimerTest();
    /**
     * @brief Test set up.
     */
    virtual void SetUp ();
    /**
     * @brief Test tear down.
     */
    virtual void TearDown ();

protected:

private:

};

#endif

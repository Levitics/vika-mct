
#ifndef COLORSTDOUPUTLOGMSGTEST_HPP
#define COLORSTDOUPUTLOGMSGTEST_HPP
#include <gtest/gtest.h>
#include <didactics/core/log/ColorStdOuputLogMsg.hpp>
class ColorStdOuputLogMsgTest  : public ::testing::Test
{

public:

    ColorStdOuputLogMsgTest();
    ColorStdOuputLogMsgTest(const ColorStdOuputLogMsgTest & orig);
    virtual ~ColorStdOuputLogMsgTest();
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

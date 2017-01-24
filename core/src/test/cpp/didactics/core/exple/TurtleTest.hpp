
#ifndef TURTLETEST_HPP
#define TURTLETEST_HPP
#include <gtest/gtest.h>
#include <didactics/core/exple/MockTurtle.hpp>
#include <didactics/core/exple/FakeTurtle.hpp>
#include <didactics/core/exple/DelegateMockTurtle.hpp>

class TurtleTest : public ::testing::Test
{
public:

    TurtleTest();
    TurtleTest(const TurtleTest & orig);
    virtual ~TurtleTest();
    /*!
     * @brief Test set up.
     */
    virtual void SetUp ();
    /*!
     * @brief Test tear down.
     */
    virtual void TearDown ();

protected:

    MockTurtle * objectUnderTest;
    static log4cxx::LoggerPtr logger;

private:

    //
    //    MockTurtle * objectUnderTest;
    //    log4cxx::LoggerPtr logger;
};

#endif

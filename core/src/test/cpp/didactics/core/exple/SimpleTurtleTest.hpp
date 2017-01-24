
#ifndef SIMPLETURTLETEST_HPP
#define SIMPLETURTLETEST_HPP
#include <gtest/gtest.h>
#include <didactics/core/exple/FakeTurtle.hpp>

class SimpleTurtleTest : public ::testing::Test
{
public:

    SimpleTurtleTest();
    SimpleTurtleTest(const SimpleTurtleTest & orig);
    virtual ~SimpleTurtleTest();
    /*!
     * @brief Test set up.
     */
    virtual void SetUp ();
    /*!
     * @brief Test tear down.
     */
    virtual void TearDown ();

protected:

    static FakeTurtle * objectUnderTest;
    static log4cxx::LoggerPtr logger;

private:

};

#endif

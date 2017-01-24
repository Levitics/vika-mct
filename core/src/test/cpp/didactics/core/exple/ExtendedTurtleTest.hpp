
#ifndef EXTENDEDTURTLETEST_HPP
#define EXTENDEDTURTLETEST_HPP

#include <didactics/core/exple/DelegateMockTurtle.hpp>

class ExtendedTurtleTest : public ::testing::Test
{
public:

    ExtendedTurtleTest();
    ExtendedTurtleTest(const ExtendedTurtleTest & orig);
    virtual ~ExtendedTurtleTest();
    /*!
     * @brief Test set up.
     */
    virtual void SetUp ();
    /*!
     * @brief Test tear down.
     */
    virtual void TearDown ();

protected:

    static DelegateMockTurtle * objectUnderTest;
    static log4cxx::LoggerPtr logger;

private:

};

#endif

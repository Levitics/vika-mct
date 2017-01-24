
#ifndef EXCEPTIONSTEST_HPP
#define EXCEPTIONSTEST_HPP
#include <gtest/gtest.h>
#include <didactics/core/log/Logger.hpp>
#include <didactics/core/errorhandling/Exceptions.hpp>
class ExceptionsTest : public ::testing::Test
{
public:

    ExceptionsTest();
    virtual ~ExceptionsTest();

    /*!
     * @brief Test set up.
     */
    virtual void SetUp ();
    /*!
     * @brief Test tear down.
     */
    virtual void TearDown ();

protected:

    //    Exceptions * testObject ;
    static log4cxx::LoggerPtr logger;

private:

};

#endif

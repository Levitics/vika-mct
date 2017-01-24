
#ifndef RESOURCELIMITTEST_HPP
#define RESOURCELIMITTEST_HPP
#include <gtest/gtest.h>
#include <didactics/core/platform/linux/ResourceLimit.hpp>

class ResourceLimitTest : public ::testing::Test
{
public:

    ResourceLimitTest();
    ResourceLimitTest(const ResourceLimitTest & orig);
    virtual ~ResourceLimitTest();
    /*!
     * @brief Test set up.
     */
    virtual void SetUp ();
    /*!
     * @brief Test tear down.
     */
    virtual void TearDown ();

protected:

    ResourceLimit * objectUnderTest;
    static log4cxx::LoggerPtr logger;

private:

};

#endif

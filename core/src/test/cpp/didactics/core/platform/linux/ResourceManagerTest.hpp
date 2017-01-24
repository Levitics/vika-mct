
#ifndef RESOURCEMANAGERTEST_HPP
#define RESOURCEMANAGERTEST_HPP
#include <gtest/gtest.h>
#include <didactics/core/platform/linux/ResourceManager.hpp>

class ResourceManagerTest  : public ::testing::Test
{
public:

    ResourceManagerTest();
    ResourceManagerTest(const ResourceManagerTest & orig);
    virtual ~ResourceManagerTest();
    /*!
     * @brief Test set up.
     */
    virtual void SetUp ();
    /*!
     * @brief Test tear down.
     */
    virtual void TearDown ();

protected:

    ResourceManager * objectUnderTest;
    static log4cxx::LoggerPtr logger;

private:

};

#endif

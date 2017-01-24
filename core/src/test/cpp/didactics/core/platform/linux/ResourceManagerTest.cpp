
#include <limits>
#include <didactics/core/platform/linux/ResourceManagerTest.hpp>

log4cxx::LoggerPtr ResourceManagerTest::logger =
    log4cxx::Logger::getLogger(std::string("diactics.core.platform.linux.ResourceManagerTest"));

ResourceManagerTest::ResourceManagerTest()
    : objectUnderTest(NULL)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

ResourceManagerTest::ResourceManagerTest(const ResourceManagerTest & orig) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

ResourceManagerTest::~ResourceManagerTest() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void ResourceManagerTest::SetUp ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //    std::numeric_limits<double>::epsilon();
    // this->objectUnderTest = new ResourceManager();
}

void ResourceManagerTest::TearDown ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    delete objectUnderTest;
}

TEST_F(ResourceManagerTest , testResourceLimit)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

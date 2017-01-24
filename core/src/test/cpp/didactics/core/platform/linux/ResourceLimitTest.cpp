
#include <didactics/core/platform/linux/ResourceLimitTest.hpp>
log4cxx::LoggerPtr ResourceLimitTest::logger =
    log4cxx::Logger::getLogger(std::string("diactics.core.platform.linux.ResourceLimitTest"));

ResourceLimitTest::ResourceLimitTest()
    : objectUnderTest(nullptr)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

ResourceLimitTest::ResourceLimitTest(const ResourceLimitTest & orig) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

ResourceLimitTest::~ResourceLimitTest() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void ResourceLimitTest::SetUp ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->objectUnderTest = new ResourceLimit(RLIMIT_CPU , 3 , 3);
}

void ResourceLimitTest::TearDown ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    delete this->objectUnderTest;
}

TEST_F(ResourceLimitTest , testLimit)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    EXPECT_EQ( 3 , objectUnderTest->soft_limit() );
    EXPECT_EQ( 3 , objectUnderTest->hard_limit() );
}

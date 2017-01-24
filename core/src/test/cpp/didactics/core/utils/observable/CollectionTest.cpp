
#include <didactics/core/utils/observable/CollectionTest.hpp>

CollectionTest::CollectionTest()
{
}

CollectionTest::CollectionTest(const CollectionTest & orig) {
}

CollectionTest::~CollectionTest() {
}

void CollectionTest::SetUp ()
{

    // LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    // testObject = new Collection<int>();
    // std::is_nothrow_constructible<Collection<int>>::value;
}

void CollectionTest::TearDown ()
{
    // LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    delete testObject;
}

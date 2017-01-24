
#ifndef COLLECTIONTEST_HPP
#define COLLECTIONTEST_HPP
#include <array>
#include <atomic>
#include <type_traits>
#include <memory>
#include <thread>
#include <vector>
#include <unordered_set>
#include <gtest/gtest.h>
#include <didactics/core/utils/observable/Collection.hpp>


class CollectionTest : public ::testing::Test
{
public:

    CollectionTest();
    CollectionTest(const CollectionTest & orig);
    virtual ~CollectionTest();
    /*!
     * @brief Test set up.
     */
    virtual void SetUp ();
    /*!
     * @brief Test tear down.
     */
    virtual void TearDown ();

protected:

    Collection * testObject;

private:

};

#endif

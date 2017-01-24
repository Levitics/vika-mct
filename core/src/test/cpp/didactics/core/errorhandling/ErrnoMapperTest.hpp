
#ifndef ERRNOMAPPERTEST_HPP
#define ERRNOMAPPERTEST_HPP
#include <gtest/gtest.h>
#include <didactics/core/errorhandling/ErrnoMapperMock.hpp>

class ErrnoMapperTest  : public ::testing::Test
{
public:

    ErrnoMapperTest();
    //    ErrnoMapperTest(const ErrnoMapperTest& orig) = default;
    //    ErrnoMapperTest(ErrnoMapperTest&& orig) = default;
    //    ErrnoMapperTest & operator=(const ErrnoMapperTest& orig) = default;
    //    ErrnoMapperTest & operator=(ErrnoMapperTest && orig) = default;
    virtual ~ErrnoMapperTest(); // = default;

    /*!
     * @brief Test set up.
     */
    virtual void SetUp ();
    /*!
     * @brief Test tear down.
     */
    virtual void TearDown ();

protected:

    ErrnoMapperMock * testObject;
    static log4cxx::LoggerPtr logger;

private:

};

#endif

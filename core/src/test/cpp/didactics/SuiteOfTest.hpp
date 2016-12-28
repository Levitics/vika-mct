
#ifndef SUITEOFTEST_HPP
#define SUITEOFTEST_HPP
#include <cppunit/Portability.h>
#include <string>

namespace ts
{
    /*!
     * @brief Get test suite name.
     * @return Test suite name.
     */

    const std::string &getTestSuiteName ()
    {
        static const std::string testSuiteName = PROJECT_ARTIFACTID;
        return testSuiteName;
    }
}

#endif

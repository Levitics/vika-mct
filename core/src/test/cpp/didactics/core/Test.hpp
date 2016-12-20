#ifndef DIDACTIC_CORE_TEST_HPP
#define DIDACTIC_CORE_TEST_HPP
#include <string>
#include <didactics/Test.hpp>
//#include <didactics/SuiteOfTest.hpp>

namespace didactics
{
    namespace core
    {
        namespace test
        {
            extern const std::string & runThisTestSuiteName();
            /*!
             * @brief Execute tests.
             * @return The total number of test failures and errors.
             */
            extern int execute(int argc, char *argv[]);
            /*!
             * @brief Namespace logger.
             */            
            extern log4cxx::LoggerPtr logger;
        }
    }
}

#endif


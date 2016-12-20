#ifndef DIDACTIC_TEST_HPP
#define DIDACTIC_TEST_HPP

#include <didactics/core/log/Logger.hpp>

namespace didactics
{
    namespace test
    {
        /*!
         * @brief Run tests.
         * @param suite Test registration suite name.
         * @return The total number of test failures and errors.
         */
        extern int run(int argc, char *argv[],const char * const suite);
        /*!
         * @brief Run tests.
         * @param suite Test registration suite name.
         * @return The total number of test failures and errors.
         */
        extern int launch(const std::string & suite,int argc = 0, char **argv = NULL);
        /*!
         * @brief Execute tests.
         * @param suite Test suite name.
         * @return The total number of test failures and errors.
         */
        extern int execute(const char * const suite,int argc, char *argv[]);
        /*!
         * @brief Namespace logger name.
         */        
        extern log4cxx::LoggerPtr logger;
    }
}
#endif


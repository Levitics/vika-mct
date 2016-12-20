#include <didactics/core/Test.hpp>

log4cxx::LoggerPtr didactics::core::test::logger = log4cxx::Logger::getLogger(std::string("didactics.core.test"));            
            
const std::string & didactics::core::test::runThisTestSuiteName()
{
    static const std::string testSuiteName = PROJECT_ARTIFACTID;
    return testSuiteName;    
}

int 
didactics::core::test::execute(int argc, char *argv[])
{
    LOG4CXX_TRACE(didactics::core::test::logger, runThisTestSuiteName() << " " <<__LOG4CXX_FUNC__);
    //return didactics::test::execute(ts::getTestSuiteName().c_str(),argc,argv);
    return didactics::test::execute(runThisTestSuiteName().c_str(),argc,argv);
    //return 0;
}

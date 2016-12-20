#include <cppunit/XmlOutputter.h>
//#include <didactics/XmlOutputterHook.hpp>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TextTestRunner.h>
#include <gmock/gmock.h>
//#include <didactics/SuiteOfTest.hpp>
#include <didactics/Test.hpp>

log4cxx::LoggerPtr didactics::test::logger = log4cxx::Logger::getLogger(std::string("didactics.test"));

int didactics::test::run(int argc, char *argv[],const char * const suite)
{
    std::string testPath = (argc > 1) ? std::string(argv[1]) : std::string("");
    CPPUNIT_NS::TestResult controller;
    
    CPPUNIT_NS::TestResultCollector result;
    controller.addListener( &result );
    
    CPPUNIT_NS::BriefTestProgressListener progress;
    controller.addListener( &progress );
    
    CPPUNIT_NS::TestRunner runner;
    runner.addTest( CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest() );
    try
    {
        //CPPUNIT_NS::stdCOut() << "Running "  <<  testPath;
        runner.run( controller, testPath );
       // CPPUNIT_NS::stdCOut() << "\n";

        // Print test in a compiler compatible format.
        CPPUNIT_NS::CompilerOutputter outputter( &result, CPPUNIT_NS::stdCOut() );
        outputter.write(); 

    // Uncomment this for XML output
    //    std::ofstream file( "tests.xml" );
    //    CPPUNIT_NS::XmlOutputter xml( &result, file );
    //    xml.setStyleSheet( "report.xsl" );
    //    xml.write();
    //    file.close();
    }
    catch ( std::invalid_argument &e )  // Test path not resolved
    {
        CPPUNIT_NS::stdCOut()  <<  "\n"  
                                <<  "ERROR: "  <<  e.what()
                                << "\n";
        return 0;
    }
    return result.wasSuccessful() ? 0 : 1;    
}

int 
didactics::test::launch(const std::string & suite ,int argc, char *argv[])
{
    LOG4CXX_TRACE(didactics::test::logger,"launch " <<suite <<" " <<__LOG4CXX_FUNC__);    

    
    // The following line causes Google Mock to throw an exception on failure,
    // which will be interpreted by your testing framework as a test failure.

    ::testing::GTEST_FLAG(throw_on_failure) = true;
    ::testing::FLAGS_gmock_verbose = "verbose";
    
    try
    {
        LOG4CXX_TRACE(didactics::test::logger,"Innitializing google mock");
        ::testing::InitGoogleMock(&argc, argv);     
    }
    catch (std::exception& e) 
    {
        LOG4CXX_ERROR(didactics::test::logger, "Issues while innitializing google mock"  << typeid (e).name () << ": " << e.what () );
    }    
    catch(...)
    {
        LOG4CXX_FATAL(didactics::test::logger,"Unhandled exception");
    }
    LOG4CXX_TRACE(didactics::test::logger,">>>>>>>>!!!!Star running unit test!!!!>>>>>>>>");

    CPPUNIT_NS::TextTestRunner runner;
    runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry(suite).makeTest());
    runner.run();

    std::ofstream xmlFile("cppunit-test-result2.xml");
    CPPUNIT_NS::XmlOutputter xmlOutputter(&(runner.result()), xmlFile);
    //XmlOutputterHook hook;
    //xmlOutputter.addHook(&hook);
    //xmlOutputter.write();
    //xmlFile.close();

    LOG4CXX_TRACE(didactics::test::logger,"<<<<<<<<!!!!Unit test ended!!!!<<<<<<<<");
    return (runner.result().testFailuresTotal()); 
}
 
int 
didactics::test::execute(const char * const suite,int argc, char *argv[])
{
    LOG4CXX_TRACE(didactics::test::logger,__LOG4CXX_FUNC__ );
    //std::string testname(ts::getTestSuiteName());
    std::string testname(suite);
    const std::string name = !testname.empty() ? testname : "AllTests";
    LOG4CXX_TRACE(didactics::test::logger, __LOG4CXX_FUNC__ << " " << name);
    return didactics::test::launch(name,argc,argv);
}


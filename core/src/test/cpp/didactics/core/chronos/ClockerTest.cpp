
#include <didactics/core/chronos/ClockerTest.hpp>
#include <didactics/core/Test.hpp>

Clocker * ClockerTest::testObject = nullptr;
log4cxx::LoggerPtr ClockerTest::logger = log4cxx::Logger::getLogger(std::string("didactics.core.utils.ClockerTest"));

ClockerTest::ClockerTest()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

ClockerTest::ClockerTest(const ClockerTest & orig) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

ClockerTest::~ClockerTest() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void ClockerTest::SetUp ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    testObject = new Clocker();
}

void ClockerTest::TearDown ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    delete testObject;
}

// void ClockerTest::SetUpTestCase()
// {
//    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
//        testObject = new Clocker();
// }
// void ClockerTest::TearDownTestCase()
// {
//    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
//    delete testObject;
// }
//
TEST_F(ClockerTest , testStart)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(ClockerTest , testStop)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(ClockerTest , testReset)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(ClockerTest , testIsRunning)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(ClockerTest , testIsReset)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(ClockerTest , testGetTime)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(ClockerTest , testGetTimeInSeconds)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(ClockerTest , testGetTimeInMilliSeconds)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(ClockerTest , testGetTimeInMicroSeconds)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

}

TEST_F(ClockerTest , testGetTimeInNanoSeconds)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

TEST_F(ClockerTest , testGetFrequency)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

/*
   void ClockerTest::testStart ()
   {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->testObject->start();
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Time is not runing"
                                , true
                                , this->testObject->isRunning()
                                 );

    CPPUNIT_ASSERT_EQUAL_MESSAGE("Time should be running"
                                , false
                                , this->testObject->isReset()
                                 );
   }

   void ClockerTest::testStop ()
   {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->testObject->stop();
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Time should be stopped"
                                , false
                                , this->testObject->isRunning()
                                 );

    CPPUNIT_ASSERT_EQUAL_MESSAGE("Time should be reset"
                                , true
                                , this->testObject->isReset()
                                 );
   }

   void ClockerTest::testReset ()
   {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->testObject->reset();
   }

   void ClockerTest::testIsRunning ()
   {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->testObject->isRunning();
   }

   void ClockerTest::testIsReset ()
   {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->testObject->isReset();
   }

   void ClockerTest::testGetTime ()
   {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->testObject->getTime();
   }

   void ClockerTest::testGetTimeInSeconds ()
   {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->testObject->getTimeInSeconds();
   }

   void ClockerTest::testGetTimeInMilliSeconds ()
   {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->testObject->getTimeInMilliSeconds();
   }

   void ClockerTest::testGetTimeInMicroSeconds ()
   {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->testObject->getTimeInMicroSeconds();
   }

   void ClockerTest::testGetTimeInNanoSeconds ()
   {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->testObject->getTimeInNanoSeconds();
   }

   void ClockerTest::testGetFrequency ()
   {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->testObject->getFrequency();
   }

 */

#ifndef COLORSTDOUPUTLOGMSGTEST_HPP
#define COLORSTDOUPUTLOGMSGTEST_HPP
#include <didactics/Test.hpp>
class ColorStdOuputLogMsgTest  : public CppUnit::TestFixture{
    CPPUNIT_TEST_SUITE(ColorStdOuputLogMsgTest);
    CPPUNIT_TEST(dummy);
    CPPUNIT_TEST_SUITE_END();     
public:
    ColorStdOuputLogMsgTest();
    ColorStdOuputLogMsgTest(const ColorStdOuputLogMsgTest& orig);
    virtual ~ColorStdOuputLogMsgTest();
    /**
     * @brief Test set up.
     */
    void setUp();
    /**
     * @brief Test tear down.
     */
    void tearDown();
protected:
    void dummy();    
private:

};

#endif


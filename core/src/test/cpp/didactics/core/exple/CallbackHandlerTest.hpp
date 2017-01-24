
#ifndef CALLBACKHANDLERTEST_HPP
#define CALLBACKHANDLERTEST_HPP
#include <didactics/core/exple/CallbackHandler.hpp>

class ATestClass
{
public:

    ATestClass()  = default;
    virtual ~ATestClass() = default;
    int mathod (int);
};

class CallbackHandlerTest
{

public:

    CallbackHandlerTest();
    virtual ~CallbackHandlerTest();

protected:

    //    CallbackHandler<ATestClass,int,int>callbackhandler1;

private:

};

#endif

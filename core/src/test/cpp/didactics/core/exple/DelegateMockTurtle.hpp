#ifndef DELEGATEMOCKTURTLE_HPP
#define DELEGATEMOCKTURTLE_HPP
#include <gmock/gmock.h>
#include <didactics/core/exple/Turtle.hpp>
#include <didactics/core/exple/FakeTurtle.hpp>

using ::testing::_;
using ::testing::AtLeast;
using ::testing::Gt;
using ::testing::NotNull;
using ::testing::InvokeWithoutArgs;
using ::testing::AnyNumber;
using ::testing::Return; 
using ::testing::Invoke;
using ::testing::NiceMock;
using ::testing::ReturnRef;
using ::testing::SaveArg;
using ::testing::InSequence;

class DelegateMockTurtle : public Turtle {
public:
    MOCK_METHOD0(PenUp, void());
    MOCK_METHOD0(PenDown, void());
    MOCK_METHOD1(Forward, void(int distance));
    MOCK_METHOD1(Turn, void(int degrees));
    MOCK_METHOD2(GoTo, void(int x, int y));
    MOCK_CONST_METHOD0(GetX, int());
    MOCK_CONST_METHOD0(GetY, int());     
    MOCK_CONST_METHOD0(name, std::string ());
    DelegateMockTurtle();
    DelegateMockTurtle(const DelegateMockTurtle& orig);
    virtual ~DelegateMockTurtle();
    void DelegateToFake();
    
private:
    FakeTurtle turtleNinja;
    log4cxx::LoggerPtr logger;
};

#endif


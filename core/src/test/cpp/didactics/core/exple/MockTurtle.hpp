#ifndef MOCKTURTLE_HPP
#define MOCKTURTLE_HPP
#include <gmock/gmock.h>
#include <didactics/core/exple/Turtle.hpp>

class MockTurtle : public Turtle{
public:
    MockTurtle();
    MockTurtle(const MockTurtle& orig);
    virtual ~MockTurtle();

    MOCK_METHOD0(PenUp, void());
    MOCK_METHOD0(PenDown, void());
    MOCK_METHOD1(Forward, void(int distance));
    MOCK_METHOD1(Turn, void(int degrees));
    MOCK_METHOD2(GoTo, void(int x, int y));
    MOCK_CONST_METHOD0(GetX, int());
    MOCK_CONST_METHOD0(GetY, int());
    //MOCK_CONST_METHOD0( name(), std::string () );
private:
    log4cxx::LoggerPtr logger;
};

#endif


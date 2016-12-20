
#ifndef FAKETURTLE_HPP
#define FAKETURTLE_HPP
#include <didactics/core/exple/Turtle.hpp>
class FakeTurtle : public Turtle {
public:
    FakeTurtle();
    FakeTurtle(const FakeTurtle& orig);
    virtual ~FakeTurtle();

    virtual void PenUp();
    virtual void PenDown();
    virtual void Forward(int distance);
    virtual void Turn(int degrees);
    virtual void GoTo(int x, int y);
    virtual int GetX() const;
    virtual int GetY() const;
    virtual std::string name() const;
private:
    log4cxx::LoggerPtr logger;
};

#endif


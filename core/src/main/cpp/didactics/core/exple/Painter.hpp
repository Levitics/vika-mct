
#ifndef PAINTER_HPP
#define PAINTER_HPP
#include <didactics/core/exple/Turtle.hpp>
class Painter
{
public:

    Painter();
    Painter(Turtle * turtle);
    Painter(const Painter & orig);
    virtual ~Painter();
    bool DrawCircle (int x , int y , int r);

private:

    Turtle * turtle;
    log4cxx::LoggerPtr logger;
};

#endif

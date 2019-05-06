#ifndef CLOCK_HPP
#define CLOCK_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Clock
{
public:
    Clock();
    void do_time(Window const& win);

private:
    Color second_clr;
    Vec2 center_;
    Vec2 minutes_;
    Vec2 hours_;
};

#endif
#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Circle
{
public:
    Circle();
    Circle(Vec2 const& center, int radius_, Color const& color);
    float circumference();
    void draw(Window const& win, int step);
    void draw(Window const& win, int step, bool isHighlight);
    void is_inside(Window const& win, Vec2 const& point);

private:
    Color color_;
    Color highlightColor_ = {0.3, 0.4, 0.1};
    Vec2 center_;
    int radius_;
};

#endif
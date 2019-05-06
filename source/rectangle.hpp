#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Rectangle
{
public:
    Rectangle();
    Rectangle(Vec2 const& min, Vec2 const& max, Color const& color);
    float circumference();
    void draw(Window const& window);
    void draw(Window const& window, int thickness);
    void is_inside(Window const& window, Vec2 const& point);

private:
    Color color_;
    Vec2 min_;
    Vec2 max_;
};

#endif
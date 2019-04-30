#include "rectangle.hpp"

Rectangle::Rectangle()
{
    Vec2 min_ = {0.0f, 0.0f};
    Vec2 max_ = {1.0f, 1.0f};
}

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max)
{
    min_ = min;
    max_ = max;
}

float Rectangle::circumference()
{
    float a = max_.x - min_.x;
    float b = max_.y - min_.y;

    float umfang = (2 * a) + (2 * b);
    return umfang;
}
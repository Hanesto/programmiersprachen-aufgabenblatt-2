#include "vec2.hpp"

class Rectangle
{
public:
    Rectangle();
    Rectangle(Vec2 const& min, Vec2 const& max);
    float circumference();

private:
    Vec2 min_;
    Vec2 max_;
};
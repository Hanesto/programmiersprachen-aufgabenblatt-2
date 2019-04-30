#include "vec2.hpp"

class Circle
{
public:
    Circle();
    Circle(Vec2 const& center, int radius_);
    float circumference();

private:
    Vec2 center_;
    int radius_;
};
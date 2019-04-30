#include "circle.hpp"
#include <math.h>

Circle::Circle()
{
    center_ = {0, 0};
    radius_ = 1;
}

Circle::Circle(Vec2 const& center, int radius)
{
    center_ = center;
    radius_ = radius;
}

float Circle::circumference()
{
    float umfang;
    umfang = 2 * M_PI * radius_;
    return umfang;
}
    

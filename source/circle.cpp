#include "circle.hpp"
#include <math.h>

Circle::Circle()
{
    center_ = {0, 0};
    radius_ = 1;
}

Circle::Circle(Vec2 const& center, int radius, Color const& color)
{
    color_ = color;
    center_ = center;
    radius_ = radius;
}

float Circle::circumference()
{
    float umfang;
    umfang = 2 * M_PI * radius_;
    return umfang;
}
    
void Circle::draw(Window const& win, int step)
{
    int theta = 0;
    Vec2 point;

    while(theta <= 360){
    
     int x = center_.x + radius_ * cos(theta);
     int y = center_.y + radius_ * sin(theta);

     win.draw_point(x, y, color_.r, color_.g, color_.b);

     //win.draw_line(point.x, point.y, x, y, color_.r, color_.g, color_.b);

     point.x = x;
     point.y = y;

     theta += step;
    }
}

void Circle::draw(Window const& win, int step, bool isHighlight)
{
    int theta = 0;
    Vec2 point;

    while(theta <= 360){
    
        int x = center_.x + radius_ * cos(theta);
        int y = center_.y + radius_ * sin(theta);

        if (isHighlight) {
            win.draw_point(x, y, highlightColor_.r, highlightColor_.g, highlightColor_.b);
        }
        
        else
        {
            win.draw_point(x, y, color_.r, color_.g, color_.b);
        }

        //win.draw_line(point.x, point.y, x, y, color_.r, color_.g, color_.b);

        point.x = x;
        point.y = y;

        theta += step;
    }
}
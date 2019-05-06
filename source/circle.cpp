#include "circle.hpp"
#include <math.h>

using namespace std;

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
    
     int x = center_.x + radius_ * std::cos(theta);
     int y = center_.y + radius_ * std::sin(theta);

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
    
        int x = center_.x + radius_ * std::cos(theta);
        int y = center_.y + radius_ * std::sin(theta);

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

void Circle::is_inside(Window const& win, Vec2 const& point)
{
    Vec2 mouse;
    auto mouse_position = win.mouse_position();
    mouse.x = mouse_position.first;
    mouse.y = mouse_position.second;

    int d = std::sqrt(pow(point.x - center_.x, 2) + pow(point.y - center_.y, 2));
    int d_mouse = std::sqrt(pow(mouse.x - center_.x, 2) + pow(mouse.y - center_.y, 2));

    Color notInside = {0.8, 0.1, 0.1};
    Color isInside = {0.2, 0.7, 0.4};

    if(d < radius_)
    {
      win.draw_point(point.x, point.y, isInside.r, isInside.g, isInside.b);
    }
    else
    {
        win.draw_point(point.x, point.y, notInside.r, notInside.g, notInside.b);
    }

    if(d_mouse < radius_)
    {
        draw(win, 1, true);
    }
}
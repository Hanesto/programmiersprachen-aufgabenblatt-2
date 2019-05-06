#include "rectangle.hpp"

Rectangle::Rectangle()
{
    Vec2 min_ = {0.0f, 0.0f};
    Vec2 max_ = {1.0f, 1.0f};
}

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& color)
{
    color_ = color;
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

//Überladen bedeutet, mehere Funktionen mit dem gleichen Namen, aber verschiedenen Eingabe
//Parametern zu erstellen, sodass die Eingabeparameter bestimmen, welche Funktion ausgeführt wird
void Rectangle::draw(Window const& win)
{
    win.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.g, color_.b);
    win.draw_line(min_.x, min_.y, min_.x, max_.y, color_.r, color_.g, color_.b);
    win.draw_line(max_.x, max_.y, max_.x, min_.y, color_.r, color_.g, color_.b);
    win.draw_line(max_.x, max_.y, min_.x, max_.y, color_.r, color_.g, color_.b);
}

void Rectangle::draw(Window const& win, int thickness)
{
    win.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.g, color_.b, thickness);
    win.draw_line(min_.x, min_.y, min_.x, max_.y, color_.r, color_.g, color_.b, thickness);
    win.draw_line(max_.x, max_.y, max_.x, min_.y, color_.r, color_.g, color_.b, thickness);
    win.draw_line(max_.x, max_.y, min_.x, max_.y, color_.r, color_.g, color_.b, thickness);
}

void Rectangle::is_inside(Window const& win, Vec2 const& point)
{
    Vec2 mouse;
    auto mouse_position = win.mouse_position();
    mouse.x = mouse_position.first;
    mouse.y = mouse_position.second;

    Color notInside = {0.8, 0.1, 0.1};
    Color isInside = {0.2, 0.7, 0.4};

    if(point.x > min_.x && point.x > min_.y && point.y < max_.y)
    {
        win.draw_point(point.x, point.y, isInside.r, isInside.g, isInside.b);
    }
    else
    {
        win.draw_point(point.x, point.y, notInside.r, notInside.g, notInside.b);
    }

    if(mouse.x > min_.x && mouse.y > min_.y && mouse.x < max_.x && mouse.y < max_.y)
    {
        draw(win, 4);
    }
    
}
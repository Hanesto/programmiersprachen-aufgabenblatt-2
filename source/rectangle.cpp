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
void Rectangle::draw(Window const& window)
{
    window.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.g, color_.b);
    window.draw_line(min_.x, min_.y, min_.x, max_.y, color_.r, color_.g, color_.b);
    window.draw_line(max_.x, max_.y, max_.x, min_.y, color_.r, color_.g, color_.b);
    window.draw_line(max_.x, max_.y, min_.x, max_.y, color_.r, color_.g, color_.b);
}

void Rectangle::draw(Window const& window, int thickness)
{
    window.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.g, color_.b, thickness);
    window.draw_line(min_.x, min_.y, min_.x, max_.y, color_.r, color_.g, color_.b, thickness);
    window.draw_line(max_.x, max_.y, max_.x, min_.y, color_.r, color_.g, color_.b, thickness);
    window.draw_line(max_.x, max_.y, min_.x, max_.y, color_.r, color_.g, color_.b, thickness);
}
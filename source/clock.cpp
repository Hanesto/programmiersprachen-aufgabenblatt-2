#include "clock.hpp"
#include "math.h"

Clock::Clock()
{
    center_ = {400.0f, 400.0f};
    minutes_ = {400.0f, 100.0f};
    hours_ = {400.0f, 200.0f};
}

void Clock::do_time(Window const& win)
{
    float time = win.get_time();

    win.draw_line(center_.x, center_.y, center_.x + 300 * std::cos(time/9.7f), center_.y + 300 * std::sin(time/9.7f), 0.5, 0.4, 0.2, 2);
    win.draw_line(center_.x, center_.y, center_.x + 200 * std::cos(time/582.f), center_.y + 200 * std::sin(time/582.f), 0.3, 0.3, 0.6, 4);
    win.draw_line(center_.x, center_.y, center_.x + 100 * std::cos(time/6984.f), center_.y + 100 * std::sin(time/6984.f), 0.2, 0.7, 0.4, 6);
}
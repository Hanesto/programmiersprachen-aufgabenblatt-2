#include "window.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "clock.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "math.h"

int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    Vec2 min_ = {50.0f, 60.0f};
    Vec2 max_ = {200.0f, 300.0f};
    Vec2 min2_ = {300.0f, 400.0f};
    Vec2 max2_ = {600.0f, 500.0f};

    Color rectColor;
    Color circColor = {0.2, 0.3, 0.6};

    Rectangle rect(min_, max_, rectColor);
    Rectangle rect2(min2_, max2_, rectColor);
    Circle circ(max_, 100, circColor);
    Circle circ2(min2_, 100, circColor);
    
    rect.draw(win);
    rect2.draw(win, 4);
    circ.draw(win, 1);
    circ2.draw(win, 1, true);

    Vec2 point = {70, 150};
    Vec2 point2 = {20, 150};
    Vec2 point3 = {250, 250};
    Vec2 point4 = {250, 200};

    rect.is_inside(win, point);
    rect.is_inside(win, point2);
    circ.is_inside(win, point3);
    circ.is_inside(win, point4);

    Clock grandfatherClock;
    grandfatherClock.do_time(win);

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1 = 400.f + 380.f * std::sin(t);
    float y1 = 400.f + 380.f * std::cos(t);

    float x2 = 400.f + 380.f * std::sin(2.0f*t);
    float y2 = 400.f + 380.f * std::cos(2.0f*t);

    float x3 = 400.f + 380.f * std::sin(t-10.f);
    float y3 = 400.f + 380.f * std::cos(t-10.f);

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto mouse_position = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                    mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                    1.0,0.0,0.0, // color with r,g,b in [0.0, 1.0]
                    1.0);        // line thickness = 1.0 * default thickness
    }

    win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second, mouse_position.second, 0.0, 0.0, 0.0);

    win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " + std::to_string(mouse_position.second) + ")";
    
    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);

    win.update();
  }

  return 0;
}

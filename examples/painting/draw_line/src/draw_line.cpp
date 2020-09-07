#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("draw_line");
      client_size({300, 300});

      paint += [&](control& sender, paint_event_args& e) {
        auto pen_solid = pen(color::red, 5);
        e.graphics().draw_line(pen_solid, 10, 10, 280, 10);

        auto pen_dot = pen(color::green, 5);
        pen_dot.dash_style(xtd::drawing::dash_style::dot);
        e.graphics().draw_line(pen_dot, 10, 25, 280, 25);

        auto pen_dash = pen(color::blue, 5);
        pen_dash.dash_style(xtd::drawing::dash_style::dash);
        e.graphics().draw_line(pen_dash, 10, 40, 280, 40);

        auto pen_dash_dot = pen(color::yellow, 5);
        pen_dash_dot.dash_style(xtd::drawing::dash_style::dash_dot);
        e.graphics().draw_line(pen_dash_dot, 10, 55, 280, 55);

        auto pen_dash_dot_dot = pen(color::cyan, 5);
        pen_dash_dot_dot.dash_style(xtd::drawing::dash_style::dash_dot_dot);
        e.graphics().draw_line(pen_dash_dot_dot, 10, 70, 280, 70);

        auto pen_custom = pen(color::magenta, 5);
        pen_custom.dash_style(xtd::drawing::dash_style::custom);
        pen_custom.dash_pattern({4, 1, 2, 1});
        e.graphics().draw_line(pen_custom, 10, 85, 280, 85);
      };
    }
  };
}

int main() {
  application::run(examples::form1());
}

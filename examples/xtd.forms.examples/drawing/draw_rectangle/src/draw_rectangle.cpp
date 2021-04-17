#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Draw line example");
      client_size({340, 230});
    }
    
    void on_paint(paint_event_args& e) override {
      auto pen_solid = pen(color::red, 5);
      e.graphics().draw_rectangle(pen_solid, 10, 10, 100, 100);
      
      auto pen_dot = pen(color::green, 5);
      pen_dot.dash_style(xtd::drawing::dash_style::dot);
      e.graphics().draw_rectangle(pen_dot, 120, 10, 100, 100);
      
      auto pen_dash = pen(color::blue, 5);
      pen_dash.dash_style(xtd::drawing::dash_style::dash);
      e.graphics().draw_rectangle(pen_dash, 230, 10, 100, 100);
      
      auto pen_dash_dot = pen(color::yellow, 5);
      pen_dash_dot.dash_style(xtd::drawing::dash_style::dash_dot);
      e.graphics().draw_rectangle(pen_dash_dot, 10, 120, 100, 100);
      
      auto pen_dash_dot_dot = pen(color::cyan, 5);
      pen_dash_dot_dot.dash_style(xtd::drawing::dash_style::dash_dot_dot);
      e.graphics().draw_rectangle(pen_dash_dot_dot, 120, 120, 100, 100);
      
      auto pen_custom = pen(color::magenta, 5);
      pen_custom.dash_style(xtd::drawing::dash_style::custom);
      pen_custom.dash_pattern({4, 1, 3, 2});
      e.graphics().draw_rectangle(pen_custom, 230, 120, 100, 100);
      
      form::on_paint(e);
    }
  };
}

int main() {
  application::run(examples::form1());
}

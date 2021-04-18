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
      auto solid_pen = pen(color::red, 5);
      e.graphics().draw_rectangle(solid_pen, 10, 10, 100, 100);
      
      auto dot_pen = pen(color::green, 5);
      dot_pen.dash_style(xtd::drawing::dash_style::dot);
      e.graphics().draw_rectangle(dot_pen, 120, 10, 100, 100);
      
      auto dash_pen = pen(color::blue, 5);
      dash_pen.dash_style(xtd::drawing::dash_style::dash);
      e.graphics().draw_rectangle(dash_pen, 230, 10, 100, 100);
      
      auto dash_dot_pen = pen(color::yellow, 5);
      dash_dot_pen.dash_style(xtd::drawing::dash_style::dash_dot);
      e.graphics().draw_rectangle(dash_dot_pen, 10, 120, 100, 100);
      
      auto dash_dot_dot_pen = pen(color::cyan, 5);
      dash_dot_dot_pen.dash_style(xtd::drawing::dash_style::dash_dot_dot);
      e.graphics().draw_rectangle(dash_dot_dot_pen, 120, 120, 100, 100);
      
      auto custom_pen = pen(color::magenta, 5);
      custom_pen.dash_style(xtd::drawing::dash_style::custom);
      custom_pen.dash_pattern({4, 1, 3, 2});
      e.graphics().draw_rectangle(custom_pen, 230, 120, 100, 100);
      
      form::on_paint(e);
    }
  };
}

int main() {
  application::run(examples::form1());
}

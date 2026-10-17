#include <xtd/xtd>

namespace draw_rounded_rectangle_example {
  class form1 : public form {
  public:
    form1() {
      text("Draw rounded rectangle example");
      client_size({340, 230});
    }
    
  protected:
    void on_paint(paint_event_args& e) override {
      form::on_paint(e);
      
      e.graphics().draw_rounded_rectangle(pen {color::red, 5.0f}, 10.0f, 10.0f, 100.0f, 100.0f, 10.0f);
      
      auto dot_pen = pen {color::green, 5.0f};
      dot_pen.dash_style(drawing_2d::dash_style::dot);
      e.graphics().draw_rounded_rectangle(dot_pen, 120.0f, 10.0f, 100.0f, 100.0f, 10.0f);
      
      auto dash_pen = pen {color::blue, 5.0f};
      dash_pen.dash_style(drawing_2d::dash_style::dash);
      e.graphics().draw_rounded_rectangle(dash_pen, 230.0f, 10.0f, 100.0f, 100.0f, 10.0f);
      
      auto dash_dot_pen = pen {color::yellow, 5.0f};
      dash_dot_pen.dash_style(drawing_2d::dash_style::dash_dot);
      e.graphics().draw_rounded_rectangle(dash_dot_pen, 10.0f, 120.0f, 100.0f, 100.0f, 10.0f);
      
      auto dash_dot_dot_pen = pen {color::cyan, 5.0f};
      dash_dot_dot_pen.dash_style(drawing_2d::dash_style::dash_dot_dot);
      e.graphics().draw_rounded_rectangle(dash_dot_dot_pen, 120.0f, 120.0f, 100.0f, 100.0f, 10.0f);
      
      auto custom_pen = pen {color::magenta, 5.0f};
      custom_pen.dash_style(drawing_2d::dash_style::custom);
      custom_pen.dash_pattern({4.0f, 1.0f, 3.0f, 2.0f});
      e.graphics().draw_rounded_rectangle(custom_pen, 230.0f, 120.0f, 100.0f, 100.0f, 10.0f);
    }
  };
}

auto main() -> int {
  application::run(draw_rounded_rectangle_example::form1 {});
}

#include <xtd/xtd>

namespace draw_ellipe_example {
  class form1 : public form {
  public:
    form1() {
      text("Draw ellipse example");
      client_size({340, 230});
    }
    
  protected:
    void on_paint(paint_event_args& e) override {
      form::on_paint(e);
      
      e.graphics().draw_ellipse(pen {color::red, 5}, 10, 10, 100, 100);
      
      auto dot_pen = pen {color::green, 5};
      dot_pen.dash_style(drawing_2d::dash_style::dot);
      e.graphics().draw_ellipse(dot_pen, 120, 10, 100, 100);
      
      auto dash_pen = pen {color::blue, 5};
      dash_pen.dash_style(drawing_2d::dash_style::dash);
      e.graphics().draw_ellipse(dash_pen, 230, 10, 100, 100);
      
      auto dash_dot_pen = pen {color::yellow, 5};
      dash_dot_pen.dash_style(drawing_2d::dash_style::dash_dot);
      e.graphics().draw_ellipse(dash_dot_pen, 10, 120, 100, 100);
      
      auto dash_dot_dot_pen = pen {color::cyan, 5};
      dash_dot_dot_pen.dash_style(drawing_2d::dash_style::dash_dot_dot);
      e.graphics().draw_ellipse(dash_dot_dot_pen, 120, 120, 100, 100);
      
      auto custom_pen = pen {color::magenta, 5};
      custom_pen.dash_style(drawing_2d::dash_style::custom);
      custom_pen.dash_pattern({4, 1, 3, 2});
      e.graphics().draw_ellipse(custom_pen, 230, 120, 100, 100);
    }
  };
}

auto main() -> int {
  application::run(draw_ellipe_example::form1 {});
}

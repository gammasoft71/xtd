#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Draw line example");
    }
    
    void on_paint(paint_event_args& e) override {
      auto pen_solid = pen(color::red, 5);
      e.graphics().draw_line(pen_solid, 10, e.clip_rectangle().height() / 7, e.clip_rectangle().width() - 20, e.clip_rectangle().height() / 7);
      
      auto pen_dot = pen(color::green, 5);
      pen_dot.dash_style(xtd::drawing::dash_style::dot);
      e.graphics().draw_line(pen_dot, 10, e.clip_rectangle().height() / 7 * 2, e.clip_rectangle().width() - 20, e.clip_rectangle().height() / 7 * 2);
      
      auto pen_dash = pen(color::blue, 5);
      pen_dash.dash_style(xtd::drawing::dash_style::dash);
      e.graphics().draw_line(pen_dash, 10, e.clip_rectangle().height() / 7 * 3, e.clip_rectangle().width() - 20, e.clip_rectangle().height() / 7 * 3);
      
      auto pen_dash_dot = pen(color::yellow, 5);
      pen_dash_dot.dash_style(xtd::drawing::dash_style::dash_dot);
      e.graphics().draw_line(pen_dash_dot, 10, e.clip_rectangle().height() / 7 * 4, e.clip_rectangle().width() - 20, e.clip_rectangle().height() / 7 * 4);
      
      auto pen_dash_dot_dot = pen(color::cyan, 5);
      pen_dash_dot_dot.dash_style(xtd::drawing::dash_style::dash_dot_dot);
      e.graphics().draw_line(pen_dash_dot_dot, 10, e.clip_rectangle().height() / 7 * 5, e.clip_rectangle().width() - 20, e.clip_rectangle().height() / 7 * 5);
      
      auto pen_custom = pen(color::magenta, 5);
      pen_custom.dash_style(xtd::drawing::dash_style::custom);
      pen_custom.dash_pattern({4, 1, 3, 2});
      e.graphics().draw_line(pen_custom, 10, e.clip_rectangle().height() / 7 * 6, e.clip_rectangle().width() - 20, e.clip_rectangle().height() / 7 * 6);
      
      form::on_paint(e);
    }
  };
}

int main() {
  application::run(examples::form1());
}

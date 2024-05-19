#include <xtd/drawing/drawing_2d/linear_gradient_brush>
#include <xtd/drawing/drawing_2d/radial_gradient_brush>
#include <xtd/drawing/brushes>
#include <xtd/forms/application>
#include <xtd/forms/form>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;
using namespace xtd::forms;

namespace form_paint_example {
  class form1 : public form {
  public:
    form1() {
      text("Paint example");
      client_size({640, 480});
      minimum_client_size({350, 320});
      
      paint += [](object & sender, paint_event_args & e) {
        e.graphics().clear(color::cyan);
        e.graphics().draw_string("Drawing with graphics", drawing::font("Arial", 34, font_style::regular), brushes::dark_cyan(), {20.0f, 20.0f, e.clip_rectangle().width() - 180.0f, e.clip_rectangle().height() - 40.0f});
        e.graphics().fill_ellipse(radial_gradient_brush(point {e.clip_rectangle().width() - 100, 100}, color::white, color::yellow, 75), e.clip_rectangle().width() - 150, 50, 100, 100);
        e.graphics().draw_ellipse(pen(color::yellow_green, 2), e.clip_rectangle().width() - 150, 50, 100, 100);
        e.graphics().fill_rectangle(brushes::spring_green(), 0, e.clip_rectangle().height() - 100, e.clip_rectangle().width(), 100);
        e.graphics().fill_rectangle(brushes::red(), e.clip_rectangle().width() / 2 - 140, e.clip_rectangle().height() - 180, 280, 150);
        e.graphics().fill_rectangle(brushes::black(), e.clip_rectangle().width() / 2 - 30, e.clip_rectangle().height() - 140, 60, 110);
        e.graphics().fill_rectangle(brushes::white(), e.clip_rectangle().width() / 2 - 120, e.clip_rectangle().height() - 140, 70, 60);
        e.graphics().fill_rectangle(brushes::white(), e.clip_rectangle().width() / 2 + 50, e.clip_rectangle().height() - 140, 70, 60);
        e.graphics().fill_polygon(linear_gradient_brush(rectangle {e.clip_rectangle().width() / 2 - 160, e.clip_rectangle().height() - 300, 320, 120}, color::brown, color::sandy_brown, linear_gradient_mode::backward_diagonal), vector<point> {{e.clip_rectangle().width() / 2, e.clip_rectangle().height() - 300}, {e.clip_rectangle().width() / 2 + 160, e.clip_rectangle().height() - 180}, {e.clip_rectangle().width() / 2 - 160, e.clip_rectangle().height() - 180},});
      };
    }
  };
}

auto main() -> int {
  application::run(form_paint_example::form1 {});
}

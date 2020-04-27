#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Paint example");
      location({100, 100});
      client_size({640, 480});
      
      paint += [](const control& sender, paint_event_args& e) {
        e.graphics().fill_rectangle(brushes::blue(), 0, 0, 640, 480);
        e.graphics().clear(color::light_yellow);
        e.graphics().draw_rectangle(pen(color::light_pink, 10), e.clip_rectangle());
        e.graphics().draw_line(pen(color::light_steel_blue, 5), 20, 60, 260, 60);
        e.graphics().fill_rectangle(brushes::light_blue(), 50, 300, 400, 50);
        e.graphics().draw_line(pens::red(), 0, 0, 1, 1);
        e.graphics().draw_string("Draw string", drawing::font("Arial", 34, font_style::regular), brushes::light_green(), 20.0f, 0.0f);
        e.graphics().fill_rectangle(brushes::light_sea_green(), 400, 70, 100, 200);
        e.graphics().draw_arc(pen(color::black, 10), 400, 70, 100, 200, 45, 270);
        e.graphics().draw_ellipse(pen(color::red, 10), 100, 80, 200, 200);
        e.graphics().fill_pie(brushes::green(), 120, 100, 160, 160, 45, 270);
        e.graphics().fill_pie(brushes::light_green(), 120, 100, 160, 160, 270, 180);
        e.graphics().draw_bezier(pens::black(), 100, 100, 150, 150, 200, 100, 250, 50);
      };
    }
  };
}

int main() {
  application::run(examples::form1());
}

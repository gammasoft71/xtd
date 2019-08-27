#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      this->text("Paint example");
      this->location({100, 100});
      this->client_size({640, 480});
      
      this->paint += [&](const control& sender, paint_event_args& e) {
        e.graphics().fill_rectangle(drawing::solid_brush(drawing::color::blue), 0, 0, 640, 480);
        e.graphics().clear(drawing::color::light_yellow);
        e.graphics().draw_rectangle(drawing::pen(drawing::color::light_pink, 10), e.clip_rectangle());
        e.graphics().draw_line(drawing::pen(drawing::color::light_steel_blue, 5), 20, 60, 260, 60);
        e.graphics().fill_rectangle(drawing::solid_brush(drawing::color::light_blue), 50, 300, 400, 50);
        e.graphics().draw_line(drawing::pen(drawing::color::red, 1), 0, 0, 1, 1);
        e.graphics().draw_string("Draw string", drawing::font("Arial", 34, drawing::font_style::regular), drawing::solid_brush(drawing::color::light_green), 20.0f, 0.0f);
        e.graphics().fill_rectangle(drawing::solid_brush(drawing::color::light_sea_green), 400, 70, 100, 200);
        e.graphics().draw_arc(drawing::pen(drawing::color::black, 10), 400, 70, 100, 200, 45, 270);
        e.graphics().draw_ellipse(drawing::pen(drawing::color::red, 10), 100, 80, 200, 200);
        e.graphics().fill_pie(drawing::solid_brush(drawing::color::green), 120, 100, 160, 160, 45, 270);
        e.graphics().fill_pie(drawing::solid_brush(drawing::color::light_green), 120, 100, 160, 160, 270, 180);
        e.graphics().draw_bezier(drawing::pen(drawing::color::black), 100, 100, 150, 150, 200, 100, 250, 50);
      };
    }
  };
}

int main() {
  application::run(examples::form1());
}

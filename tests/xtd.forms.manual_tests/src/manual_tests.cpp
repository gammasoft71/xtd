#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  form form;
  form.text("Manual tests");
  form.client_size({640, 480});

  form.show();
  form.paint += [&](const control& sender, paint_event_args& e) {
    graphics g = e.graphics();
    g.fill_rectangle(solid_brush(color::blue), 0, 0, 640, 480);
    g.clear(color::light_yellow);
    g.draw_rectangle(pen(color::light_pink, 10), e.clip_rectangle());
    g.draw_line(pen(color::light_steel_blue, 5), 20, 60, 260, 60);
    g.fill_rectangle(solid_brush(color::light_blue), 50, 300, 400, 50);
    g.draw_line(pen(color::red, 1), 0, 0, 1, 1);
    g.draw_string("Draw string", font(font_family::generic_sans_serif(), 34, font_style::regular), solid_brush(color::light_green), 20.0f, 0.0f);
    g.fill_rectangle(solid_brush(color::light_sea_green), 400, 70, 100, 200);
    g.draw_arc(pen(color::black, 10), 400, 70, 100, 200, 45, 270);
    g.draw_ellipse(pen(color::red, 10), 100, 80, 200, 200);
    g.fill_pie(solid_brush(color::green), 120, 100, 160, 160, 45, 270);
    g.fill_pie(solid_brush(color::light_green), 120, 100, 160, 160, 270, 180);
    g.draw_bezier(pen(color::black), 100, 100, 150, 150, 200, 100, 250, 50);
 };
  
  application::run(form);
}

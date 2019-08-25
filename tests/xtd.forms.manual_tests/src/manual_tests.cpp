#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

// The main entry point for the application.
int main() {
  form form;
  form.text("Manual tests");
  form.client_size({640, 480});

  form.show();
  form.paint += [&](const control& sender, paint_event_args& e) {
    //string_format string_format;
    e.graphics().fill_rectangle(solid_brush(color::blue), 0, 0, 640, 480);
    e.graphics().clear(color::light_yellow);
    e.graphics().draw_rectangle(pen(color::light_pink, 10), e.clip_rectangle());
    e.graphics().draw_line(pen(color::light_steel_blue, 5), 20, 60, 260, 60);
    e.graphics().fill_rectangle(solid_brush(color::light_blue), 50, 300, 400, 50);
    e.graphics().draw_line(pen(color::red, 1), 0, 0, 1, 1);
    //e.graphics().draw_string("Draw string", font("Arial", 34, font_style::regular), solid_brush(color::light_green), 20, 0, string_format);
    e.graphics().fill_rectangle(solid_brush(color::light_sea_green), 400, 70, 100, 200);
    e.graphics().draw_arc(pen(color::black, 10), 400, 70, 100, 200, 45, 270);
 };
  
  application::run(form);
}

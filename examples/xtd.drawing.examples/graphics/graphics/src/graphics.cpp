#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
using namespace xtd::io;

auto main()->int {
  bitmap bitmap(640, 480);
  auto graphics = graphics::from_image(bitmap);
  graphics.clear(color::cyan);
  graphics.draw_string("Drawing with graphics", drawing::font("Arial", 34, font_style::regular), brushes::dark_cyan(), {20.0f, 20.0f, bitmap.width() - 180.0f, bitmap.height() - 40.0f});
  graphics.fill_ellipse(radial_gradient_brush(point {bitmap.width() - 100, 100}, color::white, color::yellow, 75), bitmap.width() - 150, 50, 100, 100);
  graphics.draw_ellipse(pen(color::yellow_green, 2), bitmap.width() - 150, 50, 100, 100);
  graphics.fill_rectangle(brushes::spring_green(), 0, bitmap.height() - 100, bitmap.width(), 100);
  graphics.fill_rectangle(brushes::red(), bitmap.width() / 2 - 140, bitmap.height() - 180, 280, 150);
  graphics.fill_rectangle(brushes::black(), bitmap.width() / 2 - 30, bitmap.height() - 140, 60, 110);
  graphics.fill_rectangle(brushes::white(), bitmap.width() / 2 - 120, bitmap.height() - 140, 70, 60);
  graphics.fill_rectangle(brushes::white(), bitmap.width() / 2 + 50, bitmap.height() - 140, 70, 60);
  graphics.fill_polygon(linear_gradient_brush(rectangle {bitmap.width() / 2 - 160, bitmap.height() - 300, 320, 120}, color::brown, color::sandy_brown, linear_gradient_mode::backward_diagonal), vector<point> {{bitmap.width() / 2, bitmap.height() - 300}, {bitmap.width() / 2 + 160, bitmap.height() - 180}, {bitmap.width() / 2 - 160, bitmap.height() - 180},});
  bitmap.save(path::combine(path::get_temp_path(), "graphics.png"));
  process::start(path::combine(path::get_temp_path(), "graphics.png"));
}

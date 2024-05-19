#include <xtd/diagnostics/process>
#include <xtd/drawing/drawing_2d/linear_gradient_brush>
#include <xtd/drawing/drawing_2d/radial_gradient_brush>
#include <xtd/drawing/bitmap>
#include <xtd/drawing/brushes>
#include <xtd/drawing/graphics>
#include <xtd/drawing/system_fonts>
#include <xtd/io/path>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;
using namespace xtd::io;

auto main() -> int {
  auto drawing_bitmap = bitmap {640, 480};
  auto graphics = graphics::from_image(drawing_bitmap);
  graphics.clear(color::cyan);
  graphics.draw_string("Drawing with graphics", drawing::font {"Arial", 34, font_style::regular}, brushes::dark_cyan(), {20.0f, 20.0f, drawing_bitmap.width() - 180.0f, drawing_bitmap.height() - 40.0f});
  graphics.fill_ellipse(radial_gradient_brush(point {drawing_bitmap.width() - 100, 100}, color::white, color::yellow, 75), drawing_bitmap.width() - 150, 50, 100, 100);
  graphics.draw_ellipse(pen {color::yellow_green, 2}, drawing_bitmap.width() - 150, 50, 100, 100);
  graphics.fill_rectangle(brushes::spring_green(), 0, drawing_bitmap.height() - 100, drawing_bitmap.width(), 100);
  graphics.fill_rectangle(brushes::red(), drawing_bitmap.width() / 2 - 140, drawing_bitmap.height() - 180, 280, 150);
  graphics.fill_rectangle(brushes::black(), drawing_bitmap.width() / 2 - 30, drawing_bitmap.height() - 140, 60, 110);
  graphics.fill_rectangle(brushes::white(), drawing_bitmap.width() / 2 - 120, drawing_bitmap.height() - 140, 70, 60);
  graphics.fill_rectangle(brushes::white(), drawing_bitmap.width() / 2 + 50, drawing_bitmap.height() - 140, 70, 60);
  graphics.fill_polygon(linear_gradient_brush {rectangle {drawing_bitmap.width() / 2 - 160, drawing_bitmap.height() - 300, 320, 120}, color::brown, color::sandy_brown, linear_gradient_mode::backward_diagonal}, vector<point> {{drawing_bitmap.width() / 2, drawing_bitmap.height() - 300}, {drawing_bitmap.width() / 2 + 160, drawing_bitmap.height() - 180}, {drawing_bitmap.width() / 2 - 160, drawing_bitmap.height() - 180},});
  drawing_bitmap.save(path::combine(path::get_temp_path(), "graphics.png"));
  process::start(path::combine(path::get_temp_path(), "graphics.png"));
}

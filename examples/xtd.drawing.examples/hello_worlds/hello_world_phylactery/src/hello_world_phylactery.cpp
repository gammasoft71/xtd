#include <xtd/xtd>

using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;

auto main() -> int {
  auto drawing_bitmap = bitmap {640, 480};
  auto graphics = graphics::from_image(drawing_bitmap);
  
  graphics.draw_ellipse(pen {color::black, 10.0f}, rectangle {10, 10, 620, 388});
  graphics.fill_polygon(solid_brush {color::white}, array<point> {{156, 338}, {92, 460}, {252,338}});
  graphics.draw_polygon(pen {color::black, 10.0f}, array<point> {{156, 338}, {92, 460}, {252,338}});
  graphics.fill_ellipse(solid_brush {color::white}, ellipse.inflate(rectangle {10, 10, 620, 388}, size {-5, -5}));
  graphics.draw_string("Hello, World!", {system_fonts::default_font(), 60.0f, font_style::bold}, solid_brush {color::black}, rectangle {10, 10, 620, 388}, string_format().alignment(string_alignment::center).line_alignment(string_alignment::center));
  
  drawing_bitmap.save(path::combine(path::get_temp_path(), "hello_world_phylactery.png"));
  diagnostics::process::start(diagnostics::process_start_info {path::combine(path::get_temp_path(), "hello_world_phylactery.png")}.use_shell_execute(true)).wait_for_exit();
}

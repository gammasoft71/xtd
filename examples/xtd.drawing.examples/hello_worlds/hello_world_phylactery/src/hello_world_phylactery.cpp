#include <xtd/xtd>

using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;
using namespace xtd::drawing::text;

auto main() -> int {
  auto drawing_bitmap = bitmap {640, 480};
  auto graphics = graphics::from_image(drawing_bitmap);
  
  auto ellipse = rectangle {10, 10, 620, 388};
  auto tip = array<point> {{156, 338}, {92, 460}, {252,338}};
  
  graphics.smoothing_mode(smoothing_mode::anti_alias);
  graphics.text_rendering_hint(text_rendering_hint::clear_type_grid_fit);
  //graphics.clear(color::light_blue);
  graphics.draw_ellipse(pen {color::black, 10}, ellipse);
  graphics.fill_polygon(solid_brush {color::white}, tip);
  graphics.draw_polygon(pen {color::black, 10}, tip);
  graphics.fill_ellipse(solid_brush {color::white}, ellipse.inflate(ellipse, size {-5, -5}));
  graphics.draw_string("Hello, World!", {system_fonts::default_font(), 60, font_style::bold}, solid_brush {color::black}, ellipse, string_format().alignment(string_alignment::center).line_alignment(string_alignment::center));
  
  drawing_bitmap.save(path::combine(path::get_temp_path(), "hello_world_phylactery.png"));
  diagnostics::process::start(diagnostics::process_start_info {path::combine(path::get_temp_path(), "hello_world_phylactery.png")}.use_shell_execute(true)).wait_for_exit();
}

#include <xtd/xtd>

using namespace xtd::drawing;

auto main() -> int {
  auto hello_world_bitmap = bitmap {300, 300};
  auto graphics = graphics::from_image(hello_world_bitmap);
  graphics.draw_string("Hello World!", {system_fonts::default_font(), 32, font_style::bold | font_style::italic}, solid_brush {color_converter::dark(color::spring_green, 2.0 / 3)}, rectangle::offset({{0, 0}, hello_world_bitmap.size()}, {2, 2}), string_format {}.alignment(string_alignment::center).line_alignment(string_alignment::center));
  graphics.draw_string("Hello World!", {system_fonts::default_font(), 32, font_style::bold | font_style::italic}, brushes::spring_green(), rectangle::inflate({{0, 0}, hello_world_bitmap.size()}, {-2, -2}), string_format {}.alignment(string_alignment::center).line_alignment(string_alignment::center));
  auto hello_world_path = path::combine(path::get_temp_path(), "hello_world.png");
  hello_world_bitmap.save(hello_world_path);
  diagnostics::process::start(diagnostics::process_start_info {hello_world_path}.use_shell_execute(true)).wait_for_exit();
}

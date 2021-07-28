#include <xtd/xtd>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;

int main() {
  bitmap bitmap(300, 300);
  auto graphics = graphics::from_image(bitmap);
  graphics.draw_string("Hello World!", {system_fonts::default_font(), 32, font_style::bold | font_style::italic}, solid_brush(color::dark(color::spring_green, 2.0 / 3)), rectangle::offset({{0, 0}, bitmap.size()}, {2, 2}), string_format().alignment(string_alignment::center).line_alignment(string_alignment::center));
  graphics.draw_string("Hello World!", {system_fonts::default_font(), 32, font_style::bold | font_style::italic}, brushes::spring_green(), rectangle::inflate({{0, 0}, bitmap.size()}, {-2, -2}), string_format().alignment(string_alignment::center).line_alignment(string_alignment::center));
  bitmap.save("hello_world_png.png");
  process::start(ustring::format("{} hello_world_png.png", environment::os_version().is_windows_platform() ? "start" : "open")).wait_for_exit();
}

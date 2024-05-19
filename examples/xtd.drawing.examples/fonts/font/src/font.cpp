#include <xtd/drawing/font>
#include <xtd/console>

using namespace xtd;
using namespace xtd::drawing;

auto main() -> int {
  auto font1 = font {font_family::generic_monospace(), 42.0f, font_style::bold};
  console::write_line("font1 = {0}", font1);
  
  auto font2 = font {"Times New Roman", 24.0f};
  console::write_line("font2 = {0}", font2);
  
  auto font3 = font {font_family::generic_serif(), 24.0f};
  console::write_line("font3 = {0}", font3);
  
  console::write_line("font1 {0} font2", font1 == font2 ? "==" : "!=");
  console::write_line("font2 {0} font3", font2 == font3 ? "==" : "!=");
}

// This code can produce the following output:
//
// font1 = [font: name=Courier, size=42, units=3, gdi_char_set=0, gdi_vertical_font=false]
// font2 = [font: name=Times, size=24, units=3, gdi_char_set=0, gdi_vertical_font=false]
// font3 = [font: name=Times New Roman, size=24, units=3, gdi_char_set=0, gdi_vertical_font=false]
// font1 != font2
// font2 == font3

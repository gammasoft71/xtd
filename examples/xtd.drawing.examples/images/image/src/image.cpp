#include <xtd/drawing/bitmap>
#include <xtd/console>
#include "logo.xpm"

using namespace xtd;
using namespace xtd::drawing;

auto main() -> int {
  auto bmp = bitmap {logo_xpm};
  
  console::write_line("handle = 0x{:X}", bmp.handle());
  console::write_line("horizontal resolution = {}", bmp.horizontal_resolution());
  console::write_line("physical dimension = {}", bmp.physical_dimension());
  console::write_line("raw format = {}", bmp.raw_format());
  console::write_line("vertcal resolution = {}", bmp.vertical_resolution());
  console::write_line("size = {}", bmp.size());
  console::write_line("pixel[50][100] = {}", bmp.get_pixel(50, 100));
}

// This code produces the following output:
//
// handle = 0x101E61F10
// horizontal resolution = 96
// physical dimension = {width=256.000000, height=256.000000}
// raw format = [image_format: b96b3cc0-0728-11d3-9d7b-0000f81ef32e]
// vertcal resolution = 96
// size = {width=256, height=256}
// pixel[50][100] = color [a=255, r=0, g=64, b=128]

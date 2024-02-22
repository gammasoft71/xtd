#include <iostream>
#include <xtd/drawing/drawing_2d/hatch_brush.h>
#include <xtd/drawing/bitmap>
#include <xtd/drawing/color>
#include <xtd/io/file>
#include <xtd/io/path>
#include <xtd/console>
#include <xtd/ustring>
//#include "logo.xpm"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;

void to_ppm(const xtd::ustring& filename, const xtd::drawing::bitmap& bitmap, const color& transparent_color = color::white) {
  std::vector<xtd::ustring> lines;
  lines.push_back("P3");
  lines.push_back("# Ppm.ppm");
  lines.push_back(xtd::ustring::format("{} {}", bitmap.width(), bitmap.height()));
  lines.push_back("255");
  lines.push_back("");
  for (int y = 0; y < bitmap.height(); y++) {
    for (int x = 0; x < bitmap.width(); x++)
      if (bitmap.get_pixel(x, y).a() == 0)
        lines.push_back(ustring::format("{, 3} {, 3} {, 3}", transparent_color.r(), transparent_color.g(), transparent_color.b()));
      else
        lines.push_back(ustring::format("{, 3} {, 3} {, 3}", bitmap.get_pixel(x, y).r(), bitmap.get_pixel(x, y).g(), bitmap.get_pixel(x, y).b()));
    lines.push_back("");
  }
  xtd::io::file::write_all_lines(ustring(filename), lines);
}

void to_ppm(const xtd::ustring& filename, const color& transparent_color = color::white) {
  to_ppm(xtd::io::path::combine(xtd::io::path::get_directory_name(filename), xtd::ustring::format("{}{}", xtd::io::path::get_file_name_without_extension(filename), ".ppm")), bitmap(filename), transparent_color);
}

auto main()->int {
  //to_ppm("/Users/yves/Desktop/test.png");
  //bitmap img = bitmap(logo_xpm);
  //to_ppm("/Users/yves/Desktop/logo.ppm", img, color::magenta);
  
  for (auto hatch : enum_object<>::get_values<hatch_style>()) {
    auto bmp = bitmap {200, 100};
    auto g = graphics::from_image(bmp);
    g.fill_rectangle(hatch_brush {hatch, color::white, color::dark_blue}, rectangle {{0, 0}, bmp.size()});
    bmp.save(ustring::format("hatch_brush_{}.png", hatch));
  }
}

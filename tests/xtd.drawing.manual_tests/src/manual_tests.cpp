#include <iostream>
#include <xtd/xtd.drawing>
//#include "logo.xpm"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

void to_ppm(const std::string& filename, const xtd::drawing::bitmap& bitmap, const color& transparent_color = color::white) {
  std::vector<std::string> lines;
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

void to_ppm(const std::string& filename, const color& transparent_color = color::white) {
  to_ppm(xtd::io::path::combine(xtd::io::path::get_directory_name(filename), xtd::ustring::format("{}{}", xtd::io::path::get_file_name_without_extension(filename), ".ppm")), bitmap(filename), transparent_color);
}

int main() {
  //to_ppm("/Users/yves/Desktop/test.png");
  //bitmap img = bitmap(logo_xpm);
  //to_ppm("/Users/yves/Desktop/logo.ppm", img, color::magenta);
  cout << ustring::format("color = {}", color::light(color::light(color::from_argb(128, 128, 128)))) << endl;
  cout << ustring::format("color = {}", color::light(color::from_argb(128, 128, 128))) << endl;
  cout << ustring::format("color = {}", color::from_argb(128, 128, 128)) << endl;
  cout << ustring::format("color = {}", color::dark(color::from_argb(128, 128, 128))) << endl;
  cout << ustring::format("color = {}", color::dark(color::dark(color::from_argb(128, 128, 128)))) << endl;
  image img = image::empty;
}

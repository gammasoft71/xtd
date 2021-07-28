#include <iostream>
#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

int main() {
  font font1(font_family::generic_monospace(), 42.0f, font_style::bold);
  cout << ustring::format("font1 = {0}", font1) << endl;

  font font2("Times New Roman", 24.0f);
  cout << ustring::format("font2 = {0}", font2) << endl;

  font font3(font_family::generic_serif(), 24.0f);
  cout << ustring::format("font3 = {0}", font3) << endl;

  cout << ustring::format("font1 {0} font2", font1 == font2 ? "==" : "!=") << endl;
  cout << ustring::format("font2 {0} font3", font2 == font3 ? "==" : "!=") << endl;
}

// This code can produce the following output:
//
// font1 = [font: name=Courier, size=42, units=3, gdi_char_set=0, gdi_vertical_font=false]
// font2 = [font: name=Times, size=24, units=3, gdi_char_set=0, gdi_vertical_font=false]
// font3 = [font: name=Times New Roman, size=24, units=3, gdi_char_set=0, gdi_vertical_font=false]
// font1 != font2
// font2 == font3

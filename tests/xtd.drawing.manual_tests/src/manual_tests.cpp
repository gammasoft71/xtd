#include <iostream>
#include <xtd/xtd.drawing>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

int main() {
  cout << format("families = {{{}}}", strings::join(", ", font_family::families())) << endl;
  cout << format("Serif = {}", font_family::generic_serif()) << endl;
  cout << format("Sans Serif = {}", font_family::generic_sans_serif()) << endl;
  cout << format("Monspace = {}", font_family::generic_monospace()) << endl;
  cout << format("arial = {}", font_family("arial")) << endl;
  cout << format("arial.ascent = {}", font_family("arial").get_cell_ascent(font_style::regular)) << endl;
  cout << format("arial.descent = {}", font_family("arial").get_cell_descent(font_style::regular)) << endl;
}

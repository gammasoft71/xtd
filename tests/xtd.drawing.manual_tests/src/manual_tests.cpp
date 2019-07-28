#include <iostream>
#include <xtd/xtd.drawing>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

// The main entry point for the application.
int main() {
  cout << "color::empty = " << color::empty << endl;
  cout << "color::blue = " << color::blue << endl;
  cout << "color::from_argb(255, 255, 0, 0) = " << color::from_argb(255, 255, 0, 0) << endl;
  cout << "system_colors::active_border = " << system_colors::active_border << endl;
}

#include <iostream>
#include <xtd/xtd.drawing>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

int main() {
  cout << format("color::black = {0}", color::black) << endl;
  cout << format("color::withe = {0}", color::white) << endl;
  cout << format("color::blue = {0}", color::blue) << endl;
  cout << format("Color::light_green = {0}", color::light_green) << endl;
  cout << format("Color::from_argb(255, 253, 2, 0) = {0}", color::from_argb(255, 253, 2, 0)) << endl;
  cout << format("color::from_name(\"dodger_blue\") = {0}", color::from_name("dodger_blue")) << endl;
}

// This code produces the following output:
//
// color::black = color [black]
// color::withe = color [white]
// color::blue = color [blue]
// Color::light_green = color [light_green]
// Color::from_argb(255, 253, 2, 0) = color [a=255, r=253, g=2, b=0]
// color::from_name("dodger_blue") = color [dodger_blue]

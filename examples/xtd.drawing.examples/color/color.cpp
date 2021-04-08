#include <iostream>
#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

int main() {
  cout << strings::format("color::black = {0}", color::black) << endl;
  cout << strings::format("color::withe = {0}", color::white) << endl;
  cout << strings::format("color::blue = {0}", color::blue) << endl;
  cout << strings::format("Color::light_green = {0}", color::light_green) << endl;
  cout << strings::format("Color::from_argb(255, 253, 2, 0) = {0}", color::from_argb(255, 253, 2, 0)) << endl;
  cout << strings::format("color::from_name(\"dodger_blue\") = {0}", color::from_name("dodger_blue")) << endl;
  cout << strings::format("color::from_name(\"dodger blue\") = {0}", color::from_name("dodger blue")) << endl;
}

// This code produces the following output:
//
// color::black = color [black]
// color::withe = color [white]
// color::blue = color [blue]
// Color::light_green = color [light_green]
// Color::from_argb(255, 253, 2, 0) = color [a=255, r=253, g=2, b=0]
// color::from_name("dodger_blue") = color [dodger_blue]
// color::from_name("dodger blue") = color [dodger_blue]

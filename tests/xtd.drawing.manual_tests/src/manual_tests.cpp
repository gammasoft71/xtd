#include <iostream>
#include <xtd/xtd.drawing>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

// The main entry point for the application.
int main() {
  cout << format("color::empty = {}", color::empty) << endl;
  cout << format("color::alice_blue = {}", color::alice_blue) << endl;
  cout << format("color::blue = {}", color::blue) << endl;
  cout << format("color::blue.to_argb() = 0x{:X}", color::blue.to_argb()) << endl;
  cout << format("color::from_argb(128, color::blue) = {}", color::from_argb(128, color::blue)) << endl;
  cout << format("color::from_argb(255, 255, 0, 0) = {}", color::from_argb(255, 255, 0, 0)) << endl;
  cout << format("ccolor::from_name(\"buttonface\") = {}", color::from_name("buttonface")) << endl;
  cout << format("color::parse(\"button face\") = {}", color::parse("button face")) << endl;
  cout << format("color::parse(\"color [button face]\") = {}", color::parse("color [button face]")) << endl;
  cout << format("color::parse(\"BLUE\") = {}", color::parse("BLUE")) << endl;
  cout << format("color::parse(\"color [blue]\") = {}", color::parse("color [blue]")) << endl;
  cout << format("color::parse(\"color [a=255, r=0, g=80, b=0]\") = {}", color::parse("color [a=255, r=0, g=80, b=0]")) << endl;
  cout << format("system_colors::button_face = {}", system_colors::button_face) << endl;
  cout << format("system_colors::button_face.to_argb() = 0x{:X}", system_colors::button_face.to_argb()) << endl;
}

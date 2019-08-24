#include <iostream>
#include <xtd/xtd.drawing>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

int main() {
  solid_brush solid_brush1(color::spring_green);
  cout << strings::format("solid_brush1 = {}", solid_brush1) << endl;
  cout << strings::format("solid_brush1.color() = {}", solid_brush1.color()) << endl;

  solid_brush solid_brush2 = solid_brush1;
  cout << strings::format("solid_brush2 = {}", solid_brush2) << endl;
  cout << strings::format("solid_brush2.color() = {}", solid_brush2.color()) << endl;
}

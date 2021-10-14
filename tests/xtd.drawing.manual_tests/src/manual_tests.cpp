#include <iostream>
#include <xtd/xtd.drawing>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

int main() {
  cout << ustring::format("color = {}", color::light(color::light(color::from_argb(128, 128, 128)))) << endl;
  cout << ustring::format("color = {}", color::light(color::from_argb(128, 128, 128))) << endl;
  cout << ustring::format("color = {}", color::from_argb(128, 128, 128)) << endl;
  cout << ustring::format("color = {}", color::dark(color::from_argb(128, 128, 128))) << endl;
  cout << ustring::format("color = {}", color::dark(color::dark(color::from_argb(128, 128, 128)))) << endl;
}

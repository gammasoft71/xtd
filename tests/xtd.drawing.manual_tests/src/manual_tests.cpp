#include <iostream>
#include <xtd/xtd.drawing>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

int main() {
  font font("Arial", 12, font_style::italic);
  cout << format("font = {}", font) << endl;
}

#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << background_color(console_color::blue) << foreground_color(console_color::white) << "Hello, World!" << reset_color() << endl;
}

// This code produces the following output with colors :
//
// Hello, World!

#include <xtd/xtd>
#include <string>

using namespace std;
using namespace xtd;

// The main entry point for the application.
int main() {
  const char* s1 = "Hello,";
  string s2 = "World!";
  
  cout << foreground_color(console_color::green);
  cout << format("%s%7s", s1, s2);
  cout << reset_color() << endl;
  
  console::background_color(console_color::blue);
  console::foreground_color(console_color::white);
  console::write_line("%s%7s", s1, s2);
  console::reset_color();
}

// This code produces the following output with colors :
//
// Hello, World!
// Hello, World!

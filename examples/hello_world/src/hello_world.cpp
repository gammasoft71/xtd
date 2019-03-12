#include <xtd/console>

using namespace std;
using namespace xtd;

// The main entry point for the application.
int main() {
  const char* s1 = "Hello,";
  string s2 = "World!";
  
  console::out << background_color(console_color::cyan);
  cout << foreground_color(console_color::yellow);
  cout << format("%s%7s", s1, s2);
  cout << reset_color() << endl;
  
  console::out << background_color(console_color::white);
  console::out << foreground_color(console_color::black);
  console::out << format("%s%7s", s1, s2);
  console::out << reset_color() << endl;
  
  console::background_color(console_color::blue);
  console::foreground_color(console_color::white);
  console::write_line("%s%7s", s1, s2);
  console::reset_color();
}

// This code produces the following output with colors :
//
// Hello, World!
// Hello, World!
// Hello, World!

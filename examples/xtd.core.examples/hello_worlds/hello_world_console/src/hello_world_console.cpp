#include <xtd/xtd>

using namespace xtd;

int main() {
  console::background_color(console_color::blue);
  console::foreground_color(console_color::white);
  console::write_line("Hello, World!");
  console::reset_color();
}

// This code produces the following output with colors :
//
// Hello, World!

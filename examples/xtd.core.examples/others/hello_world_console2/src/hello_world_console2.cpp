#include <xtd/xtd>

auto main() -> int {
  console::out << background_color(console_color::blue) << foreground_color(console_color::white) << "Hello, World!" << reset_color() << environment::new_line;
}

// This code produces the following output with colors :
//
// Hello, World!

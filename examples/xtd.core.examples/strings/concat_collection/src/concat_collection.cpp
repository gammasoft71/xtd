#include <xtd/xtd>

auto main() -> int {
  auto items = {"One ", "Two ", "Three ", "Four "};
  console::write_line(string::concat(items));
}

// This code produces the following output :
//
// One Two Three Four

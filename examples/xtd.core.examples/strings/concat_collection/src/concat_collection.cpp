#include <xtd/console>
#include <xtd/ustring>

using namespace xtd;

auto main() -> int {
  auto items = {"One ", "Two ", "Three ", "Four "};
  console::write_line(ustring::concat(items));
}

// This code produces the following output:
//
// One Two Three Four

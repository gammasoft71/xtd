#include <xtd/console>
#include <xtd/ustring>

using namespace xtd;

auto main() -> int {
  auto result_str = ustring::join(", ", {"One", "Two", "Three", "Four", "Five"});
  console::write_line(result_str);
}

// This code produces the following output:
//
// One, Two, Three, Four, Five

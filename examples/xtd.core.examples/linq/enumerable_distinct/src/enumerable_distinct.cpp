#include <xtd/xtd>

auto main() -> int {
  auto numbers = array {2, 7, 3, 1, 1, 4, 10, 5, 3, 3, 3, 6, 6, 2, 8, 9, 8, 9};
  console::write_line("numbers = {}", numbers.distinct());
}

// This code produces the following output :
//
// numbers = [2, 7, 3, 1, 4, 10, 5, 6, 8, 9]

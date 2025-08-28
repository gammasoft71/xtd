#include <xtd/xtd>

auto main() -> int {
  auto numbers = array {1, 1, 2, 3, 3, 3, 3, 4, 5, 6, 6, 2, 7, 8, 9, 10, 8, 9};
  console::write_line("numbers = {}", numbers.distinct());
}

// This code produces the following output :
//
// numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

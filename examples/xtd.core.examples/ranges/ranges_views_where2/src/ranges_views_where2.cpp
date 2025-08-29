#include <xtd/xtd>

auto main() -> int {
  auto numbers = array {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  console::write_line("numbers = {}", where(numbers, [](auto n) {return n <= 5;}));
}

// This code produces the following output :
//
// numbers = [1, 2, 3, 4, 5]

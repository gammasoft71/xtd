#include <xtd/xtd>

auto main() -> int {
  auto numbers = array {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  console::write_line("numbers = {}", select(numbers, [](auto n) {return n * n;}));
}

// This code produces the following output :
//
// numbers = [1, 4, 9, 16, 25, 36, 49, 64, 81, 100]

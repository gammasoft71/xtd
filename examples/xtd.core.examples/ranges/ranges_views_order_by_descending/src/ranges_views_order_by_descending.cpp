#include <xtd/xtd>

auto main() -> int {
  auto numbers = array {2, 7, 3, 1, 4, 10, 5, 6, 8, 9};
  console::write_line("numbers = {}", numbers | order_by_descending([](auto n) {return n;}));
}

// This code produces the following output :
//
// numbers = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]

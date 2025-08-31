#include <xtd/xtd>

auto main() -> int {
  auto numbers = array {2, 7, 3, 1, 4, 10, 5, 6, 8, 9};
  console::write_line("numbers = {}", numbers | order_by([](auto n) {return n;}));
}

// This code produces the following output :
//
// numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

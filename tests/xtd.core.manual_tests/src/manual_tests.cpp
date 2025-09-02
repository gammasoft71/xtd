#include <xtd/xtd>

auto main() -> int {
  /*
  auto numbers = array {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // Gets distinct numbers with xtd::collections::extensions::enumerable extension.
  auto query1 = numbers | select<bool>([](auto n)->bool {return n % 2 == 0;});
  console::write_line("query1 = {}", query1);
   */
  
  auto numbers = list {2, 7, 3, 1, 4, 10, 5, 6, 8, 9};
  console::write_line("numbers = {}", numbers | order_by([](auto n) {return n;}));
  console::write_line("numbers = {}", numbers | order_by_descending([](auto n) {return n;}));
}

// This code produces the following output :
//
// distinct numbers = [4, 49, 9, 1, 16, 100, 25, 36, 64, 81]
// distinct numbers = [4, 49, 9, 1, 16, 100, 25, 36, 64, 81]

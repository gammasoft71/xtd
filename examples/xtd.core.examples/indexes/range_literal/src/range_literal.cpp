#include <xtd/xtd>

auto main() -> int {
  auto items = list {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  
  println("items[\"0..10\"_r] = {}", items["0..10"_r]);
  println("items[\"2..6\"_r] = {}", items["2..6"_r]);
  println("items[\"0..~0\"_r] = {}", items["0..~0"_r]);
  println("items[\"2..~4\"_r] = {}", items["2..~4"_r]);
  println("items[\"~10..~0\"_r] = {}", items["~10..~0"_r]);
  println("items[\"~8..~4\"_r] = {}", items["~8..~4"_r]);
}

// This code produces the following output :
//
// items["0..10"_r] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// items["2..6"_r] = [3, 4, 5, 6]
// items["0..~0"_r] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// items["2..~4"_r] = [3, 4, 5, 6]
// items["~10..~0"_r] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// items["~8..~4"_r] = [3, 4, 5, 6]

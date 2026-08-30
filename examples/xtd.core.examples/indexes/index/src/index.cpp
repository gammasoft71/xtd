#include <xtd/xtd>

auto main() -> int {
  auto items = list {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  
  println("items[0_i] = {}", items[index::from_start(0)]);
  println("items(1_i) = {}", items(1_i));
  println("items[2_i] = {}", items[2_i]);
  println("items(3_i) = {}", items(3_i));
  println("items[4_i] = {}", items[4_i]);
  println("items(5_i) = {}", items(5_i));
  println("items[6_i] = {}", items[6_i]);
  println("items(7_i) = {}", items(7_i));
  println("items[8_i] = {}", items[8_i]);
  println("items(9_i) = {}", items(index::from_start(9)));
  println();
  println("items[~1_i] = {}", items[index::from_end(1)]);
  println("items(~2_i) = {}", items(~2_i));
  println("items[~3_i] = {}", items[~3_i]);
  println("items(~4_i) = {}", items(~4_i));
  println("items[~5_i] = {}", items[~5_i]);
  println("items(~6_i) = {}", items(~6_i));
  println("items[~7_i] = {}", items[~7_i]);
  println("items(~8_i) = {}", items(~8_i));
  println("items[~9_i] = {}", items[~9_i]);
  println("items(~10_i) = {}", items(index::from_end(10)));
}

// This code produces the following output :
//
// items[0_i] = 1
// items(1_i) = 2
// items[2_i] = 3
// items(3_i) = 4
// items[4_i] = 5
// items(5_i) = 6
// items[6_i] = 7
// items(7_i) = 8
// items[8_i] = 9
// items(9_i) = 10
//
// items[~1_i] = 10
// items(~2_i) = 9
// items[~3_i] = 8
// items(~4_i) = 7
// items[~5_i] = 6
// items(~6_i) = 5
// items[~7_i] = 4
// items(~8_i) = 3
// items[~9_i] = 2
// items(~10_i) = 1

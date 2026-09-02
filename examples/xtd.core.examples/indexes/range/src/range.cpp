#include <xtd/xtd>

auto main() -> int {
  auto items = list {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  
  println("items[range::all()] = {}", items[range::all()]);
  println("items(range::start_at(2)) = {}", items(range::start_at(2)));
  println("items[range::start_at(index::from_end(8))] = {}", items[range::start_at(index::from_end(8))]);
  println("items(range::start_at(~8_i)) = {}", items(range::start_at(~8_i)));
  println("items[range::end_at(6)] = {}", items[range::end_at(6)]);
  println("items[range::end_at(index::from_start(6))] = {}", items[range::end_at(index::from_start(6))]);
  println("items(range::end_at(~4_i)) = {}", items(range::end_at(~4_i)));
  println("items(range {{2, 6}}) = {}", items[range {2, 6}]);
  println("items(range {{3_i, ~2_i}}) = {}", items[range {3_i, ~2_i}]);
  println("items({{0, 8}}) = {}", items[{0, 8}]);
  println("items({{1_i, ~4_i}}) = {}", items[{1_i, ~4_i}]);
}

// This code produces the following output :
//
// items[range::all()] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// items(range::start_at(2)) = [3, 4, 5, 6, 7, 8, 9, 10]
// items[range::start_at(index::from_end(8))] = [3, 4, 5, 6, 7, 8, 9, 10]
// items[range::start_at(~8_i)] = [3, 4, 5, 6, 7, 8, 9, 10]
// items[range::end_at(6)] = [1, 2, 3, 4, 5, 6]
// items[range::end_at(index::from_start(6))] = [1, 2, 3, 4, 5, 6]
// items(range::end_at(~4_i)) = [1, 2, 3, 4, 5, 6]
// items(range {2, 6}) = [3, 4, 5, 6]
// items(range {3_i, ~2_i}) = [4, 5, 6, 7, 8]
// items({0, 8}) = [1, 2, 3, 4, 5, 6, 7, 8]
// items({1_i, ~4_i}) = [2, 3, 4, 5, 6]


#include <xtd/xtd>

auto main() -> int {
  auto items = list {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  
  xtd::println("items[xtd::index::from_start(0)] = {}", items[xtd::index::from_start(0)]);
  xtd::println("items(xtd::index {{1, false}}) = {}", items(xtd::index {1, false}));
  xtd::println("items[xtd::index {{2}}] = {}", items[xtd::index {2}]);
  xtd::println("items(xtd::index {{~3, true}}) = {}", items(xtd::index {~3, true}));
  xtd::println("items[xtd::index {{4}}] = {}", items[xtd::index {4}]);
  xtd::println("items(xtd::index {{5}}) = {}", items(xtd::index {5}));
  xtd::println("items[xtd::index {{6}}] = {}", items[xtd::index {6}]);
  xtd::println("items(xtd::index {{7}}) = {}", items(xtd::index {7}));
  xtd::println("items[xtd::index {{8}}] = {}", items[xtd::index {8}]);
  xtd::println("items(xtd::index::from_start(9)) = {}", items(xtd::index::from_start(9)));
  xtd::println();
  xtd::println("items[xtd::index::from_end(1)] = {}", items[xtd::index::from_end(1)]);
  xtd::println("items(xtd::index {{2}}, true)) = {}", items(xtd::index {2, true}));
  xtd::println("items[xtd::index {{~3}}] = {}", items[xtd::index {~3}]);
  xtd::println("items(xtd::index {{~4, false}}) = {}", items(xtd::index {~4, false}));
  xtd::println("items[xtd::index {{~5}}] = {}", items[xtd::index {~5}]);
  xtd::println("items(xtd::index {{~6}}) = {}", items(xtd::index {~6}));
  xtd::println("items[xtd::index {{~7}}] = {}", items[xtd::index {~7}]);
  xtd::println("items(xtd::index {{~8}}) = {}", items(xtd::index {~8}));
  xtd::println("items[xtd::index {{~9}}] = {}", items[xtd::index {~9}]);
  xtd::println("items(xtd::index::from_end(10)) = {}", items(xtd::index::from_end(10)));
}

// This code produces the following output :
//
// items[xtd::index::from_start(0)] = 1
// items(xtd::index {1, false}) = 2
// items[xtd::index {2}] = 3
// items(xtd::index {~3, true}) = 4
// items[xtd::index {4}] = 5
// items(xtd::index {5}) = 6
// items[xtd::index {6}] = 7
// items(xtd::index {7}) = 8
// items[xtd::index {8}] = 9
// items(xtd::index::from_start(9)) = 10

//
// items[xtd::index::from_end(1)] = 10
// items(xtd::index {2, true}) = 9
// items[xtd::index {~3}] = 8
// items(xtd::index {~4, false}) = 7
// items[xtd::index {~5}] = 6
// items(xtd::index {~6}) = 5
// items[xtd::index {~7}] = 4
// items(xtd::index {~8}) = 3
// items[xtd::index {~9}] = 2
// items(xtd::index::from_end(10)) = 1

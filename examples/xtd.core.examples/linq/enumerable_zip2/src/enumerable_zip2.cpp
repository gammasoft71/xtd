#include <xtd/xtd>

auto main() -> int {
  auto numbers = array {1, 2, 3, 4, 5};
  auto words = array {"One", "Two", "Three", "Four", "Five"};
  
  auto numbers_and_words = numbers.zip(words, _1 + " "_s + _2);
  
  for (auto&& item : numbers_and_words)
    println(item);
}

// This code produces the following output:
//
// 1 One
// 2 Two
// 3 Three
// 4 Four
// 5 Five

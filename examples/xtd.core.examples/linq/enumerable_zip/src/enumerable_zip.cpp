#include <xtd/xtd>

auto main() -> int {
  auto numbers = array {1, 2, 3, 4, 5};
  auto words = array {"One", "Two", "Three", "Four", "Five"};
  
  auto numbers_and_words = numbers.zip(words);
  
  for (auto&& [number, word] : numbers_and_words)
    println("number = {}, word = {}", number, word);
}

// This code produces the following output:
//
// number = 1, word = One
// number = 2, word = Two
// number = 3, word = Three
// number = 4, word = Four
// number = 5, word = Five

#include <xtd/xtd>

auto main() -> int {
  auto strings = string("One Two Three\tFour\nFive").split();
  
  console::write_line("strings.size = {}", strings.length());
  for (auto string : strings)
    console::write_line(string);
}

// This code produces the following output :
//
// strings.size = 5
// One
// Two
// Three
// Four
// Five

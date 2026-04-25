#include <xtd/xtd>

auto main() -> int {
  auto fruits = array<string> {"apple", "passionfruit", "banana", "mango", "orange", "blueberry", "grape", "strawberry"};
  
  auto lengths = fruits.select<usize>(_*method(&string::length)).to_list();
  
  for (auto length : lengths)
    console::write_line(length);
}

// This code produces the following output :
//
// 5
// 12
// 6
// 5
// 6
// 9
// 5
// 10

#include <xtd/xtd>

auto main() -> int {
  auto fruits = array<string> {"apple", "passionfruit", "banana", "mango", "orange", "blueberry", "grape", "strawberry"};
  
  auto query = fruits.where(_*method(&string::length) < 6);
  
  for (const auto& fruit : query)
    console::write_line(fruit);
}

// This code produces the following output :
//
// apple
// mango
// grape

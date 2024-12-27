#include <xtd/xtd>

using namespace xtd;
using namespace xtd::collections::generic;

auto main() -> int {
  array<string> fruits = {"apple", "passionfruit", "banana", "mango", "orange", "blueberry", "grape", "strawberry"};
  
  const ienumerable<string>& query = fruits.where([](const string& fruit) {return fruit.length() < 6;});
  
  for (const auto& fruit : query)
    console::write_line(fruit);
}

// This code produces the following output :
//
// apple
// mango
// grape

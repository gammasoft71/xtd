#include <xtd/xtd>

using namespace xtd;

auto main() -> int {
  auto fruits = array {"apple", "passionfruit", "banana", "mango", "orange", "blueberry", "grape", "strawberry"};
  
  auto query = fruits.where([](const string& fruit) {return fruit.length() < 6;});
  
  for (const auto& fruit : query)
    console::write_line(fruit);
}

// This code produces the following output :
//
// apple
// mango
// grape

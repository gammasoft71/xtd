#include <xtd/xtd>

using namespace xtd;
using namespace xtd::collections::generic;

auto main() -> int {
  auto fruits = array {"apple", "banana", "mango", "orange", "passionfruit", "grape"};
  
  auto number_of_fruits = fruits.enumerable::count();
  console::write_line("There are {0} fruits in the collection.", number_of_fruits);
}

// This code produces the following output :
//
// There are 6 fruits in the collection.

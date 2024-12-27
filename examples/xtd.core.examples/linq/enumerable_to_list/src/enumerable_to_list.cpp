#include <xtd/collections/generic/list>
#include <xtd/console>

using namespace xtd;
using namespace xtd::collections::generic;

auto main() -> int {
  array<string> fruits = {"apple", "passionfruit", "banana", "mango", "orange", "blueberry", "grape", "strawberry"};
  
  list<size_t> lengths = fruits.select<size_t>([](const string& fruit) {return fruit.length();}).to_list();
  
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

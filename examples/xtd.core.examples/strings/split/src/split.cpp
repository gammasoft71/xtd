#include <xtd/console>
#include <xtd/ustring>

using namespace xtd;

auto main() -> int {
  auto strings = ustring("One Two Three\tFour\nFive").split();
  
  console::write_line("strings.size = {}", strings.size());
  for (auto string : strings)
    console::write_line(string);
}

// This code produces the following output:
//
// strings.size = 5
// One
// Two
// Three
// Four
// Five

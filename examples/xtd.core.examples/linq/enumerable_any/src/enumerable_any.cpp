#include <xtd/collections/generic/list>
#include <xtd/console>

using namespace xtd;
using namespace xtd::collections::generic;

auto main() -> int {
  auto numbers = list {1, 2};
  auto has_elements = numbers.any();
  
  console::write_line("The list {0} empty.", has_elements ? "is not" : "is");
}

// This code produces the following output :
//
// The list is not empty.

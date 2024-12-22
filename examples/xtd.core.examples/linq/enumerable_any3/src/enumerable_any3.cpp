#include <xtd/collections/generic/list>
#include <xtd/linq/enumerable>
#include <xtd/console>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::linq;

auto main() -> int {
  auto numbers = list {1, 2};
  auto has_elements = enumerable::any<int>(numbers.begin(), numbers.end());
  
  console::write_line("The list {0} empty.", has_elements ? "is not" : "is");
}

// This code produces the following output :
//
// The list is not empty.

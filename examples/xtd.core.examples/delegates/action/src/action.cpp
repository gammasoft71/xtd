#include <xtd/collections/generic/list>
#include <xtd/action>
#include <xtd/console>
#include <algorithm>

using namespace xtd;
using namespace xtd::collections::generic;

auto main() -> int {
  auto names = list {"Bruce", "Alfred", "Tim", "Richard"};
  
  auto print = action<const ustring&> {[](const ustring & value) {
    console::write_line(value);
  }};
  
  // Display the contents of the list using the print delegate.
  std::for_each(names.begin(), names.end(), print);
  
  // The following demonstrates the lambda of c++ to display the contents of the list to the console.
  std::for_each(names.begin(), names.end(), [](const ustring & value) {
    console::write_line(value);
  });
}

// This code produces the following output:
//
// Bruce
// Alfred
// Tim
// Richard
// Bruce
// Alfred
// Tim
// Richard

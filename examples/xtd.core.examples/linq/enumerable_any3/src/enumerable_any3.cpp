#include <xtd/xtd>

auto main() -> int {
  auto numbers = list {1, 2};
  auto has_elements = enumerable::from(numbers.begin(), numbers.end()).any();
  
  console::write_line("The list {0} empty.", has_elements ? "is not" : "is");
}

// This code produces the following output :
//
// The list is not empty.

#include <xtd/collections/generic/list>
#include <xtd/console>

using namespace xtd;
using namespace xtd::collections::generic;

auto main() -> int {
  // Creating a list of numbers
  auto numbers = list {1, 2, 3, 4};
  
  // Trying to append any value of the same type
  numbers.append(5);
  
  // It doesn't work because the original list has not been changed
  console::write_line(string::join(", ", numbers));
  
  // It works now because we are using a changed copy of the original list
  console::write_line(string::join(", ", numbers.append(5)));
  
  // If you prefer, you can create a new list explicitly
  auto new_numbers = numbers.append(5).to_list();
  
  // And then write to the console output
  console::write_line(string::join(", ", new_numbers));
}

// This code produces the following output :
//
// 1, 2, 3, 4
// 1, 2, 3, 4, 5
// 1, 2, 3, 4, 5

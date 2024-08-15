#include <xtd/block_scope>
#include <xtd/console>
#include <xtd/environment>

using namespace xtd;

auto main() -> int {
  block_scope_(auto values = {1, 2, 3, 4, 5})
    console::write_line(string::join(", ", values));
  
  // uncomment next line cause build error with undeclared identifier 'values'.
  // console::out << string::join(", ", values) << environment::new_line;
}

// This code produces the following output :
//
// 1, 2, 3, 4, 5

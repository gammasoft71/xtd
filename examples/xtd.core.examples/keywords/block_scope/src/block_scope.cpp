#include <xtd/block_scope>
#include <xtd/console>

using namespace xtd;

auto main() -> int {
  block_scope_(auto values = {1, 2, 3, 4, 5})
    console::write_line(ustring::join(", ", values));
  
  // uncomment next line cause build error with undeclared identifier 'values'.
  // cout << ustring::join(", ", values) << endl;
}

// This code produces the following output:
//
// 1, 2, 3, 4, 5

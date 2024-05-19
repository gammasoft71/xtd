#include <xtd/console>
#include <xtd/using>

using namespace xtd;

auto main() -> int {
  using_(auto values = {1, 2, 3, 4, 5})
    console::write_line(ustring::join(", ", values));
  
  // uncomment next line cause build error with undeclared identifier 'values'.
  // cout << ustring::join(", ", values) << endl;
}

// This code produces the following output:
//
// 1, 2, 3, 4, 5

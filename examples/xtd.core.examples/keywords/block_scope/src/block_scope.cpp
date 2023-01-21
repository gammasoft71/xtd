#include <xtd/xtd>

using namespace std;
using namespace xtd;

auto main()->int {
  block_scope_(auto values = {1, 2, 3, 4, 5})
    cout << ustring::join(", ", values) << endl;
  
  // uncomment next line cause build error with undeclared identifier 'values'.
  // cout << ustring::join(", ", values) << endl;
}

// This code produces the following output:
//
// 1, 2, 3, 4, 5

#include <xtd/literals>
#include <xtd/ustring>
#include <iostream>

using namespace std;
using namespace xtd;

auto main() -> int {
  cout << ustring::format("{0,10} {1} {2:D3} {3}", "string"_s, "literal", 42, 'a') << endl;
}

// This code produces the following output:
//
//     string literal 042 a

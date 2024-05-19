#include <xtd/ustring>
#include <xtd/literals>

using namespace std;
using namespace xtd;

auto main() -> int {
  cout << ustring::format("{0} {1} {2:D} {3} {0}", "string", "literal"_s, 42, 'a') << endl;
}

// This code produces the following output :
//
// string literal 42 a string

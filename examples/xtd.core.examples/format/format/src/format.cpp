#include <xtd/literals>
#include <xtd/ustring>

using namespace std;
using namespace xtd;

auto main() -> int {
  cout << ustring::format("{} {} {} {}", "string", "literal"_s, 42, 'a') << endl;
}

// This code produces the following output :
//
// string literal 42 a

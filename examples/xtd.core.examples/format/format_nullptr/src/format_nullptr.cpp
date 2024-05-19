#include <xtd/ustring>

using namespace std;
using namespace xtd;

auto main() -> int {
  cout << ustring::format("{}", nullptr) << endl;
  cout << ustring::format("{}", null) << endl;
  cout << ustring::format("{}", NULL) << endl;
  cout << ustring::format("{}", 0) << endl;
}

// This code produces the following output :
//
// nullptr
// nullptr
// 0
// 0

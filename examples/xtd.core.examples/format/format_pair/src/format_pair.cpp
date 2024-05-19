#include <xtd/ustring>
#include <utility>

using namespace std;
using namespace xtd;

auto main() -> int {
  cout << ustring::format("{}", make_pair(1, "one")) << endl;
}

// This code produces the following output :
//
// (1, one)

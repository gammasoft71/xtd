#include <xtd/ustring>

using namespace std;
using namespace xtd;

auto main() -> int {
  cout << ustring::format("[{,10}]", 42) << endl;
  cout << ustring::format("[{,-10}]", 42) << endl;
  cout << ustring::format("[{:D10}]", 42) << endl;
}

// This code produces the following output :
//
// [        42]
// [42        ]
// [0000000042]

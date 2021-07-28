#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << ustring::format("[{,10}]", 42) << endl;
  cout << ustring::format("[{,-10}]", 42) << endl;
  cout << ustring::format("[{:D10}]", 42) << endl;
}

// This code produces the following output :
//
// [        42]
// [42        ]
// [0000000042]

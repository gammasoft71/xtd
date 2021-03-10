#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << format("[{,10}]", 42) << endl;
  cout << format("[{,-10}]", 42) << endl;
  cout << format("[{:D10}]", 42) << endl;
}

// This code produces the following output :
//
// [        42]
// [42        ]
// [0000000042]

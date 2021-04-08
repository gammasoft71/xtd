#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << strings::formatf("%i", 42) << endl;
  cout << strings::formatf("%u", 42u) << endl;
  cout << strings::formatf("%d", 42) << endl;
  cout << strings::formatf("0%o", 42) << endl;
  cout << strings::formatf("0x%04x", 42) << endl;
  cout << strings::formatf("0x%04X", 42) << endl;
}

// This code produces the following output :
//
// 42
// 42
// 42
// 052
// 0x002a
// 0x002A

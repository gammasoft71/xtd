#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  locale::global(locale("en_US.UTF-8")); // change to us for currency
  cout << formatf("%i", 42) << endl;
  cout << formatf("%u", 42u) << endl;
  cout << formatf("%d", 42) << endl;
  cout << formatf("0%o", 42) << endl;
  cout << formatf("0x%04x", 42) << endl;
  cout << formatf("0x%04X", 42) << endl;
}

// This code produces the following output :
//
// 42
// 42
// 42
// 052
// 0x002a
// 0x002A

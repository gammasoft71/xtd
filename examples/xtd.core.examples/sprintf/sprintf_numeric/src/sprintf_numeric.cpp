#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << strings::sprintf("%i", 42) << endl;
  cout << strings::sprintf("%u", 42u) << endl;
  cout << strings::sprintf("%d", 42) << endl;
  cout << strings::sprintf("0%o", 42) << endl;
  cout << strings::sprintf("0x%04x", 42) << endl;
  cout << strings::sprintf("0x%04X", 42) << endl;
}

// This code produces the following output :
//
// 42
// 42
// 42
// 052
// 0x002a
// 0x002A

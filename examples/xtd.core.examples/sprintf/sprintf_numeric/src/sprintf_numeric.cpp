#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << ustring::sprintf("%i", 42) << endl;
  cout << ustring::sprintf("%u", 42u) << endl;
  cout << ustring::sprintf("%d", 42) << endl;
  cout << ustring::sprintf("0%o", 42) << endl;
  cout << ustring::sprintf("0x%04x", 42) << endl;
  cout << ustring::sprintf("0x%04X", 42) << endl;
}

// This code produces the following output :
//
// 42
// 42
// 42
// 052
// 0x002a
// 0x002A

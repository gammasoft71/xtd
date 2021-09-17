#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << ustring::sprintf("%d", true) << endl;
  cout << ustring::sprintf("%o", true) << endl;
  cout << ustring::sprintf("%x", true) << endl;
  cout << ustring::sprintf("%X", true) << endl;
}

// This code produces the following output :
//
// 1
// 1
// 1
// 1

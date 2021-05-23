#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << strings::sprintf("%d", true) << endl;
  cout << strings::sprintf("%o", true) << endl;
  cout << strings::sprintf("%x", true) << endl;
  cout << strings::sprintf("%X", true) << endl;
}

// This code produces the following output :
//
// 1
// 1
// 1
// 1

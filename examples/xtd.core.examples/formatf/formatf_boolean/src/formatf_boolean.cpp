#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << strings::formatf("%d", true) << endl;
  cout << strings::formatf("%o", true) << endl;
  cout << strings::formatf("%x", true) << endl;
  cout << strings::formatf("%X", true) << endl;
}

// This code produces the following output :
//
// 1
// 1
// 1
// 1

#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << formatf("%d", true) << endl;
  cout << formatf("%o", true) << endl;
  cout << formatf("%x", true) << endl;
  cout << formatf("%X", true) << endl;
}

// This code produces the following output :
//
// 1
// 1
// 1
// 1

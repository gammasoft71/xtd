#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << strings::format("{}", nullptr) << endl;
  cout << strings::format("{}", null) << endl;
  cout << strings::format("{}", NULL) << endl;
  cout << strings::format("{}", 0) << endl;
}

// This code produces the following output :
//
// nullptr
// nullptr
// 0
// 0

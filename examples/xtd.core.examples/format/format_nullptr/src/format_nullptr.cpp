#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << format("{}", nullptr) << endl;
  cout << format("{}", null) << endl;
  cout << format("{}", NULL) << endl;
  cout << format("{}", 0) << endl;
}

// This code produces the following output :
//
// nullptr
// nullptr
// 0
// 0

#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << strings::format("{}", true) << endl;
  cout << strings::format("{:b}", true) << endl;
  cout << strings::format("{:B}", true) << endl;
  cout << strings::format("{:d}", true) << endl;
  cout << strings::format("{:D}", true) << endl;
  cout << strings::format("{:g}", true) << endl;
  cout << strings::format("{:G}", true) << endl;
  cout << strings::format("{:o}", true) << endl;
  cout << strings::format("{:O}", true) << endl;
  cout << strings::format("{:x}", true) << endl;
  cout << strings::format("{:X}", true) << endl;
}

// This code produces the following output :
//
// true
// 1
// 1
// 1
// 1
// true
// true
// 1
// 1
// 1
// 1

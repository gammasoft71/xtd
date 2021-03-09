#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << format("{}", true) << endl;
  cout << format("{:b}", true) << endl;
  cout << format("{:b}", true) << endl;
  cout << format("{:d}", true) << endl;
  cout << format("{:D}", true) << endl;
  cout << format("{:g}", true) << endl;
  cout << format("{:G}", true) << endl;
  cout << format("{:o}", true) << endl;
  cout << format("{:O}", true) << endl;
  cout << format("{:x}", true) << endl;
  cout << format("{:X}", true) << endl;
}

// This code produces the following output with colors :
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

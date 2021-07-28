#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << ustring::format("{}", true) << endl;
  cout << ustring::format("{:b}", true) << endl;
  cout << ustring::format("{:B}", true) << endl;
  cout << ustring::format("{:d}", true) << endl;
  cout << ustring::format("{:D}", true) << endl;
  cout << ustring::format("{:g}", true) << endl;
  cout << ustring::format("{:G}", true) << endl;
  cout << ustring::format("{:o}", true) << endl;
  cout << ustring::format("{:O}", true) << endl;
  cout << ustring::format("{:x}", true) << endl;
  cout << ustring::format("{:X}", true) << endl;
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

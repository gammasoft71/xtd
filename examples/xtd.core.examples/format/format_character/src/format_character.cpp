#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << ustring::format("{}", 'a') << endl;
  cout << ustring::format("{}", L'\u4eb0') << endl;
  cout << ustring::format("{}", u8'a') << endl;
  cout << ustring::format("{}", u'\u4eb0') << endl;
  cout << ustring::format("{}", U'\U0001F428') << endl;
}

// This code produces the following output :
//
// a
// 亰
// a
// 亰
// 🐨

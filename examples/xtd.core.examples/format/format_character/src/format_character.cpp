#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << strings::format("{}", 'a') << endl;
  cout << strings::format("{}", L'\u4eb0') << endl;
  cout << strings::format("{}", u8'a') << endl;
  cout << strings::format("{}", u'\u4eb0') << endl;
  cout << strings::format("{}", U'\U0001F428') << endl;
}

// This code produces the following output :
//
// a
// 亰
// a
// 亰
// 🐨

#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << format("{}", 'a') << endl;
  cout << format("{}", L'\u4eb0') << endl;
  cout << format("{}", u8'a') << endl;
  cout << format("{}", u'\u4eb0') << endl;
  cout << format("{}", U'\U0001F428') << endl;
}

// This code produces the following output :
//
// a
// 亰
// a
// 亰
// 🐨

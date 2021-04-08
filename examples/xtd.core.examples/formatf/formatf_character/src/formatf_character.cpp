#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << strings::formatf("%c", 'a') << endl;
  //cout << strings::formatf("%c", L'\u4eb0') << endl; // Does not work
  cout << strings::formatf("%c", u8'a') << endl;
  //cout << strings::formatf("%c", u'\u4eb0') << endl; // Does not work
  //cout << strings::formatf("%c", U'\U0001F428') << endl; // Does not work
}

// This code produces the following output :
//
// a
// a

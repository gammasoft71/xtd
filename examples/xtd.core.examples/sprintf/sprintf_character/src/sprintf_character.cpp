#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << strings::sprintf("%c", 'a') << endl;
  //cout << strings::sprintf("%c", L'\u4eb0') << endl; // Does not work
  cout << strings::sprintf("%c", u8'a') << endl;
  //cout << strings::sprintf("%c", u'\u4eb0') << endl; // Does not work
  //cout << strings::sprintf("%c", U'\U0001F428') << endl; // Does not work
}

// This code produces the following output :
//
// a
// a

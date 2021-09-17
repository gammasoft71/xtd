#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << ustring::sprintf("%c", 'a') << endl;
  //cout << ustring::sprintf("%c", L'\u4eb0') << endl; // Does not work
  cout << ustring::sprintf("%c", u8'a') << endl;
  //cout << ustring::sprintf("%c", u'\u4eb0') << endl; // Does not work
  //cout << ustring::sprintf("%c", U'\U0001F428') << endl; // Does not work
}

// This code produces the following output :
//
// a
// a

#include <xtd/ustring>

using namespace std;
using namespace xtd;

auto main() -> int {
  cout << ustring::sprintf("%c", 'a') << endl;
  //cout << ustring::sprintf("%c", L'\u4eb0') << endl; // Does not work correctly
  cout << ustring::sprintf("%c", u8'a') << endl;
  //cout << ustring::sprintf("%c", u'\u4eb0') << endl; // Does not work correctly
  //cout << ustring::sprintf("%c", U'\U0001F428') << endl; // Does not work correctly
}
  
  // This code produces the following output :
  //
  // a
  // a
  

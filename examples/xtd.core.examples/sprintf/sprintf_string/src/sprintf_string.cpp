#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << ustring::sprintf("%s", "string") << endl;
  cout << ustring::sprintf("%s", u8"u8string") << endl;
  cout << ustring::sprintf("%s", string {"string"}) << endl;
  cout << ustring::sprintf("%s", ustring {"ustring"}) << endl;
  cout << ustring::sprintf("%s", u8string {u8"u8string"}) << endl;
}

// This code produces the following output :
//
// string
// u8string
// string
// ustring
// u8string

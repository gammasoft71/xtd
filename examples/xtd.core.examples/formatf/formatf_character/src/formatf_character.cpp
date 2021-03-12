#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << formatf("%c", 'a') << endl;
  //cout << formatf("%c", L'\u4eb0') << endl; // Does not work
  cout << formatf("%c", u8'a') << endl;
  //cout << formatf("%c", u'\u4eb0') << endl; // Does not work
  //cout << formatf("%c", U'\U0001F428') << endl; // Does not work
}

// This code produces the following output :
//
// a
// a

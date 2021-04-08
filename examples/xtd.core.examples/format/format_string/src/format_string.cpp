#include <xtd/xtd>

using namespace std;
using namespace std::literals;
using namespace xtd;

int main() {
  cout << strings::format("{}", "string") << endl;
  cout << strings::format("{}", u8"string") << endl;
  cout << strings::format("{}", L"string") << endl;
  cout << strings::format("{}", u"string") << endl;
  cout << strings::format("{}", U"string") << endl;
  cout << strings::format("{}", "string"s) << endl;
  cout << strings::format("{}", u8"string"s) << endl;
  cout << strings::format("{}", L"string"s) << endl;
  cout << strings::format("{}", u"string"s) << endl;
  cout << strings::format("{}", U"string"s) << endl;
  cout << strings::format("{:anything}", "string") << endl;
}

// This code produces the following output :
//
// string
// string
// string
// string
// string
// string
// string
// string
// string
// string
// string

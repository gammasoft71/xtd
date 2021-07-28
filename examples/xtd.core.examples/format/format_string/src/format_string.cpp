#include <xtd/xtd>

using namespace std;
using namespace std::literals;
using namespace xtd;

int main() {
  cout << ustring::format("{}", "string") << endl;
  cout << ustring::format("{}", u8"string") << endl;
  cout << ustring::format("{}", L"string") << endl;
  cout << ustring::format("{}", u"string") << endl;
  cout << ustring::format("{}", U"string") << endl;
  cout << ustring::format("{}", "string"s) << endl;
  cout << ustring::format("{}", u8"string"s) << endl;
  cout << ustring::format("{}", L"string"s) << endl;
  cout << ustring::format("{}", u"string"s) << endl;
  cout << ustring::format("{}", U"string"s) << endl;
  cout << ustring::format("{:anything}", "string") << endl;
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

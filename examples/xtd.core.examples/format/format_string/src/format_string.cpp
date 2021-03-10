#include <xtd/xtd>

using namespace std;
using namespace std::literals;
using namespace xtd;

int main() {
  cout << format("{}", "string") << endl;
  cout << format("{}", u8"string") << endl;
  cout << format("{}", L"string") << endl;
  cout << format("{}", u"string") << endl;
  cout << format("{}", U"string") << endl;
  cout << format("{}", "string"s) << endl;
  cout << format("{}", u8"string"s) << endl;
  cout << format("{}", L"string"s) << endl;
  cout << format("{}", u"string"s) << endl;
  cout << format("{}", U"string"s) << endl;
  cout << format("{:anything}", "string") << endl;
}

// This code produces the following output :
//
// string
// string

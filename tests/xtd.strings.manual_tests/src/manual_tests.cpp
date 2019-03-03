#include <xtd/strings>

#include <iostream>
#include <vector>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::string_literals;

inline std::string const& to_string(std::string const& s) { return s; }

// The main entry point for the application.
int main() {
  istring str = "My immutable string"_is;
  istring str2 = "My immutable string"_is;
  istring s2 = "Hello, ";
  istring s3 = "World!";
  s2 = s2 + s3;
  cout << s2 << endl;
  cout << strings::replace(str, 'm', 'z') << endl;
  //cout << str == str2 << endl;
}

// This code produces the following output with colors:
//
// Hello, World!

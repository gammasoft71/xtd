#include <xtd/strings>

#include <iostream>
#include <vector>

using namespace std;
using namespace string_literals;
using namespace xtd;

inline std::string const& to_string(std::string const& s) { return s; }

// The main entry point for the application.
int main() {
  istring str = "My immutable string"_is;
  istring s2 = "Hello, ";
  istring s3 = "World!";
  s2 += s3;
  cout << s2 << endl;
  cout << strings::replace(str, 'm', 'z') << endl;
}

// This code produces the following output with colors:
//
// Hello, World!

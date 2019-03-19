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
  auto s = L"Hello, World!"_is;
  s = s + L"\n";
  wcout << s;
}

// This code produces the following output with colors:
//
// Hello, World!

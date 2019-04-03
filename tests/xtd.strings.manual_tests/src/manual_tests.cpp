#include <xtd/strings>

#include <bitset>
#include <iostream>
#include <vector>
#include <codecvt>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::string_literals;

// The main entry point for the application.
int main() {
  std::locale::global(std::locale("en_US.UTF-8"));
  //cout << std::stoll("(42)") << endl;
  cout << xtd::parse<int>("42+", xtd::number_styles::integer | xtd::number_styles::allow_parentheses | xtd::number_styles::allow_trailing_sign) << endl;
}

// This code produces the following output:
//
// Hello, World!

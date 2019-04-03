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
  cout << std::stold("4.2.1") << endl;
  cout << xtd::parse<int>("4.2.1", xtd::number_styles::number) << endl;
}

// This code produces the following output:
//
// Hello, World!

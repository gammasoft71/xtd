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
  cout << xtd::to_string(42, "C") << endl;
  cout << xtd::to_string(42, "C", std::locale("en_US")) << endl;
  cout << xtd::to_string(42, "C", std::locale("fr_FR.UTF-8")) << endl;
  cout << xtd::to_string(42, "C", std::locale("fr_CA.UTF-8")) << endl;
  cout << xtd::to_string(42, "C", std::locale("ja_JP.UTF-8")) << endl;
}

// This code produces the following output:
//
// Hello, World!

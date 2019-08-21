#include <xtd/xtd.strings>
#include <iostream>

using namespace std;
using namespace std::string_literals;
using namespace xtd;

// The main entry point for the application.
int main() {
  cout << format("{}, {}!", "Hello", "World"s) << endl;
}

// This code produces the following output:
//
// Hello, World!

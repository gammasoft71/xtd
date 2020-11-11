#include <xtd/xtd.strings>
#include <iostream>

using namespace std;
using namespace string_literals;
using namespace xtd;

// The main entry point for the application.
int main() {
  cout << strings::concat("Hello", ", ", "World", "!") << endl;
}

// This code produces the following output:
//
// Hello, World!

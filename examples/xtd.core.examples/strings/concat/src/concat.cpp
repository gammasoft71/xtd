#include <xtd/xtd>
#include <iostream>

using namespace std;
using namespace string_literals;
using namespace xtd;

int main() {
  cout << strings::concat("Hello", ", ", "World", "!") << endl;
}

// This code produces the following output:
//
// Hello, World!

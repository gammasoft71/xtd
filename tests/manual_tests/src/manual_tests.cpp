#include <xtd/strings>

#include <iostream>

using namespace std;
using namespace string_literals;
using namespace xtd;

// The main entry point for the application.
int main() {
  cout << strings::format("%s, %s!", "Hello", "World"s) << endl;
}

// This code produces the following output with colors:
//
// Hello, World!

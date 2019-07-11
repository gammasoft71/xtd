#include <xtd/xtd.strings>

#include <iostream>

using namespace std;
using namespace std::chrono_literals;

// The main entry point for the application.
int main() {
  //cout << "Hello, World!" << endl;

  char32_t a = 'a';
  cout << xtd::strings::format("'{}'", a) << endl;
}

// This code produces the following output:
//
// Hello, World!

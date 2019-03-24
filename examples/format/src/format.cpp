#include <xtd/strings>
#include <iostream>

using namespace std;
using namespace string_literals;
using namespace xtd;

// The main entry point for the application.
int main() {
  cout << strings::format("{0,10} {1} {2:D3} {3}", "string", "literal"s, 42, 'a') << endl;
}

// This code produces the following output:
//
//     string literal 042 a

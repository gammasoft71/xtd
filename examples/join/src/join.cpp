#include <xtd/xtd.strings>
#include <iostream>

using namespace std;
using namespace xtd;

// The main entry point for the application.
int main() {
  string strings = strings::join(", ", {"One", "Two", "Three", "Four", "Five"});
  cout << strings << endl;
}

// This code produces the following output:
//
// One, Two, Three, Four, Five

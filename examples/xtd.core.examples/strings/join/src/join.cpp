#include <xtd/xtd>
#include <iostream>

using namespace std;
using namespace xtd;

int main() {
  ustring strings = ustring::join(", ", {"One", "Two", "Three", "Four", "Five"});
  cout << strings << endl;
}

// This code produces the following output:
//
// One, Two, Three, Four, Five

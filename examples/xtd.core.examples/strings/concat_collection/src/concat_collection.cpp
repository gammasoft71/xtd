#include <xtd/xtd>
#include <iostream>

using namespace std;
using namespace string_literals;
using namespace xtd;

int main() {
  vector items = {"One ", "Two ", "Three ", "Four "};
  cout << ustring::concat(items) << endl;
}

// This code produces the following output:
//
// One Two Three Four 

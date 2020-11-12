#include <xtd/xtd.core>
#include <iostream>

using namespace std;
using namespace string_literals;
using namespace xtd;

// The main entry point for the application.
int main() {
  int result = strings::compare("Aaa", "aaa", true);
  if (result < 0)
    cout << "Aaa < aaa" << endl;
  else if (result > 0)
    cout << "Aaa > aaa" << endl;
  else
    cout << "Aaa == aaa" << endl;
}

// This code produces the following output:
//
// Aaa == aaa

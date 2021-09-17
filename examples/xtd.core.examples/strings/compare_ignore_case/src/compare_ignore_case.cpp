#include <xtd/xtd>
#include <iostream>

using namespace std;
using namespace string_literals;
using namespace xtd;

int main() {
  int result = ustring::compare("Aaa", "aaa", true);
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

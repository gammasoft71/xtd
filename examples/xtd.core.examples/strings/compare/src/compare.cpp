#include <xtd/xtd>
#include <iostream>

using namespace std;
using namespace string_literals;
using namespace xtd;

int main() {
  int result = ustring::compare("Aaa", "Baa");
  if (result < 0)
    cout << "Aaa < Baa" << endl;
  else if (result > 0)
    cout << "Aaa > Baa" << endl;
  else
    cout << "Aaa == Baa" << endl;
}

// This code produces the following output:
//
// Aaa < Baa

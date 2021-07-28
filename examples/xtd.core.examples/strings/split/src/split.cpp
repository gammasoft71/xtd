#include <xtd/xtd>
#include <iostream>

using namespace std;
using namespace xtd;

int main() {
  vector<ustring> strings = ustring("One Two Three\tFour\nFive").split();
  
  cout << "strings.size = " << strings.size() << endl;
  for (auto s : strings)
    cout << s << endl;
}

// This code produces the following output:
//
// strings.size = 5
// One
// Two
// Three
// Four
// Five

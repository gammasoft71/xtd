#include <xtd/xtd>
#include <iostream>

using namespace std;
using namespace xtd;

int main() {
  vector<string> strings = ustring::split("One Two Three\tFour\nFive");
  
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

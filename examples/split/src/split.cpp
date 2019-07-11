#include <xtd/xtd.strings>
#include <iostream>

using namespace std;
using namespace xtd;

// The main entry point for the application.
int main() {
  vector<string> strings = strings::split("One Two Three\tFour\nFive");
  
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

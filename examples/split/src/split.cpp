#include <xtd/strings>
#include <iostream>

using namespace std;
using namespace xtd;

// The main entry point for the application.
int main() {
  vector<string> strings = strings::split("One Two Three Four\nFive");
  
  cout << "strings::Length = " << strings.size() << endl;
  for (auto s : strings)
    cout << s << endl;
}

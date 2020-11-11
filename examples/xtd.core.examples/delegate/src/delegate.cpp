#include <xtd/xtd.delegates>
#include <iostream>
#include <string>

using namespace std;
using namespace xtd;

int main() {
  delegate<void(const string& str)> write_line;
  
  write_line += [](const string& str)  {
    cout << str << endl;
  };
  
  write_line += [](auto str)  {
    cerr << str << endl;
  };
  
  write_line("Hello, world!");
}

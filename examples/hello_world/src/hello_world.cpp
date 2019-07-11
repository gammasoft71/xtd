#include <xtd/xtd.delegates>
#include <iostream>
#include <string>

using namespace std;
using namespace xtd;

// The main entry point for the application.
int main() {
  delegate<void(string str)> write_line;
  
  write_line += [&](string str)  {
    cout << str << endl;
  };
  
  write_line += [&](string str)  {
    cerr << str << endl;
  };
  
  write_line("Hello, world!");
}

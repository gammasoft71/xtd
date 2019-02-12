#include <xtd/delegates>
#include <iostream>

using namespace std;
using namespace xtd;

// The main entry point for the application.
int main() {
  delegate<void(const string& str)> write_line;
  
  write_line += [&](const string& str)  {
    cout << "cout: " << str << endl;
  };
  
  write_line += [&](const string& str)  {
    cerr << "cerr: " << str << endl;
  };
  
  write_line("Hello, World!");
}

// This code produces the following output :
//
// cout: Hello, World!
// cerr: Hello, World!



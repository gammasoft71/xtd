#include <xtd/xtd.core>
#include <iostream>
#include <string>

using namespace std;
using namespace xtd;

int main() {
  // use delegate as std::function
  delegate<void(const string& str)> writer([](const string& str)  {
    cout << str << endl;
  });
  
  writer("Value to write");
}

// This code produces the following output:
//
// Hello, World!

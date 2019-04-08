#include <xtd/strings>

#include <iostream>

using namespace std;
using namespace std::chrono_literals;

// The main entry point for the application.
int main() {
  //cout << "Hello, World!" << endl;

  cout << xtd::strings::format(" : {}", 2h + 3min + 32s) << endl;
  cout << xtd::strings::format("c: {:c}", 2h + 3min + 32s) << endl;
  cout << xtd::strings::format("f: {:f}", 2h + 3min + 32s) << endl;
  cout << xtd::strings::format("F: {:F}", 2h + 3min + 32s) << endl;
  cout << xtd::strings::format("g: {:g}", 2h + 3min + 32s) << endl;
  cout << xtd::strings::format("G: {:G}", 2h + 3min + 32s) << endl;

  cout << endl;

  wcout << xtd::strings::format(L" : {}", 26h + 3min + 32s + 24ms + 500ns) << endl;
  wcout << xtd::strings::format(L"c: {:c}", 26h + 3min + 32s + 24ms + 500ns) << endl;
  wcout << xtd::strings::format(L"f: {:f}", 26h + 3min + 32s + 24ms + 500ns) << endl;
  wcout << xtd::strings::format(L"F: {:F}", 26h + 3min + 32s + 24ms + 500ns) << endl;
  wcout << xtd::strings::format(L"g: {:g}", 26h + 3min + 32s + 24ms + 500ns) << endl;
  wcout << xtd::strings::format(L"G: {:G}", 26h + 3min + 32s + 24ms + 500ns) << endl;
}

// This code produces the following output:
//
// Hello, World!

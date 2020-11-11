#include <xtd/xtd.console>
#include <string>

using namespace std;
using namespace xtd;

// The main entry point for the application.
int main() {
  wconsole::write(L"Hello ");
  wconsole::write_line(L"World!");
  wconsole::write(L"Enter your name: ");
  wstring name = wconsole::read_line();
  wconsole::write(L"Good day, ");
  wconsole::write(name);
  wconsole::write_line(L"!");
}

// This code produces the following output:
//
// Hello World!
// Enter your name: James
// Good day, James!

#include <xtd/xtd.core>
#include <string>

using namespace std;
using namespace xtd;

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

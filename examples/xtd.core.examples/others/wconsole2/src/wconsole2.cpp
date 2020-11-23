#include <xtd/xtd>
#include <string>

using namespace std;
using namespace xtd;

int main() {
  wconsole::out << L"Hello ";
  wconsole::out << L"World!" << endl;
  wconsole::out << L"Enter your name: ";
  wstring name;
  wconsole::in >> name;
  wconsole::out << L"Good day, ";
  wconsole::out << name;
  wconsole::out << L"!" << endl;
}

// This code produces the following output:
//
// Hello World!
// Enter your name: James
// Good day, James!

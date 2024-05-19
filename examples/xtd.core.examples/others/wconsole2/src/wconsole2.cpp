#include <xtd/console>

using namespace std;
using namespace xtd;

auto main() -> int {
  console::out << L"Hello ";
  console::out << L"World!" << endl;
  console::out << L"Enter your name: ";
  ustring name;
  console::in >> name;
  console::out << L"Good day, ";
  console::out << name;
  console::out << L"!" << endl;
}

// This code produces the following output:
//
// Hello World!
// Enter your name: James
// Good day, James!

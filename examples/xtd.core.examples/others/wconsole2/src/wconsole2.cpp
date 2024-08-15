#include <xtd/console>
#include <xtd/environment>

using namespace xtd;

auto main() -> int {
  console::out << L"Hello ";
  console::out << L"World!" << environment::new_line;
  console::out << L"Enter your name: ";
  string name;
  console::in >> name;
  console::out << L"Good day, ";
  console::out << name;
  console::out << L"!" << environment::new_line;
}

// This code produces the following output :
//
// Hello World!
// Enter your name: James
// Good day, James!

#include <xtd/console>
#include <xtd/environment>

using namespace xtd;

auto main() -> int {
  console::out << "Hello ";
  console::out << "World!" << environment::new_line;
  console::out << "Enter your name: ";
  string name;
  console::in >> name;
  console::out << "Good day, ";
  console::out << name;
  console::out << "!" << environment::new_line;
}

// This code produces the following output :
//
// Hello World!
// Enter your name: James
// Good day, James!

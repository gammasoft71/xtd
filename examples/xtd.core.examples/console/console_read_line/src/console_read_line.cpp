#include <xtd/xtd>
#include <string>

using namespace xtd;

int main() {
  console::write("Hello ");
  console::write_line("World!");
  console::write("Enter your name: ");
  ustring name = console::read_line();
  console::write("Good day, ");
  console::write(name);
  console::write_line("!");
}

// This code produces the following output:
//
// Hello World!
// Enter your name: James
// Good day, James!

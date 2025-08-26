#include <xtd/xtd>

auto main() -> int {
  console::write(L"Hello ");
  console::write_line(L"World!");
  console::write(L"Enter your name: ");
  string name = console::read_line();
  console::write(L"Good day, ");
  console::write(name);
  console::write_line(L"!");
}

// This code produces the following output :
//
// Hello World!
// Enter your name: James
// Good day, James!

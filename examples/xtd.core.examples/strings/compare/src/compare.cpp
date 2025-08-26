#include <xtd/xtd>

auto main() -> int {
  auto result = string::compare("Aaa", "Baa");
  if (result < 0)
    console::write_line("Aaa < Baa");
  else if (result > 0)
    console::write_line("Aaa > Baa");
  else
    console::write_line("Aaa == Baa");
}

// This code produces the following output :
//
// Aaa < Baa

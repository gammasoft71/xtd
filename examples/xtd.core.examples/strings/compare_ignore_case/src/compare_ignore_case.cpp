#include <xtd/xtd>

auto main() -> int {
  auto result = string::compare("Aaa", "aaa", true);
  if (result < 0)
    console::write_line("Aaa < aaa");
  else if (result > 0)
    console::write_line("Aaa > aaa");
  else
    console::write_line("Aaa == aaa");
}

// This code produces the following output :
//
// Aaa == aaa

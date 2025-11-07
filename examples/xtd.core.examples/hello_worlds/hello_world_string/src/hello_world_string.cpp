#include <xtd/xtd>

auto main() -> int {
  console::out << string::format("{,-8},{,8}!", "Hello", "World"_s) << environment::new_line;
}

// This code produces the following output :
//
// Hello   ,   World!

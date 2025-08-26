#include <xtd/xtd>

auto main() -> int {
  console::out << string::sprintf("%s %s %d %c", "string", "literal"_s, 42, 'a') << environment::new_line;
}

// This code produces the following output :
//
// string literal 42 a

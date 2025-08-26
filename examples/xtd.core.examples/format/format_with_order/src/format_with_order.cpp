#include <xtd/xtd>

auto main() -> int {
  console::out << string::format("{0} {1} {2:D} {3} {0}", "string", "literal"_s, 42, 'a') << environment::new_line;
}

// This code produces the following output :
//
// string literal 42 a string

#include <xtd/xtd>

auto main() -> int {
  console::out << string::format("{} {} {} {}", "string"_s, "literal", 42, 'a') << environment::new_line;
}

// This code produces the following output :
//
// string literal 42 a

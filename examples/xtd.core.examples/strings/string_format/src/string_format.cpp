#include <xtd/xtd>

auto main() -> int {
  console::out << string::format("{0,10} {1} {2:D3} {3}", "string"_s, "literal", 42, 'a') << environment::new_line;
}

// This code produces the following output :
//
//     string literal 042 a

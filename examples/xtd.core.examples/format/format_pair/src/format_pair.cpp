#include <xtd/xtd>
#include <utility>

auto main() -> int {
  console::out << string::format("{}", key_value_pair(1, "one")) << environment::new_line;
  console::out << environment::new_line;
  console::out << string::format("{}", std::make_pair(1, "one")) << environment::new_line;
}

// This code produces the following output :
//
// (1, one)
//
// (1, one)

#include <xtd/xtd>

auto main() -> int {
  console::out << format("{}", optional<string> {"string value"}) << environment::new_line;
  console::out << format("{}", optional<string> {"string value"}.value()) << environment::new_line;
  console::out << format("{}", optional<string> {}.value_or("fallback string")) << environment::new_line;
  console::out << format("{}", optional<string> {}) << environment::new_line;
  console::out << format("{}", nullopt) << environment::new_line;
}

// This code produces the following output :
//
// (string value)
// string value
// fallback string
// (null)
// (null)

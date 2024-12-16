#include <xtd/console>
#include <xtd/environment>
#include <xtd/format>
#include <xtd/null_opt>
#include <xtd/optional>

using namespace xtd;

auto main() -> int {
  console::out << format("{}", nullopt) << environment::new_line;
  console::out << format("{}", optional<string> {}) << environment::new_line;
  console::out << format("{}", optional<string> {"string value"}) << environment::new_line;
}

// This code produces the following output :
//
// (null)
// (null)
// (string value)

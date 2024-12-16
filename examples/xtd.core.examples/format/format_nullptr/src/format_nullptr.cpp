#include <xtd/console>
#include <xtd/environment>
#include <xtd/format>

using namespace xtd;

auto main() -> int {
  console::out << format("{}", null) << environment::new_line;
  console::out << format("{}", null_ptr {}) << environment::new_line;
  console::out << format("{}", nullptr) << environment::new_line;
  console::out << format("{}", std::nullptr_t {}) << environment::new_line;
  console::out << format("{}", NULL) << environment::new_line;
  console::out << format("{}", 0) << environment::new_line;
}

// This code produces the following output :
//
// null
// null
// null
// null
// 0
// 0

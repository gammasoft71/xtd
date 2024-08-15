#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;

auto main() -> int {
  console::out << string::format("{}", nullptr) << environment::new_line;
  console::out << string::format("{}", null) << environment::new_line;
  console::out << string::format("{}", NULL) << environment::new_line;
  console::out << string::format("{}", 0) << environment::new_line;
}

// This code produces the following output :
//
// nullptr
// nullptr
// 0
// 0

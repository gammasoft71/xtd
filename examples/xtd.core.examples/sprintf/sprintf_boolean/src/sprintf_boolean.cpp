#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;

auto main() -> int {
  console::out << string::sprintf("%d", true) << environment::new_line;
  console::out << string::sprintf("%o", true) << environment::new_line;
  console::out << string::sprintf("%x", true) << environment::new_line;
  console::out << string::sprintf("%X", true) << environment::new_line;
}

// This code produces the following output :
//
// 1
// 1
// 1
// 1

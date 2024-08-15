#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;

auto main() -> int {
  console::out << ustring::sprintf("%d", true) << environment::new_line;
  console::out << ustring::sprintf("%o", true) << environment::new_line;
  console::out << ustring::sprintf("%x", true) << environment::new_line;
  console::out << ustring::sprintf("%X", true) << environment::new_line;
}

// This code produces the following output :
//
// 1
// 1
// 1
// 1

#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;

auto main() -> int {
  console::out << string::sprintf("%i", 42) << environment::new_line;
  console::out << string::sprintf("%u", 42u) << environment::new_line;
  console::out << string::sprintf("%d", 42) << environment::new_line;
  console::out << string::sprintf("0%o", 42) << environment::new_line;
  console::out << string::sprintf("0x%04x", 42) << environment::new_line;
  console::out << string::sprintf("0x%04X", 42) << environment::new_line;
}

// This code produces the following output :
//
// 42
// 42
// 42
// 052
// 0x002a
// 0x002A

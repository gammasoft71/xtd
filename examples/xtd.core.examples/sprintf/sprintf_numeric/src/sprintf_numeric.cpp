#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;

auto main() -> int {
  console::out << ustring::sprintf("%i", 42) << environment::new_line;
  console::out << ustring::sprintf("%u", 42u) << environment::new_line;
  console::out << ustring::sprintf("%d", 42) << environment::new_line;
  console::out << ustring::sprintf("0%o", 42) << environment::new_line;
  console::out << ustring::sprintf("0x%04x", 42) << environment::new_line;
  console::out << ustring::sprintf("0x%04X", 42) << environment::new_line;
}

// This code produces the following output :
//
// 42
// 42
// 42
// 052
// 0x002a
// 0x002A

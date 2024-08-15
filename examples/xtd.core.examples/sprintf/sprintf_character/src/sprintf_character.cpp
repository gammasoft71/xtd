#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;

auto main() -> int {
  console::out << ustring::sprintf("%c", 'a') << environment::new_line;
  //console::out << ustring::sprintf("%c", L'\u4eb0') << environment::new_line; // Does not work correctly
  console::out << ustring::sprintf("%c", u8'a') << environment::new_line;
  //console::out << ustring::sprintf("%c", u'\u4eb0') << environment::new_line; // Does not work correctly
  //console::out << ustring::sprintf("%c", U'\U0001F428') << environment::new_line; // Does not work correctly
}
  
  // This code produces the following output :
  //
  // a
  // a
  

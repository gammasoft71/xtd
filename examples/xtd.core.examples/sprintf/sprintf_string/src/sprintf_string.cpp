#include <xtd/xtd>

using namespace xtd;

int main() {
  console::out << ustring::sprintf("%s", "string") << environment::new_line;
  console::out << ustring::sprintf("%s", u8"u8string") << environment::new_line;
  console::out << ustring::sprintf("%s", std::string {"string"}) << environment::new_line;
  console::out << ustring::sprintf("%s", ustring {"ustring"}) << environment::new_line;
  console::out << ustring::sprintf("%s", std::u8string {u8"u8string"}) << environment::new_line;
}

// This code produces the following output :
//
// string
// u8string
// string
// ustring
// u8string

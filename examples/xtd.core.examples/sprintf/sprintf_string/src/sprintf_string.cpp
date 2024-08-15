#include <xtd/xtd>

using namespace xtd;

int main() {
  console::out << string::sprintf("%s", "string") << environment::new_line;
  console::out << string::sprintf("%s", u8"u8string") << environment::new_line;
  console::out << string::sprintf("%s", std::string {"string"}) << environment::new_line;
  console::out << string::sprintf("%s", string {"string"}) << environment::new_line;
  console::out << string::sprintf("%s", std::u8string {u8"u8string"}) << environment::new_line;
}

// This code produces the following output :
//
// string
// u8string
// string
// string
// u8string

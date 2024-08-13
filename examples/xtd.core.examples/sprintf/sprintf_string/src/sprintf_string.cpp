#include <xtd/xtd>

using namespace xtd;

int main() {
  std::cout << ustring::sprintf("%s", "string") << std::endl;
  std::cout << ustring::sprintf("%s", u8"u8string") << std::endl;
  std::cout << ustring::sprintf("%s", std::string {"string"}) << std::endl;
  std::cout << ustring::sprintf("%s", ustring {"ustring"}) << std::endl;
  std::cout << ustring::sprintf("%s", std::u8string {u8"u8string"}) << std::endl;
}

// This code produces the following output :
//
// string
// u8string
// string
// ustring
// u8string

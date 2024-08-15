#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>

using namespace std::literals;
using namespace xtd;

auto main() -> int {
  console::out << ustring::format("{}", "string") << environment::new_line;
  console::out << ustring::format("{}", u8"string") << environment::new_line;
  console::out << ustring::format("{}", L"string") << environment::new_line;
  console::out << ustring::format("{}", u"string") << environment::new_line;
  console::out << ustring::format("{}", U"string") << environment::new_line;
  console::out << ustring::format("{}", "string"s) << environment::new_line;
  console::out << ustring::format("{}", u8"string"s) << environment::new_line;
  console::out << ustring::format("{}", L"string"s) << environment::new_line;
  console::out << ustring::format("{}", u"string"s) << environment::new_line;
  console::out << ustring::format("{}", U"string"s) << environment::new_line;
  console::out << ustring::format("{}", "string"_s) << environment::new_line;
  console::out << ustring::format("{}", u8"string"_s) << environment::new_line;
  console::out << ustring::format("{}", L"string"_s) << environment::new_line;
  console::out << ustring::format("{}", u"string"_s) << environment::new_line;
  console::out << ustring::format("{}", U"string"_s) << environment::new_line;
  console::out << ustring::format("{:anything}", "string") << environment::new_line;
}

// This code produces the following output :
//
// string
// string
// string
// string
// string
// string
// string
// string
// string
// string
// string
// string
// string
// string
// string
// string

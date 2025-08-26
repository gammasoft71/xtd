#include <xtd/xtd>

using namespace std::literals;

auto main() -> int {
  console::out << string::format("{}", "string") << environment::new_line;
  console::out << string::format("{}", u8"string") << environment::new_line;
  console::out << string::format("{}", L"string") << environment::new_line;
  console::out << string::format("{}", u"string") << environment::new_line;
  console::out << string::format("{}", U"string") << environment::new_line;
  console::out << string::format("{}", "string"s) << environment::new_line;
  console::out << string::format("{}", u8"string"s) << environment::new_line;
  console::out << string::format("{}", L"string"s) << environment::new_line;
  console::out << string::format("{}", u"string"s) << environment::new_line;
  console::out << string::format("{}", U"string"s) << environment::new_line;
  console::out << string::format("{}", "string"_s) << environment::new_line;
  console::out << string::format("{}", u8"string"_s) << environment::new_line;
  console::out << string::format("{}", L"string"_s) << environment::new_line;
  console::out << string::format("{}", u"string"_s) << environment::new_line;
  console::out << string::format("{}", U"string"_s) << environment::new_line;
  console::out << string::format("{:anything}", "string") << environment::new_line;
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

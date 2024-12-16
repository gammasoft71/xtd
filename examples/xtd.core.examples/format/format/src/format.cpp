#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;

auto main() -> int {
  console::out << string::format("{} {} {} {}", "string"_s, "literal", 42, 'a') << environment::new_line;
}

// This code produces the following output :
//
// string literal 42 a

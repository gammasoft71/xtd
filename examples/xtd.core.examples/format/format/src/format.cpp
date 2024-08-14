#include <xtd/console>
#include <xtd/environment>
#include <xtd/ustring>

using namespace xtd;

auto main() -> int {
  console::out << ustring::format("{} {} {} {}", "string", "literal"_s, 42, 'a') << environment::new_line;
}

// This code produces the following output :
//
// string literal 42 a

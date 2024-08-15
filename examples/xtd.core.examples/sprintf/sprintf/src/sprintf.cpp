#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;

auto main() -> int {
  console::out << ustring::sprintf("%s %s %d %c", "string", "literal"_s, 42, 'a') << environment::new_line;
}

// This code produces the following output :
//
// string literal 42 a

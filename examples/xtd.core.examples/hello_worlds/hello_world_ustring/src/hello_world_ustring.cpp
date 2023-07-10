#include <xtd/console>
#include <xtd/environment>
#include <xtd/ustring>

using namespace xtd;

auto main()->int {
  console::out << ustring::format("{},{,10}!", "Hello", "World"_s) << environment::new_line;
}

// This code produces the following output:
//
// Hello,     World!

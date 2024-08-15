#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>
#include <tuple>

using namespace xtd;

auto main() -> int {
  console::out << ustring::format("{}", make_tuple(1, "one", .42)) << environment::new_line;
}

// This code produces the following output :
//
// (1, one, 0.42)

#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>
#include <utility>

using namespace xtd;

auto main() -> int {
  console::out << ustring::format("{}", std::make_pair(1, "one")) << environment::new_line;
}

// This code produces the following output :
//
// (1, one)

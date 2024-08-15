#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>
#include <optional>

using namespace xtd;

auto main() -> int {
  console::out << string::format("{}", std::optional<string>()) << environment::new_line;
  console::out << string::format("{}", std::optional<string>("Optional string")) << environment::new_line;
}

// This code produces the following output :
//
// (null)
// (Optional string)

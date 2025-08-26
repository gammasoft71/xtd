#include <xtd/xtd>
#include <tuple>

auto main() -> int {
  console::out << string::format("{}", std::make_tuple(1, "one", .42)) << environment::new_line;
}

// This code produces the following output :
//
// (1, one, 0.42)

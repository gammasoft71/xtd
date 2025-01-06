#include <xtd/xtd>

using namespace xtd;
using namespace xtd::linq;

auto main() -> int {
  auto items = std::initializer_list<string> {"One", "Two", "Three", "Four", "Five"};
  const auto& enumerable = from(items);
  auto enumerator = enumerable.get_enumerator();
  
  while (enumerator.move_next())
    console::write_line(enumerator.current());
}

// This code produces the following output :
//
// One
// Two
// Three
// Four
// Five


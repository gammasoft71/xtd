#include <xtd/xtd>

auto main() -> int {
  auto strings = enumerable::repeat("I like programming.", 15);

  for (const auto& str : strings)
    console::write_line(str);
}

// This code produces the following output :
//
// I like programming.
// I like programming.
// I like programming.
// I like programming.
// I like programming.
// I like programming.
// I like programming.
// I like programming.
// I like programming.
// I like programming.
// I like programming.
// I like programming.
// I like programming.
// I like programming.
// I like programming.

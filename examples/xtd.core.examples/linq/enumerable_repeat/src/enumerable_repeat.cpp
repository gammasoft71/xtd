#include <xtd/xtd>

auto main() -> int {
  auto strings = enumerable::repeat("I like programming.", 15);

  for (const auto& str : strings)
    println(str);
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

#include <xtd/xtd>

auto main() -> int {
  console::write_line("Hello, {}!", environment::user_name());
}

// This code produces the following output :
//
// Hello, gammasoft71!

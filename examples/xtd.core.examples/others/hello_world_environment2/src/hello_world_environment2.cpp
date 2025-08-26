#include <xtd/xtd>

auto main() -> int {
  console::out << "Hello, " << environment::user_name() << "!" << environment::new_line;
}

// This code can produce the following output :
//
// Hello, gammasoft71!

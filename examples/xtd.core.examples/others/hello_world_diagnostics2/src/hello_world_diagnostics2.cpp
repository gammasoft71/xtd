#define TRACE
#include <xtd/ctrace>

using namespace xtd;

auto main() -> int {
  ctrace << "Hello, World!" << environment::new_line;
}

// This code produces the following debug output :
//
// Hello, World!

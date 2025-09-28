#define TRACE 1 // Force to trace even if example is builded with -DNTRACE.
#include <xtd/xtd>

auto main() -> int {
  ctrace << "Hello, World!" << environment::new_line << std::flush;
}

// This code produces the following debug output :
//
// Hello, World!

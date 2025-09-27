#define TRACE // Force to trace even if example is builded with -DNTRACE.
#include <xtd/xtd>

auto main() -> int {
  diagnostics::trace::write_line("Hello, World!");
}

// This code produces the following debug output :
//
// Hello, World!

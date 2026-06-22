// #define NTRACE // Uncomment this line or build with -DNTRACE to deactivate xtd::diagnostics::trace
#include <xtd/xtd>

auto main() -> int {
  diagnostics::trace::write_line("Hello, World!");
}

// This code produces the following debug output :
//
// Hello, World!

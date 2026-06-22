// #define NTRACE // Uncomment this line or build with -DNTRACE to deactivate xtd::diagnostics::trace
#include <xtd/xtd>

auto main() -> int {
  ctrace << "Hello, World!" << environment::new_line << std::flush;
}

// This code produces the following debug output :
//
// Hello, World!

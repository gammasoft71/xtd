#define TRACE
#include <xtd/xtd>

using namespace xtd::diagnostics;

auto main() -> int {
  trace::write_line("Hello, World!");
}

// This code produces the following debug output :
//
// Hello, World!

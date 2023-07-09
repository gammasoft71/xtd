#define TRACE
#include <xtd/diagnostics/trace>

using namespace xtd::diagnostics;

auto main()->int {
  trace::write_line("Hello, World!");
}

// This code can produces the following output debug:
//
// Hello, World!

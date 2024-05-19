// Specify -DDEBUG when compiling or add #define DEBUG in the source file.

#include <xtd/diagnostics/debug>
#include <xtd/diagnostics/ostream_trace_listener>
#include <xtd/console>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

auto main() -> int {
  debug::listeners().push_back(make_shared<ostream_trace_listener>(console::out));
  debug::auto_flush(true);
  debug::indent();
  debug::write_line("Entering Main");
  console::write_line("Hello World.");
  debug::write_line("Exiting Main");
  debug::unindent();
}

// This code produces the following output :
//
//     Entering Main
// Hello World.
//     Exiting Main

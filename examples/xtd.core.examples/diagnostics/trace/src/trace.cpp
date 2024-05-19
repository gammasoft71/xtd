// Specify -DTRACE when compiling or add #define TRACE in the source file.
#define DEBUG

#include <xtd/diagnostics/trace>
#include <xtd/diagnostics/ostream_trace_listener>
#include <xtd/console>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

auto main() -> int {
  trace::listeners().push_back(make_shared<ostream_trace_listener>(console::out));
  trace::auto_flush(true);
  trace::indent();
  trace::write_line("Entering Main");
  console::write_line("Hello World.");
  trace::write_line("Exiting Main");
  trace::unindent();
}

// This code produces the following output :
//
//     Entering Main
// Hello World.
//     Exiting Main

#define DEBUG // Force debug mode even if example is builded in release.
#include <xtd/xtd>

auto main() -> int {
  diagnostics::trace::listeners().add(new_ptr<diagnostics::ostream_trace_listener>(console::out));
  diagnostics::trace::auto_flush(true);
  diagnostics::trace::indent();
  diagnostics::trace::write_line("Entering Main");
  console::write_line("Hello World.");
  diagnostics::trace::write_line("Exiting Main");
  diagnostics::trace::unindent();
}

// This code produces the following output :
//
//     Entering Main
// Hello World.
//     Exiting Main

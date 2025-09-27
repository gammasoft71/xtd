#define DEBUG // Force debug mode even if example is builded in release.
#include <xtd/xtd>

auto main() -> int {
  diagnostics::debug::listeners().add(new_ptr<diagnostics::ostream_trace_listener>(console::out));
  diagnostics::debug::auto_flush(true);
  diagnostics::debug::indent();
  diagnostics::debug::write_line("Entering Main");
  console::write_line("Hello World.");
  diagnostics::debug::write_line("Exiting Main");
  diagnostics::debug::unindent();
}

// This code produces the following output :
//
//     Entering Main
// Hello World.
//     Exiting Main

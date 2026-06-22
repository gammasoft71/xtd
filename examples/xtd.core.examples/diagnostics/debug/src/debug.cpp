// #define NDEBUG // Uncomment this line or build with -DNDEBUG to deactivate xtd::diagnostics::debug
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

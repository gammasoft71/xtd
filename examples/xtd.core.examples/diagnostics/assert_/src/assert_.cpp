#include <xtd/diagnostics/assert>
#include <xtd/console>

using namespace xtd;

auto main() -> int {
  // Uncomment following lines to remove assert dialog
  //for (auto listener : debug::listeners())
  //  if (is<default_trace_listener>(listener))
  //    as<default_trace_listener>(listener)->assert_ui_enabled(false);

  auto index = 0;
  console::write_line("Start application");
  assert_(index > 0);
  console::write_line("End application");
}

// This code produces the following output :
//
// > If user clicks assert dialog 'Abort' button:
// Start application
//
// > If user clicks assert dialog 'Retry' button:
// Start application
// > Break the debugger on file assert_.cpp line 11.
// > If user choose continue running after break.
// End application
//
// > If user clicks assert dialog 'Ignore' button:
// Start application
// End application

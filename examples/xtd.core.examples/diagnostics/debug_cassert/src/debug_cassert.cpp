#include <xtd/xtd>

auto main() -> int {
  // Uncomment following lines to remove assert dialog
  //for (auto listener : diagnostics::debug::listeners())
  //  if (is<diagnostics::default_trace_listener>(listener))
  //    as<diagnostics::default_trace_listener>(listener)->assert_ui_enabled(false);

  auto index = 0;
  console::write_line("Start application");
  diagnostics::debug::cassert(index > 0);
  console::write_line("End application");
}

// This code produces the following output :
//
// > If user clicks assert dialog 'Abort' button:
// Start application
//
// > If user clicks assert dialog 'Retry' button:
// Start application
// > Break the debugger on file debug_cassert.cpp line 12.
// > If user choose continue running after break.
// End application
//
// > If user clicks assert dialog 'Ignore' button:
// Start application
// End application

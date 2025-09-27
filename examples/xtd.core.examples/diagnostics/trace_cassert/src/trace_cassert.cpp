#define TRACE // Force to trace even if example is builded with -DNTRACE.
#include <xtd/xtd>

auto main() -> int {
  // Uncomment following lines to remove assert dialog
  //for (auto listener : diagnostics::trace::listeners())
  //  if (is<diagnostics::default_trace_listener>(listener))
  //    as<diagnostics::default_trace_listener>(listener)->assert_ui_enabled(false);

  auto index = 0;
  console::write_line("Start application");
  diagnostics::trace::cassert(index > 0, "index must be greater than 0");
  console::write_line("End application");
}

// This code produces the following output :
//
// > If user clicks assert dialog 'Abort' button:
// Start application
//
// > If user clicks assert dialog 'Retry' button:
// Start application
// > Break the debugger on file tace_cassert.cpp line 13.
// > If user choose continue running after break.
// End application
//
// > If user clicks assert dialog 'Ignore' button:
// Start application
// End application

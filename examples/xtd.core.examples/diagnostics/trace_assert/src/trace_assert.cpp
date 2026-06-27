// #define NTRACE // Uncomment this line or build with -DNTRACE to deactivate xtd::diagnostics::trace
#include <xtd/xtd>

auto main() -> int {
  // Uncomment following line to remove assert dialog or set literner default assertuienabled to false in "${application_data}/${company_name}/${product_name}.diagnostics.config".
  //diagnostics::trace::listeners().for_each([](auto listener) {if (is<diagnostics::default_trace_listener>(listener)) as<diagnostics::default_trace_listener>(listener)->assert_ui_enabled(false);});

  auto index = 0;
  console::write_line("Start application");
  diagnostics::trace::assert(index > 0, "index must be greater than 0");
  console::write_line("End application");
}

// This code produces the following output :
//
// > If user clicks assert dialog 'Abort' button:
// Start application
//
// > If user clicks assert dialog 'Retry' button:
// Start application
// > Break the debugger on file tace_assert.cpp line 10.
// > If user choose continue running after break.
// End application
//
// > If user clicks assert dialog 'Ignore' button:
// Start application
// End application

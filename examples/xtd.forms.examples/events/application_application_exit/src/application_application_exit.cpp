#define TRACE 1 // Force to trace even if example is builded with -DNTRACE.
#include <xtd/xtd>

auto main() -> int {
  environment::program_exit += delegate_ {diagnostics::trace::write_line("The program is stopped");};
  application::application_exit += delegate_ {diagnostics::trace::write_line("The application is stopped");};
  diagnostics::trace::write_line("Before application run");
  application::run(form {});
  diagnostics::trace::write_line("After application exit");
  diagnostics::trace::write_line("Before program exit");
}

// Trace
//
// Before application run
// The application is stopped
// After application exit
// Before program exit
// The program is stopped

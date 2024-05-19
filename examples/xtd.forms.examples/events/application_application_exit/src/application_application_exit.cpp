#define TRACE
#include <xtd/diagnostics/trace>
#include <xtd/forms/application>
#include <xtd/environment>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms;

auto main() -> int {
  environment::program_exit += [] {trace::write_line("The program is stopped");};
  application::application_exit += [] {trace::write_line("The application is stopped");};
  trace::write_line("Before application run");
  application::run(form {});
  trace::write_line("After application exit");
  trace::write_line("Before program exit");
}

// Trace
//
// Before application run
// The application is stopped
// After application exit
// Before program exit
// The program is stopped

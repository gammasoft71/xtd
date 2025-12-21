#include <xtd/xtd>

auto main() -> int {
  auto start_info = diagnostics::process_start_info {"xtdc", "--help"};
  start_info.redirect_standard_output(true);
  
  auto& standard_output = diagnostics::process::start(start_info).standard_output();
  
  auto reader = stream_reader {standard_output};
  console::write(reader.read_to_end());
}

// This code produces the following output :
//
// xtdc version 0.2.0, (c) 2025 by Gammasoft
//
// Usage: xtdc [<options> | command [<command-argument>] [<command-options>]]
//
// options:
//   -i, --info       Display information.
//   -v, --version    Display version in use.
//   -h, --help       Display help.
//
// command:
//   new              Initializes project.
//   generate         Generate project from existing source files.
//   add              Adds new project to project.
//   update           Regenerates a project.
//   run              Compiles and immediately executes a project.
//   build            Builds a project.
//   install          Install a project.
//   clean            Clean build output(s).
//   open             Open a project in default ide.
//   targets          List project targets.
//   test             Runs unit tests using the test runner specified in the project.
//   uninstall        Uninstall a project.
//   documentation    Open xtd documentation.
//   examples         Open xtd examples.
//   guide            Open xtd reference guide.
//   web              Open xtd website.
//   help             Show help.
//
// Run 'xtdc command --help' for more information on a command.

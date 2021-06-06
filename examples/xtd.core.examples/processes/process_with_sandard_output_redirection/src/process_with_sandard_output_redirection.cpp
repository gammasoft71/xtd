#include <xtd/xtd>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;

int main() {
  process_start_info start_info("xtdc", "--help");
  start_info.use_shell_execute(false);
  start_info.redirect_standard_output(true);

  std::istream& standard_output = process::start(start_info).standard_output();

  stream_reader reader(standard_output);
  console::write(reader.read_to_end());
}

// This code produces the following output :
//
// xtdc version 1.0.0, © 2021 by Gammasoft
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
//   web              Open Gammasoft website.
//   help             Show help.
//
//   Run 'xtdc command --help' for more information on a command.

#include <xtd/xtd>

using namespace xtd;

int main() {
  console::write_line();
  // Invoke this sample with an arbitrary set of command line arguments.
  console::write_line("command_line: {0}", environment::command_line());
}

// This code produces the following output :
//
// >environment_command_line ARBITRARY TEXT
//
// CommandLine: /!---OMITTED---!/environment_command_line  ARBITRARY TEXT

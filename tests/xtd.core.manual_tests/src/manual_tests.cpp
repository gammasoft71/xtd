#include <xtd/xtd>

auto main() -> int {
  println("Command line arguments = {}", environment::get_command_line_args());
  println("Location path = {}", reflection::assembly::get_executing_assembly().location_path());
  println("Location = {}", reflection::assembly::get_executing_assembly().location());
  println("File name = {}", reflection::assembly::get_executing_assembly().file_name());
}

// This code produces the following output :
//
// Command line arguments = [./xtd.core.manual_tests, One, Two, Three Four, Five]
// Location path = /Users/gammasoft71/Projects/xtd/build/tests/xtd.core.manual_tests/Debug
// Localtion = /Users/gammasoft71/Projects/xtd/build/tests/xtd.core.manual_tests/Debug/xtd.core.manual_tests
// File name = xtd.core.manual_tests

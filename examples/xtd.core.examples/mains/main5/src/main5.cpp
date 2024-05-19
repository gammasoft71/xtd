#include <xtd/console>
#include <xtd/environment>

using namespace xtd;

auto main() -> int {
  // Write arguments to the console output
  for (auto arg : environment::get_command_line_args())
    console::write_line(arg);
    
  return 42;
}

// This code produces the following output if one two "three four" five are entered on command line:
//
// /!---OMITTED---!/main5
// one
// two
// three four
// five

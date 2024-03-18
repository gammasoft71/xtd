#include <xtd/console>
#include <xtd/environment>

using namespace xtd;

auto main()->int {
  console::write_line("Received the following arguments:\n");
  
  auto args = environment::get_command_line_args();
  for (auto i = 1_z; i < args.size(); i++)
    console::write_line("[{0}] = {1}", i - 1, args[i]);
    
  console::write_line();
}

// This code produces the following output :
//
// >echo_args one two "three four" five
//
// Received the following arguments:
//
// [0] = one
// [1] = two
// [2] = three four
// [3] = five

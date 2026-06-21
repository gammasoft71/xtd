#include <xtd/xtd>

auto main() -> int {
  auto beep_count = 0;
  if (environment::get_command_line_args().length() != 2 || !int32_object::try_parse(environment::get_command_line_args()[1], beep_count) || beep_count < 1 || beep_count > 9) {
    console::write_line("Usage: Enter the number of times (between 1 and 9) to beep.");
    return 1;
  }
  
  for (auto i = 1; i <= beep_count; ++i) {
    console::write_line("Beep number {}.", i);
    console::beep();
    thread::sleep(300_ms);
  }
}

// This code produces the following output if 3 is entered on command line:
//
// Beep number 1.
// Beep number 2.
// Beep number 3.

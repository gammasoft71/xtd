#include <xtd/xtd>

auto main() -> int {
  auto beep_count = 0;
  if (environment::get_command_line_args().length() != 2 || !int32_object::try_parse(environment::get_command_line_args()[1], beep_count) || beep_count < 1 || beep_count > 9) {
    console::write_line("Usage: Enter the number of times (between 1 and 9) to beep.");
    return 1;
  }

  for (auto i = 1; i <= beep_count; ++i) {
    console::out << string::format("Beep number {}.", i) << beep() << environment::new_line;
    threading::thread::sleep(300_ms);
  }
}

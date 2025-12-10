#include <xtd/xtd>

using display_message = delegate<void(const string&)>;

auto show_windows_message(const string& message) -> void {
  forms::message_box::show(message);
}

auto write_line(const string& message) -> void {
  console::write_line(message);
}

auto main() -> int {
  auto message_target = display_message {};
  
  if (environment::get_command_line_args().length() > 1)
    message_target = show_windows_message;
  else
    message_target = write_line;
    
  message_target("Hello, World!");
}

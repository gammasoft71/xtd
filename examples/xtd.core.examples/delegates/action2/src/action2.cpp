#include <xtd/xtd>

using display_message = action<const string&>;

void show_windows_message(const string& message) {
  forms::message_box::show(message);
}

void write_line(const string& message) {
  console::write_line(message);
}

auto main() -> int {
  auto message_target = display_message {};
  
  if (environment::get_command_line_args().size() > 1)
    message_target = show_windows_message;
  else
    message_target = write_line;
    
  message_target("Hello, World!");
}

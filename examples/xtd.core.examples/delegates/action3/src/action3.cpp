#include <xtd/xtd>

auto main() -> int {
  auto message_target = action<const string&> {};
  
  if (environment::get_command_line_args().length() > 1)
    message_target = [](auto&& message) {forms::message_box::show(message);};
  else
    message_target = [](auto&& message) {console::write_line(message);};
    
  message_target("Hello, World!");
}

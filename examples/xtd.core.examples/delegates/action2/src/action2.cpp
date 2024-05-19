#include <xtd/action>
#include <xtd/console>
#include <xtd/environment>
#include <xtd/forms/message_box>

using namespace xtd;
using namespace xtd::forms;

using display_message = action<const ustring&>;

void show_windows_message(const ustring& message) {
  message_box::show(message);
}

void write_line(const ustring& message) {
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

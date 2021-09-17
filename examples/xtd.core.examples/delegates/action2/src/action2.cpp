#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

using display_message = action<const ustring&>;

void show_windows_message(const ustring& message) {
  message_box::show(message);
}

void write_line(const ustring& message) {
  console::write_line(message);
}

int main() {
  display_message message_target;
  
  if (environment::get_command_line_args().size() > 1)
    message_target = show_windows_message;
  else
    message_target = write_line;
  
  message_target("Hello, World!");
}

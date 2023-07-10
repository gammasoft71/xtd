#include <xtd/action>
#include <xtd/console>
#include <xtd/environment>
#include <xtd/forms/message_box>

using namespace xtd;
using namespace xtd::forms;

auto main()->int {
  action<const ustring&> message_target;
  
  if (environment::get_command_line_args().size() > 1)
    message_target = [](const ustring & message) {message_box::show(message);};
  else
    message_target = [](const ustring & message) {console::write_line(message);};
    
  message_target("Hello, World!");
}

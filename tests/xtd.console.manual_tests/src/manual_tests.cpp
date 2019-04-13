#include <atomic>
#include <xtd/console>

using namespace std;
using namespace std::string_literals;

// The main entry point for the application.
int main() {
  xtd::console::output_code_page(65001);
  
  xtd::console::cancel_key_press += [&](xtd::console_cancel_event_args& e) {
    xtd::console::write_line("Event handler called");
    e.cancel(true);
  };
  
  //xtd::console::treat_control_c_as_input(true);
  xtd::console::write_line("Press escape key to quit");
  xtd::console_key_info key;
  while (key.key() != xtd::console_key::escape) {
    key = xtd::console::read_key(true);
    xtd::console::write_line("(key = {}, key_char = '{}', modifiers {})", key.key(), static_cast<char>(key.key_char()), key.modifiers());
  }

  //cout << xtd::strings::format("{}, {}!", "Hello", "World"s) << endl;
}

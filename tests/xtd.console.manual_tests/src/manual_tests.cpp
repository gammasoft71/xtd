#include <atomic>
#include <xtd/console>

using namespace std;
using namespace std::string_literals;

// The main entry point for the application.
int main() {
  xtd::console::output_code_page(65001);
  
  xtd::console::cancel_key_press += [&](xtd::console_cancel_event_args& e) {
    cout << "Event handler called" << endl;
    e.cancel(true);
  };
  
  char a = 'a';
  cout << "a = '" << a << "'" << endl;
  
  //xtd::console::treat_control_c_as_input(true);
  cout << "Press any key to continue" << endl;
  xtd::console_key_info key;
  while (key.key() != xtd::console_key::escape) {
    key = xtd::console::read_key(true);
    xtd::console::write_line("(key = {}, key_char = '{}', modifiers {})", key.key(), static_cast<char>(key.key_char()), key.modifiers());
  }

  //cout << xtd::strings::format("{}, {}!", "Hello", "World"s) << endl;
}

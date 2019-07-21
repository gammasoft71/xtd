#include <atomic>
#include <xtd/xtd.console>

using namespace std;
using namespace xtd;
using namespace std::string_literals;

// The main entry point for the application.
int main() {
  //cout << xtd::strings::format("{}, {}!", "Hello", "World"s) << endl;
  console::output_code_page(65001);
  xtd::console::write_line("\u0627\u0644\u0643\u0644\u0645\u0629 \u0627\u0644\u0639\u0631\u0628\u064A\u0629");

  
  console::cancel_key_press += [&](console_cancel_event_args& e) {
    xtd::console::write_line("Event handler called");
    e.cancel(true);
  };
  
  //xtd::console::treat_control_c_as_input(true);
  console::write_line(console::treat_control_c_as_input());
  console::write_line("Press escape key to quit");
  console_key_info key;
  while (key.key() != console_key::escape) {
    key = console::read_key(true);
    console::write_line("key_press [key={}, key_char='{}', modifiers={}]", key.key(), key.key_char(), key.modifiers());
  }
}

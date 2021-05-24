#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  console::cancel_key_press += [](xtd::console_cancel_event_args & e) {
    console::write_line("Signal {0} intercepted !", e.special_key());
    e.cancel(true);
  };
  
  while (true) {
    if (console::key_available()) {
      console_key_info key_info = console::read_key(true);
      console::write_line("Key = {} ({}), Char = '{}' ({}), Modifiers = {}", key_info.key(), static_cast<int>(key_info.key()), key_info.key_char(), static_cast<int>(key_info.key_char()), key_info.modifiers());
      if (key_info.key() == console_key::escape) break;
    }
  }
}

// This code produces the following output if user stroke 'q', 'w', 'e', 'r', 't', 'y', Ctrl+C and Escape keys:
//
// Key = q (81), Char = 'q' (113), Modifiers = 0
// Key = w (87), Char = 'w' (119), Modifiers = 0
// Key = e (69), Char = 'e' (101), Modifiers = 0
// Key = r (82), Char = 'r' (114), Modifiers = 0
// Key = t (84), Char = 't' (116), Modifiers = 0
// Key = y (89), Char = 'y' (121), Modifiers = 0
// Signal control_c intercepted !
// Key = escape (27), Char = ' (27), Modifiers = 0

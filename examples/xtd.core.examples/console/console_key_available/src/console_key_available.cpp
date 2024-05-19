#include <xtd/threading/thread>
#include <xtd/console>

using namespace xtd;
using namespace xtd::threading;

auto main() -> int {
  auto cki = console_key_info {};
  
  do {
    console::write_line("\nPress a key to display; press the 'x' key to quit.");
    
    // Your code could perform some useful task in the following loop. However,
    // for the sake of this example we'll merely pause for a quarter second.
    
    while (console::key_available() == false)
      thread::sleep(250_ms); // Loop until input is entered.
    
    cki = console::read_key(true);
    console::write_line("You pressed the '{0}' key.", cki.key());
  } while (cki.key() != console_key::x);
}

// This example produces results if user stroke 'h', 'e', pagge_up, down_arrow, and 'x' keys
//
// Press a key to display; press the 'x' key to quit.
// You pressed the 'h' key.
//
// Press a key to display; press the 'x' key to quit.
// You pressed the 'e' key.
//
// Press a key to display; press the 'x' key to quit.
// You pressed the 'page_up' key.
//
// Press a key to display; press the 'x' key to quit.
// You pressed the 'down_arrow' key.
//
// Press a key to display; press the 'x' key to quit.
// You pressed the 'x' key.

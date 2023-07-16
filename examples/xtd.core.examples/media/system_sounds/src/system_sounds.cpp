#include <xtd/media/system_sounds>
#include <xtd/console>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::media;

namespace system_sound_example {
  class program {
  public:
    // The main entry point for the application.
    static auto main() {
      console::write_line("Type corresponding key to play sound :");
      console::write_line();
      console::write_line("  a   : asterisk");
      console::write_line("  b   : beep");
      console::write_line("  e   : exclamation");
      console::write_line("  h   : hand");
      console::write_line("  q   : question");
      console::write_line();
      console::write_line("  Esc : exit");
      
      while (true) {
        auto key_info = console::read_key(true);
        switch (key_info.key()) {
          case console_key::a: system_sounds::asterisk().play(); break;
          case console_key::b: system_sounds::beep().play(); break;
          case console_key::e: system_sounds::exclamation().play(); break;
          case console_key::h: system_sounds::hand().play(); break;
          case console_key::q: system_sounds::question().play(); break;
          case console_key::escape: environment::exit(0); break;
          default: break;
        }
      }
    }
  };
}

startup_(system_sound_example::program);

// This code can produce the following output:
//

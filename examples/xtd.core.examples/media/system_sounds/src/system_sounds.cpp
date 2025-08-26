#include <xtd/xtd>

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
          case console_key::a: media::system_sounds::asterisk().play(); break;
          case console_key::b: media::system_sounds::beep().play(); break;
          case console_key::e: media::system_sounds::exclamation().play(); break;
          case console_key::h: media::system_sounds::hand().play(); break;
          case console_key::q: media::system_sounds::question().play(); break;
          case console_key::escape: environment::exit(0); break;
          default: break;
        }
      }
    }
  };
}

startup_(system_sound_example::program::main);

// This code can produce the following output :
//

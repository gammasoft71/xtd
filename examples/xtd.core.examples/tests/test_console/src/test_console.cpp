#include <xtd/xtd>

class console_main {
public:
  static auto main() {
    console::write_line("Hello, World!");
    forms::message_box::show("Hello, World!");
  }
};

startup_(console_main::main);

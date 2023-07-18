#include <xtd/forms/message_box>
#include <xtd/console>
#include <xtd/startup>

using namespace xtd;

class console_main {
public:
  static auto main() {
    console::write_line("Hello, World!");
    forms::message_box::show("Hello, World!");
  }
};

startup_(console_main);

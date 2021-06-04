#include <xtd/xtd>

using namespace xtd;

class console_main {
public:
  static void main() {
    console::write_line("Hello, World!");
  }
};

startup_(console_main);

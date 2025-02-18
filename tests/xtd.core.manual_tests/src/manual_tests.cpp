#include <xtd/xtd>

namespace manual_tests {
  class program static_ {
  public:
    static auto main(const auto& args) {
      console::write_line("Hello, world!");
    }
  };
}

startup_(manual_tests::program::main);

// This code can produces the following output:
//
// Hello, World!

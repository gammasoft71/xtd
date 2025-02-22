#include <xtd/xtd>

namespace xtd::tests {
  class program static_ {
  public:
    static auto main(const auto& args) {
      console::write_line("Hello, world!");
    }
  };
}

startup_(tests::program::main);

// This code can produces the following output:
//
// Hello, World!

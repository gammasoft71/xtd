#include <xtd/xtd>

class manual_tests static_ {
public:
  static auto main(const auto& args) {
    console::write_line("Hello, world!");
  }
};

startup_(manual_tests::main);

// This code can produces the following output:
//
// Hello, World!

#include <xtd/xtd>

class manual_tests static_ {
public:
  static auto main(const auto& args) {
    println("Hello, world!");
  }
};

startup_(manual_tests::main);

// This code can produces the following output:
//
// Hello, World!

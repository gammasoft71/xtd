#include <xtd/xtd>

class manual_tests static_ {
public:
  static auto startup(const auto& args) {
    println("Hello, world!");
  }
};

startup_(manual_tests::startup);

// This code can produces the following output:
//
// Hello, World!

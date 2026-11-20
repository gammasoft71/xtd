#include <xtd/xtd>

namespace xtd::manual_tests {
  class test {
  public:
    [[nodiscard]] static auto main() {
      println("Hello, World!");
    }
  };
}

auto main() -> int {
  return startup::run(manual_tests::test::main);
}

// This code produces the following output :
//
// Hello, World!

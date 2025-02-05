#include <xtd/tunit/console_unit_test>
#include <xtd/startup>

namespace xtd::forms {
  class unit_tests {
  public:
    static auto main() -> int {
      return xtd::tunit::console_unit_test {}.run();
    }
  };
}

startup_(xtd::forms::unit_tests::main);

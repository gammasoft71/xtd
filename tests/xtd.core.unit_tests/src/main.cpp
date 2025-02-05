#include <xtd/tunit/console_unit_test>
#include <xtd/startup>

namespace xtd::core {
  class unit_tests {
  public:
    static auto main() -> int {
      return xtd::tunit::console_unit_test {}.run();
    }
  };
}

startup_(xtd::core::unit_tests::main);

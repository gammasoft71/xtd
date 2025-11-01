#include "assert_unit_tests/assert_unit_tests.hpp"
#include <xtd/startup>

namespace xtd::tunit {
  class unit_tests {
  public:
    static auto main() {
      return assert_unit_tests::register_assert_unit_test::run_all_tests();
    }
  };
}

startup_(xtd::tunit::unit_tests::main);

#include "../../../include/xtd/tunit/console_unit_test.hpp"
#include "../../../include/xtd/tunit/tunit_main.hpp"
#include <xtd/exception>

using namespace xtd;
using namespace xtd::tunit;

auto __tunit_main::main() -> int {
  return console_unit_test {}.run();
}

auto __tunit_main::main_with_gtest_compatibility() -> int {
  settings::default_settings().gtest_compatibility(true);
  return main();
}

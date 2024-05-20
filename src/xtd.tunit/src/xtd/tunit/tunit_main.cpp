#include "../../../include/xtd/tunit/console_unit_test.h"
#include "../../../include/xtd/tunit/tunit_main.h"
#include <xtd/system_exception>

using namespace xtd;
using namespace xtd::tunit;

auto __tunit_main::main() -> int {
  return console_unit_test {}.run();
}

auto __tunit_main::main_with_gtest_compatibility() -> int {
  settings::default_settings().gtest_compatibility(true);
  return main();
}

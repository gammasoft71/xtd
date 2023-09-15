#include "../../../include/xtd/tunit/console_unit_test.h"
#include "../../../include/xtd/tunit/tunit_main.h"
#include <xtd/system_exception.h>

using namespace xtd;
using namespace xtd::tunit;

int __tunit_main::main() {
  return console_unit_test {}.run();
}

int __tunit_main::main_with_gtest_compatibility() {
  settings::default_settings().gtest_compatibility(true);
  return main();
}

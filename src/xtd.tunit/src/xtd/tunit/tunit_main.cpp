#include "../../../include/xtd/tunit/console_unit_test.h"
#include "../../../include/xtd/tunit/tunit_main.h"
#include <xtd/system_exception.h>

using namespace xtd;
using namespace xtd::tunit;

int __tunit_main::main(int argc, char* argv[]) {
  return console_unit_test(argc, argv).run();
}

int __tunit_main_with_gtest_compatibility::main(int argc, char* argv[]) {
  settings::default_settings().gtest_compatibility(true);
  return console_unit_test(argc, argv).run();
}

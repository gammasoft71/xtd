#include "../../../include/xtd/tunit/console_unit_test.h"
#include "../../../include/xtd/tunit/tunit_main.h"
#include <xtd/system_exception.h>

using namespace xtd;
using namespace xtd::tunit;

int __tunit_main::main(int argc, char* argv[]) {
  system_exception::enable_stack_trace(false);
  return console_unit_test(argc, argv).run();
}

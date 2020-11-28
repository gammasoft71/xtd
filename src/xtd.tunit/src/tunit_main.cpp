#include "../include/xtd/console_unit_test.h"
#include "../include/xtd/tunit_main.h"

using namespace xtd::tunit;

int __tunit_main::main(int argc, char* argv[]) {
  return console_unit_test(argc, argv).run();
}

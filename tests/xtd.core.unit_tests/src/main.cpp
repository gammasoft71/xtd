#include <xtd/system_exception.h>
#include <xtd/tunit/console_unit_test.h>

using namespace xtd;
using namespace xtd::tunit;

int main(int argc, char* argv[]) {
  system_exception::enable_stack_trace(false);
  return console_unit_test(argc, argv).run();
}

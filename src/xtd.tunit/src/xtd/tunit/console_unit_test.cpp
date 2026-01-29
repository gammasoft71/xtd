#include "../../../include/xtd/tunit/console_unit_test.hpp"

using namespace xtd;
using namespace xtd::tunit;

console_unit_test::console_unit_test() noexcept : ostream_unit_test(console::out) {
}

int32 console_unit_test::run() noexcept {
  if (!xtd::environment::exit_code()) xtd::environment::exit_code(unit_test::run());
  return xtd::environment::exit_code();
}

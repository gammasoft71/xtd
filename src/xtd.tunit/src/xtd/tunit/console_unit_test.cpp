#include "../../../include/xtd/tunit/console_unit_test.hpp"

using namespace xtd;
using namespace xtd::tunit;

console_unit_test::console_unit_test() noexcept : ostream_unit_test(console::out) {
}

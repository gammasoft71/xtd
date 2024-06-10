#include "../../../include/xtd/tunit/console_unit_test.h"

using namespace xtd;
using namespace xtd::tunit;

console_unit_test::console_unit_test() noexcept : ostream_unit_test(console::out) {
}

console_unit_test::console_unit_test(int argc, char* argv[]) noexcept : ostream_unit_test(console::out, argc, argv) {
}

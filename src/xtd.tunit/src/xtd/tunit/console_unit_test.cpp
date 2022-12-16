#include "../../../include/xtd/tunit/console_unit_test.h"

using namespace xtd::tunit;

console_unit_test::console_unit_test() : ostream_unit_test(std::cout) {
}

console_unit_test::console_unit_test(int argc, char* argv[]) : ostream_unit_test(std::cout, argc, argv) {
}

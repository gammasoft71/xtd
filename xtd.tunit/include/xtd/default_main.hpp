/// @file
/// @brief Contains main entry point.
#pragma once
#include "console_unit_test.hpp"

#if defined(TUNIT_CONFIG_MAIN)
int main(int argc, char* argv[]) {
  return xtd::tunit::console_unit_test(argv, argc).run();
}
#endif

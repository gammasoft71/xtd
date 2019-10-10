/// @file
/// @brief Contains main entry point.
#pragma once
#include "console_unit_test.hpp"

#if defined(TUNIT_CONFIG_MAIN)
int main() {
  return xtd::tunit::console_unit_test().run();
}
#endif

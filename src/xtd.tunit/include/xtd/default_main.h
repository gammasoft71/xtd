/// @file
/// @brief Contains main entry point.
#pragma once
#include "tunit_main.h"

#if defined(TUNIT_CONFIG_MAIN)
int main() {
  return __tunit_main::main();
}
#endif

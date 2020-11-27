/// @file
/// @brief Contains main entry point.
#pragma once
#include "tunit_main.h"

#if defined(TUNIT_CONFIG_MAIN)
int main(int argc, char* argv[]) {
  return __tunit_main::main(argv, argc);
}
#endif

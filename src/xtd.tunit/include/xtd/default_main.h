/// @file
/// @brief Contains main entry point.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "tunit_main.h"

/// @cond
#if defined(TUNIT_CONFIG_MAIN)
int main(int argc, char* argv[]) {
  return __tunit_main::main(argc, argv);
}
#endif
/// @endcond

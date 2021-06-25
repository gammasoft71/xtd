/// @file
/// @brief Contains main entry point for TUNIT_CONFIG_MAIN definition.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "tunit_main.h"

/// @brief If you define TUNIT_CONFIG_MAIN before including xtd.tunit.h include, a main entry point is generated for you.
/// @par Examples
/// This example shows how to usse
/// @include tunit_config_main.cpp TUNIT_CONFIG_MAIN
#if defined(TUNIT_CONFIG_MAIN)
int main(int argc, char* argv[]) {
  return __tunit_main::main(argc, argv);
}
#endif

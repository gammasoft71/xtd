/// @file
/// @brief Contains main entry point for TUNIT_CONFIG_MAIN definition.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "tunit_main"

/// @brief If you define TUNIT_CONFIG_MAIN before including xtd.tunit.h include, a main entry point is generated for you.
/// @ingroup xtd_tunit tunit
/// @par Examples
/// This example shows how to use
/// @include tunit_config_main.cpp TUNIT_CONFIG_MAIN
#if defined(TUNIT_CONFIG_MAIN)
auto main(int argc, char* argv[])->int {
  return __tunit_main::main(argc, argv);
}
#endif

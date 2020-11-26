/// @file
/// @brief Contains main entry point.
#pragma once
#include "tunit_export.h"

/// @cond
class tunit_export_ __tunit_main final {
public:
  __tunit_main() = delete;
  static int main();
};
/// @endcond

#define tunit_main_ \
__tunit_main

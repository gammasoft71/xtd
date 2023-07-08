/// @file
/// @brief Contains __demangle function.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_TUNIT_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <string>
#include "../tunit_export.h"

/// @cond
tunit_export_ std::string __tunit_demangle(const std::string& name);
/// @endcond

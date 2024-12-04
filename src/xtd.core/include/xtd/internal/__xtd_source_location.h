/// @file
/// @brief Contains __xtd_debugbreak definition.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#if defined(_MSC_VER) && __cplusplus < 202302L
#  pragma message("Deprecated : Replaced by #include <xtd/internal/__xtd_source_location.hpp> - Will be removed in version 0.4.0.")
#else
#  warning "Deprecated : Replaced by #include <xtd/internal/__xtd_source_location.hpp> - Will be removed in version 0.4.0."
#endif
#include "__xtd_source_location.hpp"

/// @file
/// @brief Contains __cpp_language definition.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#if defined(_MSC_VER) && __cplusplus < 202302L
#  pragma message("Deprecated : Replaced by #include <xtd/internal/__cpp_language.hpp> - Will be removed in version 0.4.0.")
#else
#  warning "Deprecated : Replaced by #include <xtd/internal/__cpp_language.hpp> - Will be removed in version 0.4.0."
#endif
#include "__cpp_language.hpp"

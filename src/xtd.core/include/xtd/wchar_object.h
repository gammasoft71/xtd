/// @file
/// @brief Contains xtd::wchar_object alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#if defined(_MSC_VER) && __cplusplus < 202302L
#  pragma message("Deprecated : Replaced by #include <xtd/wchar_object.hpp> - Will be removed in version 0.4.0.")
#else
#  warning "Deprecated : Replaced by #include <xtd/wchar_object.hpp> - Will be removed in version 0.4.0."
#endif
#include "wchar_object.hpp"

/// @file
/// @brief Contains throw format exception method.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <string>
#include "../types.hpp"

/// @cond
void __format_exception(const xtd::type& type);
void __format_exception(const std::string& message);
/// @endcond

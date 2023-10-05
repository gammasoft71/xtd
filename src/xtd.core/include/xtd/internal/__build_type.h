/// @file
/// @brief Contains __build_type definition.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond
#include "../build_type.h"

/// @cond
#if !defined(NDEBUG) || defined(DEBUG)
#  define __build_type xtd::build_type::debug;
#else
#  define __build_type xtd::build_type::release;
#endif
/// @endcond

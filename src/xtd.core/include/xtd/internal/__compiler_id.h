/// @file
/// @brief Contains __compiler_id definition.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond
#include "../compiler_id.h"

/// @cond
#if defined(_MSC_VER)
#  define __compiler_id xtd::compiler_id::microsoft_visual_studio
#elif defined(__clang__)
#  define __compiler_id xtd::compiler_id::clang;
#elif defined(__GNUC__)
#  define __compiler_id xtd::compiler_id::gcc;
#else
#  define __compiler_id xtd::compiler_id::unknown;
#endif
/// @endcond

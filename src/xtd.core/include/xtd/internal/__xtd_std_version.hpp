/// @file
/// @brief Contains __xtd_std_version definitions.
#pragma once
/// @cond
#include "../check_cpp_version.hpp"

#if !defined(__XTD_STD_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

// Sometimes the preprocessor macros corresponding to C++ language and library features are not bee respected by compilers
// In this case, xtd uses its own definition. It begins with the prefix `__xtd`.
// See https://en.cppreference.com/w/cpp/feature_test and https://en.cppreference.com/w/cpp/compiler_support for more information.
// Warning Internal useonly.

/// @cond
#include <version>

#if (defined(__cpp_lib_format) && defined(_MSC_VER) && _MSC_VER >= 1932) || (defined(__apple_build_version__) && __apple_build_version__ >= 15000300) || (!defined(__APPLE__) && defined(__GNUC__) && __GNUC__ >= 13) || (!defined(__APPLE__) && defined(__clang_major__) && __clang_major__ >= 15)
#define __xtd__cpp_lib_format
#endif

#if defined(__cpp_lib_ranges)
#define __xtd__cpp_lib_ranges
#endif

#if defined(__cpp_lib_source_location)
#define __xtd__cpp_lib_source_location
#endif

#if defined(__cpp_lib_type_identity)
#define __xtd__cpp_lib_type_identity
#endif

/// @endcond

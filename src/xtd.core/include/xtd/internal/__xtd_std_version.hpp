/// @file
/// @brief Contains __xtd_std_version definitions.
#pragma once
/// @cond
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

#if defined(__cpp_lib_any) || __cplusplus >= 201703l
#define __xtd__cpp_lib_any
#endif

#if defined(__cpp_lib_char8_t)
#define __xtd__cpp_lib_char8_t
#endif

#if defined(__cpp_lib_filesystem)
#define __xtd__cpp_lib_filesystem
#endif

#if (defined(__cpp_lib_format) && defined(_MSC_VER) && _MSC_VER >= 1932) || (defined(__apple_build_version__) && __apple_build_version__ >= 15000300) || (!defined(__APPLE__) && defined(__GNUC__) && __GNUC__ >= 13) || (!defined(__APPLE__) && defined(__clang_major__) && __clang_major__ >= 15)
#define __xtd__cpp_lib_format
#endif

#if defined(__cpp_lib_optional) || __cplusplus >= 201703l
#define __xtd__cpp_lib_optional
#endif

#if defined(__cpp_lib_ranges) || __cplusplus >= 202002l
#define __xtd__cpp_lib_ranges
#endif

#if defined(__cpp_lib_semaphore) || __cplusplus >= 202002l
#define __xtd__cpp_lib_semaphore
#endif

#if defined(__cpp_lib_three_way_comparison) || __cplusplus >= 201907l
#define __xtd__cpp_lib_three_way_comparison
#endif

#if defined(__cpp_lib_source_location)
#define __xtd__cpp_lib_source_location
#endif

/// @endcond

/// @file
/// @brief Contains C++ version check.
#pragma once

/// @cond
#if defined(_MSC_VER) && _MSVC_LANG < 202002l
#  error "xtd requires C++20 or later. Use /std:c++20 with MSVC."
#elif defined(__clang__) && __cplusplus < 202002l
#  error "xtd requires C++20 or later. Use -std=c++20 with Clang."
#elif defined(__GNUC__) && __cplusplus < 202002l
#  error "xtd requires C++20 or later. Use -std=c++20 with GCC."
#elif __cplusplus < 202002l
#  error "xtd requires C++20 or later. Use set std to c++20 with your compiler option."
#endif
/// @endcond

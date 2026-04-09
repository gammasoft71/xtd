/// @file
/// @brief Contains C++ version check.
#pragma once

/// @cond
#if defined(_MSC_VER)
#  if _MSVC_LANG < 202002L
#    error "xtd requires C++20 or later. Use /std:c++20 with MSVC."
#  endif
#else
#  if __cplusplus < 202002L
#    error "xtd requires C++20 or later. Use -std=c++20 with your compiler."
#  endif
#endif
/// @endcond

/// @file
/// @brief Contains __format_information struct.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <string>
#include <limits>

/// @cond
template<class char_t>
struct __format_information {
  size_t index = std::numeric_limits<size_t>::max();
  size_t location = 0;
  std::basic_string<char_t> alignment;
  std::basic_string<char_t> format;
};
/// @endcond

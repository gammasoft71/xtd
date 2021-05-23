/// @file
/// @brief Contains __format_information struct.
#pragma once
/// @cond
#ifndef __XTD_CORE_INTERNAL__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <climits>
#include <string>

/// @cond
template<typename char_t>
struct __format_information {
  size_t index = std::numeric_limits<size_t>::max();
  size_t location;
  std::basic_string<char_t> alignment;
  std::basic_string<char_t> format;
};

/// @endcond

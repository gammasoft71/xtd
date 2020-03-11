/// @file
/// @brief Contains __format_information struct.
#pragma once

/// @cond
#ifndef __XTD_STRINGS_INCLUDE__
#error "Do not include this file yourself, use only #include <xtd/xtd.strings>"
#endif
/// @endcond

#include <string>

/// @cond
template<typename char_t>
struct __format_information {
  size_t index = -1;
  size_t location;
  std::basic_string<char_t> alignment;
  std::basic_string<char_t> format;
};

/// @endcond

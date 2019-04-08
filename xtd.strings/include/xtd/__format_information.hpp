/// @file
/// @brief Contains __format_information struct.
#pragma once
#include <string>

/// @cond
template<typename Char>
struct __format_information {
  size_t index = -1;
  size_t location;
  std::basic_string<Char> alignment;
  std::basic_string<Char> format;
};

/// @endcond

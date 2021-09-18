/// @file
/// @brief Contains __natural_formatter method.
#pragma once
/// @cond
#ifndef __XTD_CORE_INTERNAL__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <iomanip>
#include <locale>
#include <string>
#include <sstream>

/// @cond
template<typename char_t>
inline std::basic_string<char_t> __natural_formatter(long double value, int precision, const std::locale& loc) {
  std::basic_stringstream<char_t> ss;
  ss.imbue(loc);
  ss << std::fixed << std::setprecision(precision) << value;
  return ss.str();
}
/// @endcond

/// @file
/// @brief Contains __hexfloat_formatter method.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <iomanip>
#include <locale>
#include <string>
#include <sstream>

/// @cond
template<class char_t>
inline std::basic_string<char_t> __hexfloat_formatter(long double value, int precision, const std::locale& loc) {
  std::basic_stringstream<char_t> ss;
  ss.imbue(loc);
  ss << std::hexfloat << std::setprecision(precision) << value;
  return ss.str();
}
/// @endcond

/// @file
/// @brief Contains __natural_formater method.
#pragma once

/// @cond
#ifndef __XTD_STRINGS_INCLUDE__
#error "Do not include this file yourself, use only #include <xtd/xtd.strings>"
#endif
/// @endcond

#include <iomanip>
#include <locale>
#include <string>
#include <sstream>

/// @cond
template<typename char_t>
inline std::basic_string<char_t> __natural_formater(long double value, int precision, const std::locale& loc) {
  std::basic_stringstream<char_t> ss;
  ss.imbue(loc);
  ss << std::fixed << std::setprecision(precision) << value;
  return ss.str();
}
/// @endcond

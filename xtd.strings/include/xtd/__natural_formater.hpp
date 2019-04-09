/// @file
/// @brief Contains __natural_formater method.
#pragma once

/// @cond
#ifndef __XTD_STRINGS_INCLUDE__
#error "Do not include this file yourself, use only #include <xtd/strings>"
#endif
/// @endcond

#include <iomanip>
#include <locale>
#include <string>
#include <sstream>

/// @cond
template<typename Char>
inline std::basic_string<Char> __natural_formater(long double value, int precision, const std::locale& loc) {
  std::basic_stringstream<Char> ss;
  ss.imbue(loc);
  ss << std::fixed << std::setprecision(precision) << value;
  return ss.str();
}
/// @endcond

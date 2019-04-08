/// @file
/// @brief Contains __natural_formater method.
#pragma once
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

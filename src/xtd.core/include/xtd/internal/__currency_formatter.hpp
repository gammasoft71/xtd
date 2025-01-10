/// @file
/// @brief Contains __currency_formatter method.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "__binary_formatter.hpp"

#include <cmath>
#include <iomanip>
#include <locale>
#include <sstream>

/// @cond
template<class char_t>
inline std::basic_string<char_t> __currency_formatter(long double value, const std::locale& loc) {
  std::basic_stringstream<char_t> ss;
  ss.imbue(loc);
  ss << std::showbase << std::fixed << std::put_money(value * std::pow(10, std::use_facet<std::moneypunct<char_t>>(loc).frac_digits()));
  return ss.str();
}
/// @endcond

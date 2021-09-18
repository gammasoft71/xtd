/// @file
/// @brief Contains __currency_formatter method.
#pragma once
/// @cond
#ifndef __XTD_CORE_INTERNAL__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "__binary_formatter.h"

#include <cmath>
#include <locale>
#include <sstream>

/// @cond
template<typename char_t>
inline std::basic_string<char_t> __currency_formatter(long double value, const std::locale& loc) {
  std::basic_stringstream<char_t> ss;
  ss.imbue(loc);
  ss << std::showbase << std::fixed << std::put_money(value*std::pow(10, std::use_facet<std::moneypunct<char_t>>(loc).frac_digits()));
  return ss.str();
}
/// @endcond

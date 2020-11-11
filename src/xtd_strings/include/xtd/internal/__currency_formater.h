/// @file
/// @brief Contains __currency_formater method.
#pragma once

/// @cond
#ifndef __XTD_STRINGS_INCLUDE__
#error "Do not include this file yourself, use only #include <xtd/xtd.strings>"
#endif
/// @endcond

#include "__binary_formater.h"

#include <cmath>
#include <locale>
#include <sstream>

/// @cond
template<typename char_t>
inline std::basic_string<char_t> __currency_formater(long double value, const std::locale& loc) {
  std::basic_stringstream<char_t> ss;
  ss.imbue(loc);
  ss << std::showbase << std::fixed << std::put_money(value*std::pow(10, std::use_facet<std::moneypunct<char_t>>(loc).frac_digits()));
  return ss.str();
}
/// @endcond

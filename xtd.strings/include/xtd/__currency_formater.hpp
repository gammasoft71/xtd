/// @file
/// @brief Contains __currency_formater method.
#pragma once

/// @cond
#ifndef __XTD_STRINGS_INCLUDE__
#error "Do not include this file yourself, use only #include <xtd/strings>"
#endif
/// @ebndcond

#include "__binary_formater.hpp"

#include <cmath>
#include <locale>
#include <sstream>

/// @cond
template<typename Char>
inline std::basic_string<Char> __currency_formater(long double value, const std::locale& loc) {
  std::basic_stringstream<Char> ss;
  ss.imbue(loc);
  ss << std::showbase << std::fixed << std::put_money(value*std::pow(10, std::use_facet<std::moneypunct<Char>>(loc).frac_digits()));
  return ss.str();
}
/// @endcond

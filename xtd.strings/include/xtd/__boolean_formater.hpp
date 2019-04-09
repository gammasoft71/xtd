/// @file
/// @brief Contains __boolean_formater method.
#pragma once

/// @cond
#ifndef __XTD_STRINGS_INCLUDE__
#error "Do not include this file yourself, use only #include <xtd/strings>"
#endif
/// @endcond

#include "__numeric_formater.hpp"

/// @cond
template<typename Char>
inline std::basic_string<Char> __boolean_formater(const std::basic_string<Char>& fmt, bool value, const std::locale& loc) {
  if (fmt.empty()) return value ? std::basic_string<Char> {'t', 'r', 'u', 'e'} : std::basic_string<Char> {'f', 'a', 'l', 's', 'e'};
  
  switch (fmt[0]) {
    case 'b':
    case 'B':
    case 'd':
    case 'D':
    case 'o':
    case 'O':
    case 'x':
    case 'X': return __numeric_formater(fmt, value ? 1 : 0, loc);
    case 'g':
    case 'G': return value ? std::basic_string<Char> {'t', 'r', 'u', 'e'} : std::basic_string<Char> {'f', 'a', 'l', 's', 'e'};
    default: throw std::invalid_argument("Invalid format expression");
  }
}
/// @endcond

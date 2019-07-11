/// @file
/// @brief Contains __binary_formater method.
#pragma once

/// @cond
#ifndef __XTD_STRINGS_INCLUDE__
#error "Do not include this file yourself, use only #include <xtd/xtd.strings>"
#endif
/// @endcond

#include <bitset>
#include "xtd.strings.hpp"

/// @cond
template<typename Char, typename Value>
inline std::basic_string<Char> __binary_formater(Value value, int precision) {
  if (precision < 0) return xtd::strings::pad_right(xtd::strings::trim_start(std::bitset<sizeof(value)*8>(value).to_string(Char('0'), Char('1')), Char('0')), std::abs(precision), Char(' '));
  return xtd::strings::pad_left(xtd::strings::trim_start(std::bitset<sizeof(value)*8>(value).to_string(Char('0'), Char('1')), Char('0')), precision == 0 ? 1 : precision, Char('0'));
}
/// @endcond

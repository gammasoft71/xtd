/// @file
/// @brief Contains __binary_formater method.
#pragma once
/// @cond
#ifndef __XTD_CORE_INTERNAL__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <bitset>
#include "../strings.h"

/// @cond
template<typename char_t, typename Value>
inline std::basic_string<char_t> __binary_formater(Value value, int precision) {
  if (precision < 0) return xtd::strings::pad_right(xtd::strings::trim_start(std::bitset<sizeof(value)*8>(value).to_string(char_t('0'), char_t('1')), char_t('0')), std::abs(precision), char_t(' '));
  return xtd::strings::pad_left(xtd::strings::trim_start(std::bitset<sizeof(value)*8>(value).to_string(char_t('0'), char_t('1')), char_t('0')), precision == 0 ? 1 : precision, char_t('0'));
}
/// @endcond

/// @file
/// @brief Contains __binary_formatter method.
#pragma once
/// @cond
#ifndef __XTD_CORE_INTERNAL__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <bitset>

/// @cond
template<typename char_t, typename value_t>
inline std::basic_string<char_t> __binary_formatter(value_t value, int precision) {
  std::basic_string<char_t> result = std::bitset<sizeof(value)*8>(value).to_string(char_t('0'), char_t('1'));
  while (result[0] != 0 && result[0] == char_t('0'))
    result.erase(0, 1);
  if (precision < 0 && result.size() > size_t(std::abs(precision)))
    result.append(result.size() - std::abs(precision), char_t(' '));
  else {
    if (precision == 0) precision = 1;
    if (size_t(precision) > result.size())
      result.insert(0, size_t(precision) - result.size(), char_t('0'));
  }
  return result;
}
/// @endcond

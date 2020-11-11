/// @file
/// @brief Contains __character_formater method.
#pragma once

/// @cond
#ifndef __XTD_STRINGS_INCLUDE__
#error "Do not include this file yourself, use only #include <xtd/xtd.strings>"
#endif
/// @endcond

#include "__format_stringer.h"

/// @cond
template<typename char_t, typename value_t>
inline std::basic_string<char_t> __character_formater(const std::basic_string<char_t>& fmt, value_t value, const std::locale& loc) {
  std::basic_string<char_t> result;
  char32_t codepoint = value;
  if (codepoint < 0x80) {
    result.push_back(static_cast<char>(codepoint));
  } else  if (codepoint < 0x800) {
    result.push_back(static_cast<char>((codepoint >> 6) | 0xc0));
    result.push_back(static_cast<char>((codepoint & 0x3f) | 0x80));
  } else if (codepoint < 0x10000) {
    result.push_back(static_cast<char>((codepoint >> 12) | 0xe0));
    result.push_back(static_cast<char>(((codepoint >> 6) & 0x3f) | 0x80));
    result.push_back(static_cast<char>((codepoint & 0x3f) | 0x80));
  } else {
    result.push_back(static_cast<char>((codepoint >> 18) | 0xf0));
    result.push_back(static_cast<char>(((codepoint >> 12) & 0x3f) | 0x80));
    result.push_back(static_cast<char>(((codepoint >> 6) & 0x3f) | 0x80));
    result.push_back(static_cast<char>((codepoint & 0x3f) | 0x80));
  }
  return result;
}
/// @endcond

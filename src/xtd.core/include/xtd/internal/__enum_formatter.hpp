/// @file
/// @brief Contains __enum_formatter method.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "__numeric_formatter.hpp"
#include "../helpers/throw_helper.hpp"

/// @cond
template<class enum_t>
[[nodiscard]] auto __enum_to_string__(enum_t value) noexcept -> std::string;

template<class char_t, class value_t>
[[nodiscard]] inline auto __enum_formatter(const std::basic_string<char_t>& format, value_t value, const std::locale& loc) -> std::basic_string<char_t> {
  auto fmt = format;
  if (fmt.empty()) fmt = {'G'};
  
  switch (fmt[0]) {
    case 'b':
    case 'B':
    case 'd':
    case 'D':
    case 'o':
    case 'O':
    case 'x':
    case 'X': return __numeric_formatter(fmt, static_cast<long long int>(value), loc);
    case 'g':
    case 'G': return __enum_to_string__(value);
    default: xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format, "Invalid format expression");
  }
}
/// @endcond

/// @file
/// @brief Contains __duration_formater method.
#pragma once
/// @cond
#ifndef __XTD_CORE_INTERNAL__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../strings.h"
#include "__format_exception.h"
#include <chrono>
#include <ratio>

/// @cond
#define __GCC_VERSION__ (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#if !defined(WIN32) && (__cplusplus < 201707L || (!__clang__ && __GCC_VERSION__ < 100000))
namespace std {
  namespace chrono {
    using days = std::chrono::duration<long, std::ratio<86400>>;
  }
}
#endif

template<typename char_t, typename type_t, typename period_t = std::ratio<1>>
inline std::basic_string<char_t> __make_string_from_duration(std::chrono::duration<type_t, period_t> value, bool constant = true) {
  std::basic_string<char_t> result;
  
  if (value.count() < 0)
    result += '-';
  value = std::chrono::duration<type_t, period_t>(std::abs(value.count()));
  if (std::chrono::duration_cast<std::chrono::days>(value).count())
    result += xtd::strings::format(std::basic_string<char_t> {'{', ':', 'D', '}', '.'}, std::chrono::duration_cast<std::chrono::days>(value).count());
  result += xtd::strings::format(constant ? std::basic_string<char_t> {'{', ':', 'D', '2', '}', ':', '{', ':', 'D', '2', '}', ':', '{', ':', 'D', '2', '}'} : std::basic_string<char_t> {'{', ':', 'D', '}', ':', '{', ':', 'D', '2', '}', ':', '{', ':', 'D', '2', '}'}, std::chrono::duration_cast<std::chrono::hours>(value).count() % 24, std::chrono::duration_cast<std::chrono::minutes>(value).count() % 60, std::chrono::duration_cast<std::chrono::seconds>(value).count() % 60);
  if (std::chrono::duration_cast<std::chrono::nanoseconds>(value).count() % 1000000000)
    result += xtd::strings::format(std::basic_string<char_t> {':', '{', ':', 'D', '9', '}'}, std::chrono::duration_cast<std::chrono::nanoseconds>(value).count() % 1000000000);
  
  return result;
}

template<typename char_t, typename type_t, typename period_t = std::ratio<1>>
inline std::basic_string<char_t> __duration_formater(std::basic_string<char_t> fmt, const std::chrono::duration<type_t, period_t>& value, const std::locale& loc) {
  if (fmt.empty()) fmt =  xtd::strings::format(std::basic_string<char_t> {'G'});
  if (fmt.size() > 1) __format_exception("Invalid format");
  
  switch (fmt[0]) {
    case 'c': return __make_string_from_duration<char_t>(value);
    case 'd': return xtd::strings::format(std::basic_string<char_t> {'{', ':', 'D', '}'}, std::chrono::duration_cast<std::chrono::days>(value).count());
    case 'D': return xtd::strings::format(std::basic_string<char_t> {'{', ':', 'D', '2', '}'}, std::chrono::duration_cast<std::chrono::days>(value).count());
    case 'f': return xtd::strings::format(std::basic_string<char_t> {'{', ':', 'D', '}', ':', '{', ':', 'D', '}', ':', '{', ':', 'D', '2', '}', ':', '{', ':', 'D', '2', '}', ':', '{', ':', 'D', '9', '}'}, std::chrono::duration_cast<std::chrono::days>(value).count(), std::chrono::duration_cast<std::chrono::hours>(value).count() % 24, std::chrono::duration_cast<std::chrono::minutes>(value).count() % 60, std::chrono::duration_cast<std::chrono::seconds>(value).count() % 60, std::chrono::duration_cast<std::chrono::nanoseconds>(value).count() % 1000000000);
    case 'F': return xtd::strings::format(std::basic_string<char_t> {'{', ':', 'D', '}', ':', '{', ':', 'D', '2', '}', ':', '{', ':', 'D', '2', '}', ':', '{', ':', 'D', '2', '}', ':', '{', ':', 'D', '9', '}'}, std::chrono::duration_cast<std::chrono::days>(value).count(), std::chrono::duration_cast<std::chrono::hours>(value).count() % 24, std::chrono::duration_cast<std::chrono::minutes>(value).count() % 60, std::chrono::duration_cast<std::chrono::seconds>(value).count() % 60, std::chrono::duration_cast<std::chrono::nanoseconds>(value).count() % 1000000000);
    case 'g': return __make_string_from_duration<char_t>(value, false);
    case 'G': return __make_string_from_duration<char_t>(value);
    case 'h': return xtd::strings::format(std::basic_string<char_t> {'{', ':', 'D', '}'}, std::chrono::duration_cast<std::chrono::hours>(value).count() % 24);
    case 'H': return xtd::strings::format(std::basic_string<char_t> {'{', ':', 'D', '2', '}'}, std::chrono::duration_cast<std::chrono::hours>(value).count() % 24);
    case 'm': return xtd::strings::format(std::basic_string<char_t> {'{', ':', 'D', '}'}, std::chrono::duration_cast<std::chrono::minutes>(value).count() % 60);
    case 'M': return xtd::strings::format(std::basic_string<char_t> {'{', ':', 'D', '2', '}'}, std::chrono::duration_cast<std::chrono::minutes>(value).count() % 60);
    case 'n': return xtd::strings::format(std::basic_string<char_t> {'{', ':', 'D', '}'}, std::chrono::duration_cast<std::chrono::nanoseconds>(value).count() % 1000000000);
    case 'N': return xtd::strings::format(std::basic_string<char_t> {'{', ':', 'D', '9', '}'}, std::chrono::duration_cast<std::chrono::nanoseconds>(value).count() % 1000000000);
    case 's': return xtd::strings::format(std::basic_string<char_t> {'{', ':', 'D', '}'}, std::chrono::duration_cast<std::chrono::seconds>(value).count() % 60);
    case 'S': return xtd::strings::format(std::basic_string<char_t> {'{', ':', 'D', '2', '}'}, std::chrono::duration_cast<std::chrono::seconds>(value).count() % 60);
    default: __format_exception("Invalid format"); return {};
  }
}
/// @endcond

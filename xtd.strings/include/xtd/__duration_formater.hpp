/// @file
/// @brief Contains __duration_formater method.
#pragma once

/// @cond
#ifndef __XTD_STRINGS_INCLUDE__
#error "Do not include this file yourself, use only #include <xtd/strings>"
#endif
/// @ebndcond

#include "strings.hpp"
#include <chrono>
#include <ratio>

/// @cond
#if __cplusplus <= 201703L
namespace std {
  using days = std::chrono::duration<long, std::ratio<86400>>;
}
#endif

template<typename Char, typename Type, typename Period = std::ratio<1>>
inline std::basic_string<Char> __make_string_from_duration(std::chrono::duration<Type, Period> value, bool constant = true) {
  std::basic_string<Char> result;
  
  if (value.count() < 0)
    result += '-';
  value = std::chrono::duration<Type, Period>(std::abs(value.count()));
  if (std::chrono::duration_cast<std::days>(value).count())
    result += xtd::strings::format(std::basic_string<Char> {'{', ':', 'D', '}', '.'}, std::chrono::duration_cast<std::days>(value).count());
  result += xtd::strings::format(constant ? std::basic_string<Char> {'{', ':', 'D', '2', '}', ':', '{', ':', 'D', '2', '}', ':', '{', ':', 'D', '2', '}'} : std::basic_string<Char> {'{', ':', 'D', '}', ':', '{', ':', 'D', '2', '}', ':', '{', ':', 'D', '2', '}'}, std::chrono::duration_cast<std::chrono::hours>(value).count() % 24, std::chrono::duration_cast<std::chrono::minutes>(value).count() % 60, std::chrono::duration_cast<std::chrono::seconds>(value).count() % 60);
  if (std::chrono::duration_cast<std::chrono::nanoseconds>(value).count() % 1000000000)
    result += xtd::strings::format(std::basic_string<Char> {':', '{', ':', 'D', '9', '}'}, std::chrono::duration_cast<std::chrono::nanoseconds>(value).count() % 1000000000);
  
  return result;
}

template<typename Char, typename Type, typename Period = std::ratio<1>>
inline std::basic_string<Char> __duration_formater(std::basic_string<Char> fmt, const std::chrono::duration<Type, Period>& value, const std::locale& loc) {
  if (fmt.empty()) fmt =  xtd::strings::format(std::basic_string<Char> {'G'});
  if (fmt.size() > 1) throw std::invalid_argument("Invalid format");
  
  switch (fmt[0]) {
    case 'c': return __make_string_from_duration<Char>(value);
    case 'd': return xtd::strings::format(std::basic_string<Char> {'{', ':', 'D', '}'}, std::chrono::duration_cast<std::days>(value).count());
    case 'D': return xtd::strings::format(std::basic_string<Char> {'{', ':', 'D', '2', '}'}, std::chrono::duration_cast<std::days>(value).count());
    case 'f': return xtd::strings::format(std::basic_string<Char> {'{', ':', 'D', '}', ':', '{', ':', 'D', '}', ':', '{', ':', 'D', '2', '}', ':', '{', ':', 'D', '2', '}', ':', '{', ':', 'D', '9', '}'}, std::chrono::duration_cast<std::days>(value).count(), std::chrono::duration_cast<std::chrono::hours>(value).count() % 24, std::chrono::duration_cast<std::chrono::minutes>(value).count() % 60, std::chrono::duration_cast<std::chrono::seconds>(value).count() % 60, std::chrono::duration_cast<std::chrono::nanoseconds>(value).count() % 1000000000);
    case 'F': return xtd::strings::format(std::basic_string<Char> {'{', ':', 'D', '}', ':', '{', ':', 'D', '2', '}', ':', '{', ':', 'D', '2', '}', ':', '{', ':', 'D', '2', '}', ':', '{', ':', 'D', '9', '}'}, std::chrono::duration_cast<std::days>(value).count(), std::chrono::duration_cast<std::chrono::hours>(value).count() % 24, std::chrono::duration_cast<std::chrono::minutes>(value).count() % 60, std::chrono::duration_cast<std::chrono::seconds>(value).count() % 60, std::chrono::duration_cast<std::chrono::nanoseconds>(value).count() % 1000000000);
    case 'g': return __make_string_from_duration<Char>(value, false);
    case 'G': return __make_string_from_duration<Char>(value);
    case 'h': return xtd::strings::format(std::basic_string<Char> {'{', ':', 'D', '}'}, std::chrono::duration_cast<std::chrono::hours>(value).count() % 24);
    case 'H': return xtd::strings::format(std::basic_string<Char> {'{', ':', 'D', '2', '}'}, std::chrono::duration_cast<std::chrono::hours>(value).count() % 24);
    case 'm': return xtd::strings::format(std::basic_string<Char> {'{', ':', 'D', '}'}, std::chrono::duration_cast<std::chrono::minutes>(value).count() % 60);
    case 'M': return xtd::strings::format(std::basic_string<Char> {'{', ':', 'D', '2', '}'}, std::chrono::duration_cast<std::chrono::minutes>(value).count() % 60);
    case 'n': return xtd::strings::format(std::basic_string<Char> {'{', ':', 'D', '}'}, std::chrono::duration_cast<std::chrono::nanoseconds>(value).count() % 1000000000);
    case 'N': return xtd::strings::format(std::basic_string<Char> {'{', ':', 'D', '9', '}'}, std::chrono::duration_cast<std::chrono::nanoseconds>(value).count() % 1000000000);
    case 's': return xtd::strings::format(std::basic_string<Char> {'{', ':', 'D', '}'}, std::chrono::duration_cast<std::chrono::seconds>(value).count() % 60);
    case 'S': return xtd::strings::format(std::basic_string<Char> {'{', ':', 'D', '2', '}'}, std::chrono::duration_cast<std::chrono::seconds>(value).count() % 60);
    default: throw std::invalid_argument("Invalid format");
  }
  throw std::invalid_argument("Invalid format");
}
/// @endcond

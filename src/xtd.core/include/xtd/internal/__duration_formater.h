/// @file
/// @brief Contains __duration_formater method.
#pragma once
/// @cond
#ifndef __XTD_CORE_INTERNAL__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "__format_exception.h"
#include "__sprintf.h"
#include <chrono>
#include <ratio>

/// @cond
#define __GCC_VERSION__ (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#if (_MSC_VER && _MSC_VER < 1929) || (!__clang__ && !_MSC_VER && __GCC_VERSION__ < 100000)
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
    result += __sprintf(std::basic_string<char_t> {'%', 'd', '.'}.c_str(), std::chrono::duration_cast<std::chrono::days>(value).count());
  result += __sprintf(constant ? std::basic_string<char_t> {'%', '0', '2', 'd', ':', '%', '0', '2', 'd', ':', '%', '0', '2', 'd'}.c_str() : std::basic_string<char_t> {'%', 'd', ':', '%', '0', '2', 'd', ':', '%', '0', '2', 'd'}.c_str(), std::chrono::duration_cast<std::chrono::hours>(value).count() % 24, std::chrono::duration_cast<std::chrono::minutes>(value).count() % 60, std::chrono::duration_cast<std::chrono::seconds>(value).count() % 60);
  if (std::chrono::duration_cast<std::chrono::nanoseconds>(value).count() % 1000000000UL)
    result += __sprintf(std::basic_string<char_t> {':', '%', '0', '9', 'l', 'u'}.c_str(), std::chrono::duration_cast<std::chrono::nanoseconds>(value).count() % 1000000000UL);
  
  return result;
}

template<typename char_t, typename type_t, typename period_t = std::ratio<1>>
inline std::basic_string<char_t> __duration_formater(std::basic_string<char_t> fmt, const std::chrono::duration<type_t, period_t>& value, const std::locale& loc) {
  if (fmt.empty()) fmt = std::basic_string<char_t> {'G'};
  if (fmt.size() > 1) __format_exception("Invalid format");
  
  switch (fmt[0]) {
    case 'c': return __make_string_from_duration<char_t>(value);
    case 'd': return __sprintf(std::basic_string<char_t> {'%', 'd'}.c_str(), std::chrono::duration_cast<std::chrono::days>(value).count());
    case 'D': return __sprintf(std::basic_string<char_t> {'%', '0', '2', 'd'}.c_str(), std::chrono::duration_cast<std::chrono::days>(value).count());
    case 'f': return __sprintf(std::basic_string<char_t> {'%', 'd', ':', '%', 'd', ':', '%', '0', '2', 'd', ':', '%', '0', '2', 'd', ':', '%', '0', '9', 'l', 'u'}.c_str(), std::chrono::duration_cast<std::chrono::days>(value).count(), std::chrono::duration_cast<std::chrono::hours>(value).count() % 24, std::chrono::duration_cast<std::chrono::minutes>(value).count() % 60, std::chrono::duration_cast<std::chrono::seconds>(value).count() % 60, std::chrono::duration_cast<std::chrono::nanoseconds>(value).count() % 1000000000UL);
    case 'F': return __sprintf(std::basic_string<char_t> {'%', 'd', ':', '%', '0', '2', 'd', ':', '%', '0', '2', 'd', ':', '%', '0', '2', 'd', ':', '%', '0', '9', 'l', 'u'}.c_str(), std::chrono::duration_cast<std::chrono::days>(value).count(), std::chrono::duration_cast<std::chrono::hours>(value).count() % 24, std::chrono::duration_cast<std::chrono::minutes>(value).count() % 60, std::chrono::duration_cast<std::chrono::seconds>(value).count() % 60, std::chrono::duration_cast<std::chrono::nanoseconds>(value).count() % 1000000000UL);
    case 'g': return __make_string_from_duration<char_t>(value, false);
    case 'G': return __make_string_from_duration<char_t>(value);
    case 'h': return __sprintf(std::basic_string<char_t> {'%', 'd'}.c_str(), std::chrono::duration_cast<std::chrono::hours>(value).count() % 24);
    case 'H': return __sprintf(std::basic_string<char_t> {'%', '0', '2', 'd'}.c_str(), std::chrono::duration_cast<std::chrono::hours>(value).count() % 24);
    case 'm': return __sprintf(std::basic_string<char_t> {'%', 'd'}.c_str(), std::chrono::duration_cast<std::chrono::minutes>(value).count() % 60);
    case 'M': return __sprintf(std::basic_string<char_t> {'%', '0', '2', 'd'}.c_str(), std::chrono::duration_cast<std::chrono::minutes>(value).count() % 60);
    case 'n': return __sprintf(std::basic_string<char_t> {'%', 'l', 'u'}.c_str(), std::chrono::duration_cast<std::chrono::nanoseconds>(value).count() % 1000000000UL);
    case 'N': return __sprintf(std::basic_string<char_t> {'%', '0', '9', 'l', 'u'}.c_str(), std::chrono::duration_cast<std::chrono::nanoseconds>(value).count() % 1000000000UL);
    case 's': return __sprintf(std::basic_string<char_t> {'%', 'd'}.c_str(), std::chrono::duration_cast<std::chrono::seconds>(value).count() % 60);
    case 'S': return __sprintf(std::basic_string<char_t> {'%', '0', '2', 'd'}.c_str(), std::chrono::duration_cast<std::chrono::seconds>(value).count() % 60);
    default: __format_exception("Invalid format"); return {};
  }
}
/// @endcond

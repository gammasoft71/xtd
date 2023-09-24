/// @file
/// @brief Contains __duration_formatter method.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "__format_exception"
#include "__sprintf"
#include "../chrono"

/// @cond
template<typename char_t, typename type_t, typename period_t = std::ratio<1>>
inline std::basic_string<char_t> __make_string_from_duration(std::chrono::duration<type_t, period_t> value, bool constant = true) {
  std::basic_string<char_t> result;
  
  if (value.count() < 0)
    result += '-';
  value = std::chrono::duration<type_t, period_t>(std::abs(value.count()));
  if (std::chrono::duration_cast<std::chrono::days>(value).count())
    result += __sprintf(std::basic_string<char_t> {'%', 'd', '.'}.c_str(), std::chrono::duration_cast<std::chrono::days>(value).count());
  result += __sprintf(constant ? std::basic_string<char_t> {'%', '0', '2', 'd', ':', '%', '0', '2', 'd', ':', '%', '0', '2', 'd'}.c_str() : std::basic_string<char_t> {'%', 'd', ':', '%', '0', '2', 'd', ':', '%', '0', '2', 'd'}.c_str(), std::chrono::duration_cast<std::chrono::hours>(value).count() % 24, std::chrono::duration_cast<std::chrono::minutes>(value).count() % 60, std::chrono::duration_cast<std::chrono::seconds>(value).count() % 60);
  if (std::chrono::duration_cast<std::chrono::nanoseconds>(value).count() % 1000000000ul)
    result += __sprintf(std::basic_string<char_t> {':', '%', '0', '9', 'l', 'u'}.c_str(), std::chrono::duration_cast<std::chrono::nanoseconds>(value).count() % 1000000000ul);
    
  return result;
}

template<typename char_t, typename type_t, typename period_t = std::ratio<1>>
inline std::basic_string<char_t> __duration_formatter(std::basic_string<char_t> fmt, const std::chrono::duration<type_t, period_t>& value, const std::locale& loc) {
  if (fmt.empty()) fmt = std::basic_string<char_t> {'G'};
  if (fmt.size() > 1) __format_exception("Invalid format");
  
  switch (fmt[0]) {
    case 'c': return __make_string_from_duration<char_t>(value);
    case 'd': return __sprintf(std::basic_string<char_t> {'%', 'd'}.c_str(), std::abs(std::chrono::duration_cast<std::chrono::days>(value).count()));
    case 'D': return __sprintf(std::basic_string<char_t> {'%', '0', '2', 'd'}.c_str(), std::abs(std::chrono::duration_cast<std::chrono::days>(value).count()));
    case 'f': return __sprintf(value.count() < 0 ? std::basic_string<char_t> {'-', '%', 'd', '.', '%', 'd', ':', '%', '0', '2', 'd', ':', '%', '0', '2', 'd', ':', '%', '0', '9', 'd'}.c_str() : std::basic_string<char_t> {'%', 'd', '.', '%', 'd', ':', '%', '0', '2', 'd', ':', '%', '0', '2', 'd', ':', '%', '0', '9', 'l', 'u'}.c_str(), std::abs(std::chrono::duration_cast<std::chrono::days>(value).count()), std::abs(std::chrono::duration_cast<std::chrono::hours>(value).count() % 24), std::abs(std::chrono::duration_cast<std::chrono::minutes>(value).count() % 60), std::abs(std::chrono::duration_cast<std::chrono::seconds>(value).count() % 60), std::abs(std::chrono::duration_cast<std::chrono::nanoseconds>(value).count() % 1000000000));
    case 'F': return __sprintf(value.count() < 0 ? std::basic_string<char_t> {'-', '%', 'd', '.', '%', '0', '2', 'd', ':', '%', '0', '2', 'd', ':', '%', '0', '2', 'd', ':', '%', '0', '9', 'd'}.c_str() : std::basic_string<char_t> {'%', 'd', '.', '%', '0', '2', 'd', ':', '%', '0', '2', 'd', ':', '%', '0', '2', 'd', ':', '%', '0', '9', 'l', 'u'}.c_str(), std::abs(std::chrono::duration_cast<std::chrono::days>(value).count()), std::abs(std::chrono::duration_cast<std::chrono::hours>(value).count() % 24), std::abs(std::chrono::duration_cast<std::chrono::minutes>(value).count() % 60), std::abs(std::chrono::duration_cast<std::chrono::seconds>(value).count() % 60), std::abs(std::chrono::duration_cast<std::chrono::nanoseconds>(value).count() % 1000000000));
    case 'g': return __make_string_from_duration<char_t>(value, false);
    case 'G': return __make_string_from_duration<char_t>(value);
    case 'h': return __sprintf(std::basic_string<char_t> {'%', 'd'}.c_str(), std::abs(std::chrono::duration_cast<std::chrono::hours>(value).count() % 24));
    case 'H': return __sprintf(std::basic_string<char_t> {'%', '0', '2', 'd'}.c_str(), std::abs(std::chrono::duration_cast<std::chrono::hours>(value).count() % 24));
    case 'l': return __sprintf(std::basic_string<char_t> {'%', 'd'}.c_str(), std::abs(std::chrono::duration_cast<std::chrono::milliseconds>(value).count() % 1000));
    case 'L': return __sprintf(std::basic_string<char_t> {'%', '0', '3', 'd'}.c_str(), std::abs(std::chrono::duration_cast<std::chrono::milliseconds>(value).count() % 1000));
    case 'm': return __sprintf(std::basic_string<char_t> {'%', 'd'}.c_str(), std::abs(std::chrono::duration_cast<std::chrono::minutes>(value).count() % 60));
    case 'M': return __sprintf(std::basic_string<char_t> {'%', '0', '2', 'd'}.c_str(), std::abs(std::chrono::duration_cast<std::chrono::minutes>(value).count() % 60));
    case 'n': return __sprintf(std::basic_string<char_t> {'%', 'l', 'u'}.c_str(), std::abs(std::chrono::duration_cast<std::chrono::nanoseconds>(value).count() % 1000000000));
    case 'N': return __sprintf(std::basic_string<char_t> {'%', '0', '9', 'l', 'u'}.c_str(), std::abs(std::chrono::duration_cast<std::chrono::nanoseconds>(value).count() % 1000000000));
    case 'o': return value.count() < 0 ? "-" : "";
    case 'p': return value.count() < 0 ? "-" : "+";
    case 's': return __sprintf(std::basic_string<char_t> {'%', 'd'}.c_str(), std::abs(std::chrono::duration_cast<std::chrono::seconds>(value).count() % 60));
    case 'S': return __sprintf(std::basic_string<char_t> {'%', '0', '2', 'd'}.c_str(), std::abs(std::chrono::duration_cast<std::chrono::seconds>(value).count() % 60));
    default: __format_exception("Invalid format"); return {};
  }
}
/// @endcond

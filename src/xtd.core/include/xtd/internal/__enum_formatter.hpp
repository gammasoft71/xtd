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
std::string __enum_to_string__(enum_t value) noexcept;

template<class char_t, class value_t>
inline std::basic_string<char_t> __enum_formatter(const std::basic_string<char_t>& format, value_t value, const std::locale& loc) {
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

template<class value_t>
inline static std::string __to_string_enum(const value_t& value, const std::string& fmt, const std::locale& loc, std::true_type) {return __enum_formatter(fmt, value, loc);}

template<class value_t>
inline static std::string __to_string_enum(const value_t& value, const std::string& fmt, const std::locale& loc, std::false_type) {
  xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format_not_iformatable, typeid(value));
}

template<class value_t>
inline static std::wstring __to_string_enum(const value_t& value, const std::wstring& fmt, const std::locale& loc, std::true_type) {return __enum_formatter(fmt, value, loc);}

template<class value_t>
inline static std::wstring __to_string_enum(const value_t& value, const std::wstring& fmt, const std::locale& loc, std::false_type) {
  xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format_not_iformatable, typeid(value));
}
/// @endcond

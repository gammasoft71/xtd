/// @file
/// @brief Contains __enum_formater method.
#pragma once

/// @cond
#ifndef __XTD_STRINGS_INCLUDE__
#error "Do not include this file yourself, use only #include <xtd/xtd.strings>"
#endif
/// @endcond

#include "__numeric_formater.h"

/// @cond
template<typename char_t, typename value_t>
inline std::basic_string<char_t> __enum_formater(const std::basic_string<char_t>& fmt, value_t value, const std::locale& loc) {
  if (fmt.empty()) return __format_stringer<char_t>(value);
  
  switch (fmt[0]) {
    case 'b':
    case 'B':
    case 'd':
    case 'D':
    case 'o':
    case 'O':
    case 'x':
    case 'X': return __numeric_formater(fmt, static_cast<long long int>(value), loc);
    case 'g':
    case 'G': return __format_stringer<char_t>(value);
    default: throw std::invalid_argument("Invalid format expression");
  }
}

template<typename value_t>
static std::string __to_string_enum(const value_t& value, const std::string& fmt, const std::locale& loc, std::true_type) {return __enum_formater(fmt, value, loc);}

template<typename value_t>
static std::string __to_string_enum(const value_t& value, const std::string& fmt, const std::locale& loc, std::false_type) {throw std::invalid_argument("to_string speciailisation not found");}

template<typename value_t>
static std::wstring __to_string_enum(const value_t& value, const std::wstring& fmt, const std::locale& loc, std::true_type) {return __enum_formater(fmt, value, loc);}

template<typename value_t>
static std::wstring __to_string_enum(const value_t& value, const std::wstring& fmt, const std::locale& loc, std::false_type) {throw std::invalid_argument("to_string speciailisation not found");}
/// @endcond

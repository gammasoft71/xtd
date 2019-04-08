/// @file
/// @brief Contains __enum_formater method.
#pragma once

/// @cond
#ifndef __XTD_STRINGS_INCLUDE__
#error "Do not include this file yourself, use only #include <xtd/strings>"
#endif
/// @ebndcond

#include "__numeric_formater.hpp"

/// @cond
template<typename Char, typename Value>
inline std::basic_string<Char> __enum_formater(const std::basic_string<Char>& fmt, Value value, const std::locale& loc) {
  if (fmt.empty()) return __format_stringer<Char>(value);
  
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
    case 'G': return __format_stringer<Char>(value);
    default: throw std::invalid_argument("Invalid format expression");
  }
}

template<typename Value>
static std::string __to_string_enum(const Value& value, const std::string& fmt, const std::locale& loc, std::true_type) {return __enum_formater(fmt, value, loc);}

template<typename Value>
static std::string __to_string_enum(const Value& value, const std::string& fmt, const std::locale& loc, std::false_type) {throw std::invalid_argument("to_string speciailisation not found");}

template<typename Value>
static std::wstring __to_string_enum(const Value& value, const std::wstring& fmt, const std::locale& loc, std::true_type) {return __enum_formater(fmt, value, loc);}

template<typename Value>
static std::wstring __to_string_enum(const Value& value, const std::wstring& fmt, const std::locale& loc, std::false_type) {throw std::invalid_argument("to_string speciailisation not found");}
/// @endcond

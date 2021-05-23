/// @file
/// @brief Contains __enum_formater method.
#pragma once
/// @cond
#ifndef __XTD_CORE_INTERNAL__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "__numeric_formater.h"
#include "__format_exception.h"

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
    default: __format_exception("Invalid format expression"); return {};
  }
}

template<typename value_t>
static std::string __to_string_enum(const value_t& value, const std::string& fmt, const std::locale& loc, std::true_type) {return __enum_formater(fmt, value, loc);}

template<typename value_t>
static std::string __to_string_enum(const value_t& value, const std::string& fmt, const std::locale& loc, std::false_type) {__format_exception("to_string speciailisation not found"); return {};}

template<typename value_t>
static std::wstring __to_string_enum(const value_t& value, const std::wstring& fmt, const std::locale& loc, std::true_type) {return __enum_formater(fmt, value, loc);}

template<typename value_t>
static std::wstring __to_string_enum(const value_t& value, const std::wstring& fmt, const std::locale& loc, std::false_type) {__format_exception("to_string speciailisation not found"); return {};}
/// @endcond

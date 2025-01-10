/// @file
/// @brief Contains __enum_formatter method.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "__numeric_formatter.hpp"
#include "__format_exception.hpp"

/// @cond
template<class enum_t>
std::string __enum_to_string(enum_t value) noexcept;

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
    case 'G': return __enum_to_string(value);
    default: __format_exception("Invalid format expression"); return {};
  }
}

template<class value_t>
static std::string __to_string_enum(const value_t& value, const std::string& fmt, const std::locale& loc, std::true_type) {return __enum_formatter(fmt, value, loc);}

template<class value_t>
static std::string __to_string_enum(const value_t& value, const std::string& fmt, const std::locale& loc, std::false_type) {
  __format_exception(typeid(value)); return {};
}

template<class value_t>
static std::wstring __to_string_enum(const value_t& value, const std::wstring& fmt, const std::locale& loc, std::true_type) {return __enum_formatter(fmt, value, loc);}

template<class value_t>
static std::wstring __to_string_enum(const value_t& value, const std::wstring& fmt, const std::locale& loc, std::false_type) {
  __format_exception(typeid(value)); return {};
}
/// @endcond

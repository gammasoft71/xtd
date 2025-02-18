/// @file
/// @brief Contains __polymorphic_formatter__ class.
#pragma once
#include <bitset>
#include <cmath>
#include <cstdarg>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>
#include "../helpers/throw_helper.hpp"
#include "../iformatable.hpp"
#include "../int32.hpp"
#include "../int64.hpp"
#include "../istringable.hpp"
#include "../object.hpp"

/// @cond
// defined in enum_object.hpp
// {
template<class enum_t>
std::string __enum_to_string__(enum_t value) noexcept;
// }

// defined in object.cpp
// {
std::string __object_to_string__(const xtd::object& obj) noexcept;
std::string __istringable_to_string__(const xtd::istringable& stringable) noexcept;
// }

inline const char* __sprintf__(const char* fmt, ...) noexcept {
  std::va_list args;
  va_start(args, fmt);
  thread_local auto result = std::string(vsnprintf(nullptr, 0, fmt, args), 0);
  va_end(args);
  va_start(args, fmt);
  vsnprintf(&result[0], result.size() + 1, fmt, args);
  va_end(args);
  if (result == "INF") result = "inf";
  if (result == "-INF") result = "-inf";
  if (result == "NAN") result = "nan";
  return result.c_str();
}

template<class value_t>
inline std::string __binary_formatter__(value_t value, xtd::int32 precision) {
  auto result = std::bitset<sizeof(value) * 8>(value).to_string('0', '1');
  while (result[0] != 0 && result[0] == '0')
    result.erase(0, 1);
  if (precision < 0 && result.size() > size_t(std::abs(precision)))
    result.append(result.size() - std::abs(precision), ' ');
  else {
    if (precision == 0) precision = 1;
    if (size_t(precision) > result.size())
      result.insert(0, size_t(precision) - result.size(), '0');
  }
  return result;
}

inline std::string __currency_formatter__(long double value, const std::locale& locale) {
  auto ss = std::stringstream {};
  ss.imbue(locale);
  ss << std::showbase << std::fixed << std::put_money(value * std::pow(10, std::use_facet<std::moneypunct<char>>(locale).frac_digits()));
  return ss.str();
}

inline std::string __hexfloat_formatter__(long double value, xtd::int32 precision, const std::locale& loc) {
  auto ss = std::stringstream {};
  ss.imbue(loc);
  ss << std::hexfloat << std::setprecision(precision) << value;
  return ss.str();
}

template<class floating_point_t>
inline std::string __floating_point_to_binary__(floating_point_t value, xtd::int32 precision) {
  union {
    double input;
    int64_t output;
  } data;
  data.input = value;
  return __binary_formatter__(data.output, precision);
}

inline std::string __natural_formatter__(long double value, xtd::int32 precision, const std::locale& locale) {
  auto ss = std::stringstream {};
  ss.imbue(locale);
  ss << std::fixed << std::setprecision(precision) << value;
  return ss.str();
}

template <>
inline std::string __floating_point_to_binary__<long double>(long double value, xtd::int32 precision) {
  union {
    long double input;
    int64_t output;
  } data;
  data.input = value;
  return __binary_formatter__(data.output, precision);
}

template <>
inline std::string __floating_point_to_binary__<double>(double value, xtd::int32 precision) {
  union {
    double input;
    int64_t output;
  } data;
  data.input = value;
  return __binary_formatter__(data.output, precision);
}

template <>
inline std::string __floating_point_to_binary__<float>(float value, xtd::int32 precision) {
  union {
    float input;
    int32_t output;
  } data;
  data.input = value;
  return __binary_formatter__(data.output, precision);
}

template<class type_t>
inline std::string __floating_point_formatter__(type_t value, const std::string& format, const std::locale& locale) {
  auto fmt = !format.empty() ? format : "G";
  auto possible_formats = {'b', 'B', 'c', 'C', 'e', 'E', 'f', 'F', 'g', 'G', 'n', 'N', 'p', 'P', 'x', 'X'};
  if (fmt.size() > 3 || std::find(possible_formats.begin(), possible_formats.end(), fmt[0]) == possible_formats.end() || (fmt.size() >= 2 && !std::isdigit(fmt[1])) || (fmt.size() == 3 && !std::isdigit(fmt[2])))
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format, "Custom format not yet implemented");
  
  auto precision = 0;
  try {
    if (fmt.size() > 1) precision = std::stoi(fmt.substr(1));
  } catch (...) {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format, "Invalid format expression");
  }
  if ((fmt[0] == 'f' || fmt[0] == 'F' || fmt[0] == 'n' || fmt[0] == 'N' || fmt[0] == 'p' || fmt[0] == 'P' || fmt[0] == 'r' || fmt[0] == 'R') && fmt.size() == 1) precision = 2;
  if ((fmt[0] == 'e' || fmt[0] == 'E') && fmt.size() == 1) precision = 6;
  if ((fmt[0] == 'g' || fmt[0] == 'G') && fmt.size() == 1) precision = sizeof(value) <= 4 ? 7 : 15;
  
  auto fmt_str = std::string {"%.*L"};
  switch (fmt[0]) {
    case 'b':
    case 'B': return __floating_point_to_binary__<char>(value, precision);
    case 'c':
    case 'C': return __currency_formatter__(static_cast<long double>(value), locale);
    case 'e':
    case 'E':
    case 'f':
    case 'F':
    case 'g':
    case 'G': return __sprintf__((fmt_str + fmt[0]).c_str(), precision, static_cast<long double>(value));
    case 'n':
    case 'N': return __natural_formatter__(static_cast<long double>(value), precision, locale);
    case 'p': return std::string {__sprintf__((fmt_str + 'f').c_str(), precision, static_cast<long double>(value * 100))} + std::string {" %"};
    case 'P': return std::string {__sprintf__((fmt_str + 'F').c_str(), precision, static_cast<long double>(value * 100))} + std::string {" %"};
    case 'x':
    case 'X': return __hexfloat_formatter__(static_cast<long double>(value), precision, locale);
    default: xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format, "Invalid format expression");
  }
}

template<class type_t>
inline std::string __numeric_formatter__(type_t value, const std::string& format, const std::locale& locale) {
  auto fmt = !format.empty() ? format : "G";
  auto possible_formats = {'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F', 'g', 'G', 'n', 'N', 'o', 'O', 'p', 'P', 'x', 'X'};
  if (fmt.size() > 3 || std::find(possible_formats.begin(), possible_formats.end(), fmt[0]) == possible_formats.end() || (fmt.size() >= 2 && !std::isdigit(fmt[1])) || (fmt.size() == 3 && !std::isdigit(fmt[2])))
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format, "Custom fmt not yet implemented");
  
  auto precision = 0;
  if (fmt[0] == 'b' || fmt[0] == 'B' || fmt[0] == 'd' || fmt[0] == 'D' || fmt[0] == 'o' || fmt[0] == 'O' || fmt[0] == 'x' || fmt[0] == 'X') {
    try {
      for (auto c : fmt.substr(1))
        if (!std::isdigit(c) && c != ' ' && c != '+' && c != '-') xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format, "Invalid fmt expression");
      if (fmt.size() > 1) precision = std::stoi(fmt.substr(1));
    } catch (...) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format, "Invalid fmt expression");
    }
    if ((fmt[0] == 'd' || fmt[0] == 'D') && precision > 0 && value < 0) precision += 1;
    if ((fmt[0] == 'd' || fmt[0] == 'D') && precision < 0 && value < 0) precision -= 1;
  }
  
  switch (fmt[0]) {
    case 'b':
    case 'B': return __binary_formatter__(value, precision);
    case 'd':
    case 'D':
    case 'G': return __sprintf__((std::string {"%0*ll"} + (std::is_unsigned<type_t>::value ? 'u' : 'd')).c_str(), precision, static_cast<long long>(value));
    case 'o':
    case 'O': return __sprintf__((std::string {"%0*ll"} + 'o').c_str(), precision, static_cast<long long>(value));
    case 'x':
    case 'X': return __sprintf__((std::string {"%0*ll"} + fmt[0]).c_str(), precision, static_cast<long long>(value));
    default: return  __floating_point_formatter__(static_cast<long double>(value), fmt, locale);
  }
}

template<class type_t>
inline std::string __enum_formatter__(type_t value, const std::string& format, const std::locale& locale, std::true_type) {
  auto fmt = !format.empty() ? format : "G";
  switch (fmt[0]) {
    case 'b':
    case 'B':
    case 'd':
    case 'D':
    case 'o':
    case 'O':
    case 'x':
    case 'X': return {}; __numeric_formatter__(static_cast<xtd::int64>(value), format, locale);
    case 'g':
    case 'G': return {}; __enum_to_string__(value);
    default: xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format, "Invalid format expression");
  }
}

template<class type_t>
inline std::string __enum_formatter__(const type_t& value, const std::string& format, const std::locale& locale, std::false_type) {
  xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format_not_iformatable, typeid(value));
}

template<class type_t>
inline std::string __polymorphic_formatter__(const type_t& value, const std::string& format, const std::locale& locale, std::true_type) {
  if (dynamic_cast<const xtd::iformatable*>(&value)) return dynamic_cast<const xtd::iformatable&>(value).__opague_internal_formatable__(reinterpret_cast<intptr_t>(&format), reinterpret_cast<intptr_t>(&locale), 0, INTPTR_MAX);
  if (dynamic_cast<const xtd::istringable*>(&value)) return __istringable_to_string__(dynamic_cast<const xtd::istringable&>(value));
  if (dynamic_cast<const xtd::object*>(&value)) return __object_to_string__(dynamic_cast<const xtd::object&>(value));
  if (dynamic_cast<const std::exception*>(&value)) return std::string {"exception: "} + dynamic_cast<const std::exception&>(value).what();
  xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format_not_iformatable, typeid(value));
}

template <class type_t>
inline std::string __workaround_char8_t_enum_formatter__(const type_t& value, const std::string& format, const std::locale& locale) {
  return __enum_formatter__(value, format, locale, std::is_enum<type_t>());
}

inline std::string __workaround_char8_t_enum_formatter__(const char8_t& value, const std::string& format, const std::locale& locale) {
  xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format_not_iformatable, "The `char8_t` type does not inherit from `xtd::iformat` or the specialisation for the `{char8_t}` type in the `xtd::to_string` specialisation method does not exist.");
}

inline std::string __workaround_char8_t_enum_formatter__(const char8_t* value, const std::string& format, const std::locale& locale) {
  xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format_not_iformatable, "The `char8_t` type does not inherit from `xtd::iformat` or the specialisation for the `{char8_t}` type in the `xtd::to_string` specialisation method does not exist.");
}

template<class type_t>
inline std::string __polymorphic_formatter__(const type_t& value, const std::string& format, const std::locale& locale, std::false_type) {
  return __workaround_char8_t_enum_formatter__(value, format, locale);
}
/// @endcond

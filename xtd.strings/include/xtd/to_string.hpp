/// @file
/// @brief Contains xtd::strings class.
#pragma once

#include "__format.hpp"
#include "istring.hpp"
#include "string_comparison.hpp"
#include "string_split_options.hpp"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <locale>
#include <sstream>
#include "strings.hpp"

/// @cond
template<typename Char>
inline std::basic_string<Char> __insert_group_separator(const std::basic_string<Char>& str, Char separator, Char group_separator) {
  std::basic_string<Char> output;
  int distance_from_separator = static_cast<int>(xtd::strings::index_of(str, separator));
  if (distance_from_separator == -1) distance_from_separator = static_cast<int>(str.size());
  for (Char c : str) {
    output += c;
    if (c == '-')
      distance_from_separator -= 1;
    else {
      distance_from_separator -= 1;
      if (distance_from_separator > 0 && (distance_from_separator % 3 == 0))
        output += group_separator;
    }
  }
  return output;
}

template<typename Char, typename Value>
inline std::basic_string<Char> __binary_converter(Value value, int precision) {
  if (precision < 0) return xtd::strings::pad_right(xtd::strings::trim_start(std::bitset<sizeof(value)*8>(value).to_string(Char('0'), Char('1')), Char('0')), std::abs(precision), Char(' '));
  return xtd::strings::pad_left(xtd::strings::trim_start(std::bitset<sizeof(value)*8>(value).to_string(Char('0'), Char('1')), Char('0')), precision == 0 ? 1 : precision, Char('0'));
}

template<typename Char>
inline std::basic_string<Char> __money_converter(long double value, int precision, const std::locale& loc) {
  std::basic_stringstream<Char> ss;
  ss.imbue(loc.name() == "" || loc.name() == "C" ? std::locale("en_US.UTF-8") : loc);
  ss << std::showbase << std::setprecision(precision) << std::put_money(value*100);
  return ss.str();
}

template<typename Char, typename Value>
inline std::basic_string<Char> __character_formater(const std::basic_string<Char>& fmt, Value value, const std::locale& loc) {
  return __format_stringer<Char>(value);
}

template<typename Char, typename Value>
inline std::basic_string<Char> __fixed_point_formater(const std::basic_string<Char>& fmt, Value value, const std::locale& loc) {
  if (fmt.empty()) return __format_stringer<Char>(value);

  std::vector<Char> possible_formats {'c', 'C', 'e', 'E', 'f', 'F', 'g', 'G', 'n', 'N', 'p', 'P'};
  if (fmt.size() > 3 || std::find(possible_formats.begin(), possible_formats.end(), fmt[0]) == possible_formats.end() || (fmt.size() >= 2 && !std::isdigit(fmt[1])) || (fmt.size() == 3 && !std::isdigit(fmt[2])))
    throw std::invalid_argument("Custom format not yet implemented");

  int precision = 0;
  try {
    if (fmt.size() > 1) precision = std::stoi(fmt.substr(1));
  } catch(...) {
    throw std::invalid_argument("Invalid format expression");
  }
  if ((fmt[0] == 'f' || fmt[0] == 'F' || fmt[0] == 'n' || fmt[0] == 'N' || fmt[0] == 'p' || fmt[0] == 'P' || fmt[0] == 'r' || fmt[0] == 'R') && fmt.size() == 1) precision = 2;
  if ((fmt[0] == 'e' || fmt[0] == 'E') && fmt.size() == 1) precision = 6;
  if ((fmt[0] == 'g' || fmt[0] == 'G') && fmt.size() == 1) precision = 10;
  
  std::basic_string<Char> fmt_str({'%', '.', '*', 'L'});
  switch (fmt[0]) {
    case 'c':
    case 'C': return __money_converter<Char>(static_cast<long double>(value), precision, loc);
    case 'e':
    case 'E':
    case 'f':
    case 'F':
    case 'g':
    case 'G': return xtd::strings::formatf(fmt_str + fmt[0], precision, static_cast<long double>(value));
    case 'n': return __insert_group_separator<Char>(xtd::strings::formatf(fmt_str + Char('f'), precision, static_cast<long double>(value)), Char('.'), Char(','));
    case 'N': return __insert_group_separator<Char>(xtd::strings::formatf(fmt_str + Char('F'), precision, static_cast<long double>(value)), Char('.'), Char(','));
    case 'p': return xtd::strings::formatf(fmt_str + Char('f'), precision, static_cast<long double>(value * 100)) + std::basic_string<Char>({Char(' '), Char('%')});
    case 'P': return xtd::strings::formatf(fmt_str + Char('F'), precision, static_cast<long double>(value * 100)) + std::basic_string<Char>({Char(' '), Char('%')});
    default: throw std::invalid_argument("Invalid format expression");
  }
}

template<typename Char, typename Value>
inline std::basic_string<Char> __numeric_formater(const std::basic_string<Char>& fmt, Value value, const std::locale& loc) {
  if (fmt.empty()) return __format_stringer<Char>(value);
  
  std::vector<Char> possible_formats {'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F', 'g', 'G', 'n', 'N', 'o', 'O', 'p', 'P', 'x', 'X'};
  if (fmt.size() > 3 || std::find(possible_formats.begin(), possible_formats.end(), fmt[0]) == possible_formats.end() || (fmt.size() >= 2 && !std::isdigit(fmt[1])) || (fmt.size() == 3 && !std::isdigit(fmt[2])))
    throw std::invalid_argument("Custom format not yet implemented");

  int precision = 0;
  if (fmt[0] == 'b' || fmt[0] == 'B' || fmt[0] == 'd' || fmt[0] == 'D' || fmt[0] == 'o' || fmt[0] == 'O' || fmt[0] == 'x' || fmt[0] == 'X') {
    try {
      for (auto c : fmt.substr(1))
        if (!std::isdigit(c) && c != ' ' && c != '+' && c != '-') throw std::invalid_argument("Invalid format expression");
      if (fmt.size() > 1) precision = std::stoi(fmt.substr(1));
    } catch(...) {
      throw std::invalid_argument("Invalid format expression");
    }
    if ((fmt[0] == 'd' || fmt[0] == 'D') && precision > 0 && value < 0) precision += 1;
    if ((fmt[0] == 'd' || fmt[0] == 'D') && precision < 0 && value < 0) precision -= 1;
  }
  
  std::basic_string<Char> fmt_str({'%', '0', '*', 'l', 'l'});
  switch (fmt[0]) {
    case 'b':
    case 'B': return __binary_converter<Char>(value, precision);
    case 'd':
    case 'D': return xtd::strings::formatf(fmt_str + Char(std::is_unsigned<Value>::value ? 'u' : 'd'), precision, static_cast<long long int>(value));
    case 'o':
    case 'O': return xtd::strings::formatf(fmt_str + Char('o'), precision, static_cast<long long int>(value));
    case 'x':
    case 'X': return xtd::strings::formatf(fmt_str + fmt[0], precision, static_cast<long long int>(value));
    default: return __fixed_point_formater(fmt, static_cast<long double>(value), loc);
  }
}

template<typename Char>
inline std::basic_string<Char> __boolean_formater(const std::basic_string<Char>& fmt, bool value, const std::locale& loc) {
  if (fmt.empty()) return value ? std::basic_string<Char> {'t', 'r', 'u', 'e'} : std::basic_string<Char> {'f', 'a', 'l', 's', 'e'};
  
  switch (fmt[0]) {
    case 'b':
    case 'B':
    case 'd':
    case 'D':
    case 'o':
    case 'O':
    case 'x':
    case 'X': return __numeric_formater(fmt, value ? 1 : 0, loc);
    case 'g':
    case 'G': return value ? std::basic_string<Char> {'t', 'r', 'u', 'e'} : std::basic_string<Char> {'f', 'a', 'l', 's', 'e'};
    default: throw std::invalid_argument("Invalid format expression");
  }
}

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
    case 'G': return __format_stringer<Char, Value>(value);
    default: throw std::invalid_argument("Invalid format expression");
  }
}

template<typename Char, typename Value>
inline std::basic_string<Char> __string_formater(const std::basic_string<Char>& fmt, Value value, const std::locale& loc) {
  return __format_stringer<Char>(value);
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

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  template<typename Value>
  inline std::string to_string(const Value& value, const std::string& fmt, const std::locale& loc) {return __to_string_enum(value, fmt, loc, std::is_enum<Value>());}
  
  template<>
  inline std::string to_string(const bool& value, const std::string& fmt, const std::locale& loc) {return __boolean_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const int8_t& value, const std::string& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const char& value, const std::string& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const unsigned char& value, const std::string& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const short& value, const std::string& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const unsigned short& value, const std::string& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const int& value, const std::string& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const unsigned int& value, const std::string& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const long& value, const std::string& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const unsigned long& value, const std::string& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const long long& value, const std::string& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const unsigned long long& value, const std::string& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const float& value, const std::string& fmt, const std::locale& loc) {return __fixed_point_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const double& value, const std::string& fmt, const std::locale& loc) {return __fixed_point_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const long double& value, const std::string& fmt, const std::locale& loc) {return __fixed_point_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const std::string& value, const std::string& fmt, const std::locale& loc) {return __string_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const xtd::istring& value, const std::string& fmt, const std::locale& loc) {return __string_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const char16_t& value, const std::string& fmt, const std::locale& loc) {return __character_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const char32_t& value, const std::string& fmt, const std::locale& loc) {return __character_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const wchar_t& value, const std::string& fmt, const std::locale& loc) {return __character_formater(fmt, value, loc);}
  
  /// @cond
  inline std::string to_string(const char*  value, const std::string& fmt, const std::locale& loc) {return __string_formater(fmt, value, loc);}
  /// @endcond
  
  template<typename Value>
  inline std::string to_string(const Value& value, const std::string& fmt) {return to_string(value, fmt, std::locale());}

  /// @cond
  inline std::string to_string(const char*  value, const std::string& fmt) {return to_string(value, fmt, std::locale());}
  /// @endcond
  
  template<typename Value>
  inline std::wstring to_string(const Value& value, const std::wstring& fmt, const std::locale& loc) {return __to_string_enum(value, fmt, loc, std::is_enum<Value>());}

  template<>
  inline std::wstring to_string(const bool& value, const std::wstring& fmt, const std::locale& loc) {return __boolean_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const int8_t& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const char& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const unsigned char& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const short& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const unsigned short& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const int& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const unsigned int& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const long& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const unsigned long& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const long long& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const unsigned long long& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const float& value, const std::wstring& fmt, const std::locale& loc) {return __fixed_point_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const double& value, const std::wstring& fmt, const std::locale& loc) {return __fixed_point_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const long double& value, const std::wstring& fmt, const std::locale& loc) {return __fixed_point_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const std::wstring& value, const std::wstring& fmt, const std::locale& loc) {return __string_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const xtd::iwstring& value, const std::wstring& fmt, const std::locale& loc) {return __string_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const char16_t& value, const std::wstring& fmt, const std::locale& loc) {return __character_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const char32_t& value, const std::wstring& fmt, const std::locale& loc) {return __character_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const wchar_t& value, const std::wstring& fmt, const std::locale& loc) {return __character_formater(fmt, value, loc);}

  /// @cond
  inline std::wstring to_string(const wchar_t*  value, const std::wstring& fmt, const std::locale& loc) {return __string_formater(fmt, value, loc);}
  /// @endcond

  template<typename Value>
  inline std::wstring to_string(const Value& value, const std::wstring& fmt) {return to_string(value, fmt, std::locale());}

  /// @cond
  inline std::wstring to_string(const wchar_t*  value, const std::wstring& fmt) {return to_string(value, fmt, std::locale());}
  /// @endcond
}


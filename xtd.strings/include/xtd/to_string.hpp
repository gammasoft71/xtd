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
template<typename Char, typename Value>
inline std::basic_string<Char> __binary_formater(Value value, int precision) {
  if (precision < 0) return xtd::strings::pad_right(xtd::strings::trim_start(std::bitset<sizeof(value)*8>(value).to_string(Char('0'), Char('1')), Char('0')), std::abs(precision), Char(' '));
  return xtd::strings::pad_left(xtd::strings::trim_start(std::bitset<sizeof(value)*8>(value).to_string(Char('0'), Char('1')), Char('0')), precision == 0 ? 1 : precision, Char('0'));
}

template<typename Char>
inline std::basic_string<Char> __currency_formater(long double value, const std::locale& loc) {
  std::basic_stringstream<Char> ss;
  ss.imbue(loc);
  ss << std::showbase << std::fixed << std::put_money(value*std::pow(10, std::use_facet<std::moneypunct<Char>>(loc).frac_digits()));
  return ss.str();
}

template<typename Char, typename Value>
inline std::basic_string<Char> __character_formater(const std::basic_string<Char>& fmt, Value value, const std::locale& loc) {
  return __format_stringer<Char>(value);
}

template<typename Char>
inline std::basic_string<Char> __natural_formater(long double value, int precision, const std::locale& loc) {
  std::basic_stringstream<Char> ss;
  ss.imbue(loc);
  ss << std::fixed << std::setprecision(precision) << value;
  return ss.str();
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
  if ((fmt[0] == 'e' || fmt[0] == 'E' || fmt[0] == 'g' || fmt[0] == 'G') && fmt.size() == 1) precision = 6;
  
  std::basic_string<Char> fmt_str({'%', '.', '*', 'L'});
  switch (fmt[0]) {
    case 'c':
    case 'C': return __currency_formater<Char>(static_cast<long double>(value), loc);
    case 'e':
    case 'E':
    case 'f':
    case 'F':
    case 'g':
    case 'G': return xtd::strings::formatf(fmt_str + fmt[0], precision, static_cast<long double>(value));
    case 'n':
    case 'N': return __natural_formater<Char>(static_cast<long double>(value), precision, loc);
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
    case 'B': return __binary_formater<Char>(value, precision);
    case 'd':
    case 'D': return xtd::strings::formatf(fmt_str + Char(std::is_unsigned<Value>::value ? 'u' : 'd'), precision, static_cast<long long>(value));
    case 'o':
    case 'O': return xtd::strings::formatf(fmt_str + Char('o'), precision, static_cast<long long>(value));
    case 'x':
    case 'X': return xtd::strings::formatf(fmt_str + fmt[0], precision, static_cast<long long>(value));
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
    case 'G': return __format_stringer<Char>(value);
    default: throw std::invalid_argument("Invalid format expression");
  }
}

template<typename Char>
inline std::basic_string<Char> __get_weekday_name(const std::tm& value, const std::locale& loc) {
  std::basic_stringstream<Char> result;
  result.imbue(loc);
  result << std::put_time(&value, "%A");
  return result.str();
}

template<typename Char>
inline std::basic_string<Char> __get_brief_weekday_name(const std::tm& value, const std::locale& loc) {
  std::basic_stringstream<Char> result;
  result.imbue(loc);
  result << std::put_time(&value, "%a");
  return result.str();
}

template<typename Char>
inline std::basic_string<Char> __get_month_name(const std::tm& value, const std::locale& loc) {
  std::basic_stringstream<Char> result;
  result.imbue(loc);
  result << std::put_time(&value, "%B");
  return result.str();
}

template<typename Char>
inline std::basic_string<Char> __get_brief_month_name(const std::tm& value, const std::locale& loc) {
  std::basic_stringstream<Char> result;
  result.imbue(loc);
  result << std::put_time(&value, "%b");
  return result.str();
}

template<typename Char>
inline std::basic_string<Char> __tm_formater(const Char* fmt, const std::tm& value, const std::locale& loc) {
  std::basic_stringstream<Char> result;
  result.imbue(loc);
  result << std::put_time(&value, fmt);
  return result.str();
}

inline std::string __date_time_formater(std::string fmt, const std::tm& time, const std::locale& loc) {
  if (fmt.empty()) fmt =  "G";
  if (fmt.size() > 1) throw std::invalid_argument("Invalid format");
  
  std::string result;
  switch (fmt[0]) {
    case 'd': return __tm_formater<char>("%x", time, loc);
    case 'D': return xtd::strings::format("{}/{:D2}/{}", time.tm_mon+1, time.tm_mday, time.tm_year + 1900);
    case 'f': return __tm_formater<char>("%Ec", time, loc);
    case 'F': return __tm_formater<char>("%c", time, loc);
    case 'g': return __tm_formater<char>("%Ec", time, loc);
    case 'G': return __tm_formater<char>("%c", time, loc);
    case 'h': return xtd::strings::format("{}", __get_brief_weekday_name<char>(time, loc));
    case 'H': return xtd::strings::format("{}", __get_weekday_name<char>(time, loc));
    case 'i': return xtd::strings::format("{:D2}", time.tm_mday);
    case 'I': return xtd::strings::format("{}", time.tm_mday);
    case 'j': return xtd::strings::format("{}", __get_brief_month_name<char>(time, loc));
    case 'J': return xtd::strings::format("{}", __get_month_name<char>(time, loc));
    case 'k': return xtd::strings::format("{:D2}", time.tm_mon + 1);
    case 'K': return xtd::strings::format("{}", time.tm_mon + 1);
    case 'l': return xtd::strings::format("{:D2}", time.tm_year % 100);
    case 'L': return xtd::strings::format("{}", time.tm_year + 1900);
    case 'm':
    case 'M': return xtd::strings::format("{} {}", __get_month_name<char>(time, loc), time.tm_mday);
    case 'n': return xtd::strings::format("{}, {} {} {}", __get_weekday_name<char>(time, loc), time.tm_mday, __get_month_name<char>(time, loc), time.tm_year + 1900);
    case 'N': return xtd::strings::format("{}, {} {} {} {}:{:D2}:{:D2}", __get_weekday_name<char>(time, loc), time.tm_mday, __get_month_name<char>(time, loc), time.tm_year + 1900, time.tm_hour, time.tm_min, time.tm_sec);
    case 'o':
    case 'O': return xtd::strings::format("{} {} {}", time.tm_mday, __get_month_name<char>(time, loc), time.tm_year + 1900);
    case 's': return xtd::strings::format("{}-{:D2}-{:D2}T{:D2}:{:D2}:{:D2}", time.tm_year + 1900, time.tm_mon+1, time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec);
    case 't': return xtd::strings::format("{:D2}:{:D2}:{:D2}", time.tm_hour, time.tm_min, time.tm_sec);
    case 'T': return xtd::strings::format("{}:{:D2}:{:D2}", time.tm_hour, time.tm_min, time.tm_sec);
    case 'u': return xtd::strings::format("{}-{:D2}-{:D2} {:D2}:{:D2}:{:D2}Z", time.tm_year + 1900, time.tm_mon+1, time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec);
    case 'U': return xtd::strings::format("{}, {} {} {} {}:{:D2}:{:D2}", __get_weekday_name<char>(time, loc), time.tm_mday, __get_month_name<char>(time, loc), time.tm_year + 1900, time.tm_hour, time.tm_min, time.tm_sec);
    case 'v': return xtd::strings::format("{:D2}:{:D2}", time.tm_hour, time.tm_min);
    case 'V': return xtd::strings::format("{}:{:D2}", time.tm_hour, time.tm_min);
    case 'y': return xtd::strings::format("{} {}", __get_month_name<char>(time, loc), time.tm_year % 100);
    case 'Y': return xtd::strings::format("{} {}", __get_month_name<char>(time, loc), time.tm_year + 1900);
    case 'z': return xtd::strings::format("{}", time.tm_zone);
    case 'Z': return xtd::strings::format("{}", time.tm_zone);
    default: throw std::invalid_argument("Invalid format");
  }
  throw std::invalid_argument("Invalid format");
}

inline std::string __date_time_formater(std::string fmt, time_t time, const std::locale& loc) {
  return __date_time_formater(fmt, *std::localtime(&time), loc);
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
  inline std::string to_string(const std::chrono::system_clock::time_point& value, const std::string& fmt, const std::locale& loc) {return __date_time_formater(fmt, std::chrono::system_clock::to_time_t(value), loc);}

  template<>
  inline std::string to_string(const std::tm& value, const std::string& fmt, const std::locale& loc) {return __date_time_formater(fmt, value, loc);}

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

  //template<>
  //inline std::wstring to_string(const std::chrono::system_clock::time_point& value, const std::wstring& fmt, const std::locale& loc) {return __date_time_formater(fmt, std::chrono::system_clock::to_time_t(value), loc);}
 
  //template<>
  //inline std::wstring to_string(const std::tm& value, const std::wstring& fmt, const std::locale& loc) {return __date_time_formater(fmt, value, loc);}

  template<>
  inline std::wstring to_string(const std::chrono::system_clock::time_point& value, const std::wstring& fmt, const std::locale& loc) {throw std::invalid_argument("to_string speciailisation not found");}
  
  template<>
  inline std::wstring to_string(const std::tm& value, const std::wstring& fmt, const std::locale& loc) {throw std::invalid_argument("to_string speciailisation not found");}
  
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


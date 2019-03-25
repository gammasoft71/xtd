/// @file
/// @brief Contains xtd::strings class.
#pragma once

#include "__format.hpp"
#include "istring.hpp"
#include "string_comparison.hpp"
#include "string_split_options.hpp"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <locale>
#include <sstream>
#include "strings.hpp"

template<typename Char>
inline std::basic_string<Char> __insert_group_separator(const std::basic_string<Char>& s, Char separator, Char group_separator) {
  std::basic_string<Char> output;
  int distance_from_separator = xtd::strings::index_of(s, separator);
  if (distance_from_separator == -1) distance_from_separator = s.size();
  for (Char c : s) {
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

template<typename Char>
inline std::basic_string<Char> __put_money(long double value, size_t precision) {
  std::basic_stringstream<Char> ss;
  ss.imbue(std::locale(std::locale().name() == "" || std::locale().name() == "C" ? "en_US.UTF-8" : std::locale().name().c_str()));
  ss << std::showbase << std::setprecision(precision) << std::put_money(value*100);
  return ss.str();
}

template<typename Char>
inline std::basic_string<Char> __boolean_formater(const std::basic_string<Char>& fmt, bool value) {
  std::basic_string<Char> false_string {static_cast<Char>('f'), static_cast<Char>('a'), static_cast<Char>('l'), static_cast<Char>('s'), static_cast<Char>('e')};
    std::basic_string<Char> true_string {static_cast<Char>('t'), static_cast<Char>('r'), static_cast<Char>('u'), static_cast<Char>('e')};
  if (fmt.empty()) return value ? true_string : false_string;
  
  int precision = 0;
  if (fmt[0] == static_cast<Char>(',') && fmt.size() > 1) precision = std::stoi(fmt.substr(1));
  if (precision > 0) return xtd::strings::pad_left(value ? true_string : false_string, precision);
  if (precision < 0) return xtd::strings::pad_right(value ? true_string : false_string, std::abs(precision));
  
  return value ? true_string : false_string;
}

template<typename Char, typename Value>
inline std::basic_string<Char> __character_formater(const std::basic_string<Char>& fmt, Value value) {
  if (fmt.empty()) return xtd::strings::formatf(std::basic_string<Char>{static_cast<Char>('%'), static_cast<Char>('c')}, static_cast<Char>(value));
  
  int precision = 0;
  if (fmt[0] == static_cast<Char>(',') && fmt.size() > 1) precision = std::stoi(fmt.substr(1));
  if (precision > 0) return xtd::strings::formatf(std::basic_string<Char>{static_cast<Char>('%'), static_cast<Char>('s')}, xtd::strings::pad_left(std::basic_string<Char>{static_cast<Char>(value)}, precision));
  if (precision < 0) return xtd::strings::formatf(std::basic_string<Char>{static_cast<Char>('%'), static_cast<Char>('s')}, xtd::strings::pad_right(std::basic_string<Char>{static_cast<Char>(value)}, std::abs(precision)));
  
  return xtd::strings::formatf(std::basic_string<Char>{static_cast<Char>('%'), static_cast<Char>('c')}, static_cast<Char>(value));
}

template<typename Char, typename Value>
inline std::basic_string<Char> __fixed_point_formater(const std::basic_string<Char>& fmt, Value value) {
  if (fmt.empty()) return xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('L'), static_cast<Char>('g')}), static_cast<long double>(value));
  
  size_t precision = 0;
  if (fmt.size() > 1) precision = std::stoi(fmt.substr(1));
  if ((fmt[0] == 'd' || fmt[0] == 'D') && precision > 0 && value < 0) precision += 1;
  if ((fmt[0] == 'e' || fmt[0] == 'E') && fmt.size() == 1) precision = 6;
  if ((fmt[0] == 'f' || fmt[0] == 'F') && fmt.size() == 1) precision = 2;
  if ((fmt[0] == 'g' || fmt[0] == 'G') && fmt.size() == 1) precision = 10;
  if ((fmt[0] == 'n' || fmt[0] == 'N') && fmt.size() == 1) precision = 2;
  if ((fmt[0] == 'p' || fmt[0] == 'P') && fmt.size() == 1) precision = 2;
  if ((fmt[0] == 'r' || fmt[0] == 'R') && fmt.size() == 1) precision = 2;

  switch (fmt[0]) {
    case static_cast<Char>('c'):
    case static_cast<Char>('C'): return __put_money<Char>(static_cast<long double>(value), precision);
    case static_cast<Char>('e'): return xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('.'), static_cast<Char>('*')}) + std::basic_string<Char>({static_cast<Char>('L'), static_cast<Char>('e')}), precision, static_cast<long double>(value));
    case static_cast<Char>('E'): return xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('.'), static_cast<Char>('*')}) + std::basic_string<Char>({static_cast<Char>('L'), static_cast<Char>('E')}), precision, static_cast<long double>(value));
    case static_cast<Char>('f'): return xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('.'), static_cast<Char>('*')}) + std::basic_string<Char>({static_cast<Char>('L'), static_cast<Char>('f')}), precision, static_cast<long double>(value));
    case static_cast<Char>('F'): return xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('.'), static_cast<Char>('*')}) + std::basic_string<Char>({static_cast<Char>('L'), static_cast<Char>('F')}), precision, static_cast<long double>(value));
    case static_cast<Char>('g'): return xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('.'), static_cast<Char>('*')}) + std::basic_string<Char>({static_cast<Char>('L'), static_cast<Char>('g')}), precision, static_cast<long double>(value));
    case static_cast<Char>('G'): return xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('.'), static_cast<Char>('*')}) + std::basic_string<Char>({static_cast<Char>('L'), static_cast<Char>('G')}), precision, static_cast<long double>(value));
    case static_cast<Char>('n'): return __insert_group_separator<Char>(xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('.'), static_cast<Char>('*')}) + std::basic_string<Char>({static_cast<Char>('L'), static_cast<Char>('f')}), precision, static_cast<long double>(value)), static_cast<Char>('.'), static_cast<Char>(','));
    case static_cast<Char>('N'): return __insert_group_separator<Char>(xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('.'), static_cast<Char>('*')}) + std::basic_string<Char>({static_cast<Char>('L'), static_cast<Char>('F')}), precision, static_cast<long double>(value)), static_cast<Char>('.'), static_cast<Char>(','));
    case static_cast<Char>('p'): return xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('.'), static_cast<Char>('*')}) + std::basic_string<Char>({static_cast<Char>('L'), static_cast<Char>('f')}), precision, static_cast<long double>(value * 100)) + std::basic_string<Char>({static_cast<Char>(' '), static_cast<Char>('%')});
    case static_cast<Char>('P'): return xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('.'), static_cast<Char>('*')}) + std::basic_string<Char>({static_cast<Char>('L'), static_cast<Char>('F')}), precision, static_cast<long double>(value * 100)) + std::basic_string<Char>({static_cast<Char>(' '), static_cast<Char>('%')});
    case static_cast<Char>('r'):
    case static_cast<Char>('R'): throw std::invalid_argument("Not yet implemented");
    default: throw std::invalid_argument("Invalid format expression");
  }
}

template<typename Char, typename Value>
inline std::basic_string<Char> __numeric_formater(const std::basic_string<Char>& fmt, Value value, bool unsign = false) {
  if (fmt.empty()) return xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('l'), static_cast<Char>('l'), static_cast<Char>(unsign ? 'u' : 'd')}), static_cast<long long int>(value));
  
  size_t precision = 0;
  if (fmt.size() > 1) precision = std::stoi(fmt.substr(1));
  if ((fmt[0] == 'd' || fmt[0] == 'D') && precision > 0 && value < 0) precision += 1;
  if ((fmt[0] == 'e' || fmt[0] == 'E') && fmt.size() == 1) precision = 6;
  if ((fmt[0] == 'f' || fmt[0] == 'F') && fmt.size() == 1) precision = 2;
  if ((fmt[0] == 'g' || fmt[0] == 'G') && fmt.size() == 1) precision = 10;
  if ((fmt[0] == 'n' || fmt[0] == 'N') && fmt.size() == 1) precision = 2;
  if ((fmt[0] == 'p' || fmt[0] == 'P') && fmt.size() == 1) precision = 2;
  if ((fmt[0] == 'r' || fmt[0] == 'R') && fmt.size() == 1) precision = 2;

  switch (fmt[0]) {
    case static_cast<Char>('c'):
    case static_cast<Char>('C'): return __put_money<Char>(static_cast<long double>(value), precision);
    case static_cast<Char>('d'):
    case static_cast<Char>('D'): return xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('0'), static_cast<Char>('*')}) + std::basic_string<Char>({static_cast<Char>('l'), static_cast<Char>('l'), static_cast<Char>(unsign ? 'u' : 'd')}), precision, static_cast<long long int>(value));
    case static_cast<Char>('e'): return xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('.'), static_cast<Char>('*')}) + std::basic_string<Char>({static_cast<Char>('e')}), precision, static_cast<double>(value));
    case static_cast<Char>('E'): return xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('.'), static_cast<Char>('*')}) + std::basic_string<Char>({static_cast<Char>('E')}), precision, static_cast<double>(value));
    case static_cast<Char>('f'): return xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('.'), static_cast<Char>('*')}) + std::basic_string<Char>({static_cast<Char>('f')}), precision, static_cast<double>(value));
    case static_cast<Char>('F'): return xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('.'), static_cast<Char>('*')}) + std::basic_string<Char>({static_cast<Char>('F')}), precision, static_cast<double>(value));
    case static_cast<Char>('g'): return xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('.'), static_cast<Char>('*')}) + std::basic_string<Char>({static_cast<Char>('g')}), precision, static_cast<double>(value));
    case static_cast<Char>('G'): return xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('.'), static_cast<Char>('*')}) + std::basic_string<Char>({static_cast<Char>('G')}), precision, static_cast<double>(value));
    case static_cast<Char>('n'): return __insert_group_separator<Char>(xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('.'), static_cast<Char>('*')}) + std::basic_string<Char>({static_cast<Char>('f')}), precision, static_cast<double>(value)), static_cast<Char>('.'), static_cast<Char>(','));
    case static_cast<Char>('N'): return __insert_group_separator<Char>(xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('.'), static_cast<Char>('*')}) + std::basic_string<Char>({static_cast<Char>('F')}), precision, static_cast<double>(value)), static_cast<Char>('.'), static_cast<Char>(','));
    case static_cast<Char>('o'):
    case static_cast<Char>('O'): return xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('0'), static_cast<Char>('*')}) + std::basic_string<Char>({static_cast<Char>('l'), static_cast<Char>('l'), static_cast<Char>('o')}), precision, static_cast<long long int>(value));
    case static_cast<Char>('p'): return xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('.'), static_cast<Char>('*')}) + std::basic_string<Char>({static_cast<Char>('f')}), precision, static_cast<double>(value * 100)) + std::basic_string<Char>({static_cast<Char>(' '), static_cast<Char>('%')});
    case static_cast<Char>('P'): return xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('.'), static_cast<Char>('*')}) + std::basic_string<Char>({static_cast<Char>('F')}), precision, static_cast<double>(value * 100)) + std::basic_string<Char>({static_cast<Char>(' '), static_cast<Char>('%')});
    case static_cast<Char>('x'): return xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('0'), static_cast<Char>('*')}) + std::basic_string<Char>({static_cast<Char>('l'), static_cast<Char>('l'), static_cast<Char>('x')}), precision, static_cast<long long int>(value));
    case static_cast<Char>('X'): return xtd::strings::formatf(std::basic_string<Char>({static_cast<Char>('%'), static_cast<Char>('0'), static_cast<Char>('*')}) + std::basic_string<Char>({static_cast<Char>('l'), static_cast<Char>('l'), static_cast<Char>('X')}), precision, static_cast<long long int>(value));
    default: throw std::invalid_argument("Invalid format expression");
  }
}

template<typename Char, typename Value>
inline std::basic_string<Char> __unsigned_numeric_formater(const std::basic_string<Char>& fmt, Value value) {
  return __numeric_formater(fmt, value, true);
}

template<typename Char, typename Value>
inline std::basic_string<Char> __string_formater(const std::basic_string<Char>& fmt, Value value) {
  if (fmt.empty()) return value;
  
  int precision = 0;
  if (fmt[0] == static_cast<Char>(',') && fmt.size() > 1) precision = std::stoi(fmt.substr(1));
  if (precision > 0) return xtd::strings::pad_left(value, precision);
  if (precision < 0) return xtd::strings::pad_right(value, std::abs(precision));
  
  return value;
}

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  inline std::string to_string(bool value, const std::string& fmt) {return __boolean_formater(fmt, value);}
  inline std::string to_string(bool value) {return to_string(value, "");}
  
  inline std::string to_string(short value, const std::string& fmt) {return __numeric_formater(fmt, value);}
  inline std::string to_string(short value) {return to_string(value, "");}
  
  inline std::string to_string(unsigned short value, const std::string& fmt) {return __unsigned_numeric_formater(fmt, value);}
  inline std::string to_string(unsigned short value) {return to_string(value, "");}
  
  inline std::string to_string(int value, const std::string& fmt) {return __numeric_formater(fmt, value);}
  inline std::string to_string(int value) {return to_string(value, "");}
  
  inline std::string to_string(unsigned int value, const std::string& fmt) {return __unsigned_numeric_formater(fmt, value);}
  inline std::string to_string(unsigned int value) {return to_string(value, "");}
  
  inline std::string to_string(long value, const std::string& fmt) {return __numeric_formater(fmt, value);}
  inline std::string to_string(long value) {return to_string(value, "");}
  
  inline std::string to_string(unsigned long value, const std::string& fmt) {return __unsigned_numeric_formater(fmt, value);}
  inline std::string to_string(unsigned long value) {return to_string(value, "");}
  
  inline std::string to_string(long long value, const std::string& fmt) {return __numeric_formater(fmt, value);}
  inline std::string to_string(long long value) {return to_string(value, "");}
  
  inline std::string to_string(unsigned long long value, const std::string& fmt) {return __unsigned_numeric_formater(fmt, value);}
  inline std::string to_string(unsigned long long value) {return to_string(value, "");}
  
  inline std::string to_string(float value, const std::string& fmt) {return __fixed_point_formater(fmt, value);}
  inline std::string to_string(float value) {return to_string(value, "");}
  
  inline std::string to_string(double value, const std::string& fmt) {return __fixed_point_formater(fmt, value);}
  inline std::string to_string(double value) {return to_string(value, "");}
  
  inline std::string to_string(long double value, const std::string& fmt) {return __fixed_point_formater(fmt, value);}
  inline std::string to_string(long double value) {return to_string(value, "");}
  
  inline std::string to_string(const std::string& value, const std::string& fmt) {return __string_formater(fmt, value);}
  inline std::string to_string(const std::string& value) {return to_string(value, "");}
  
  inline std::string to_string(const xtd::istring& value, const std::string& fmt) {return __string_formater(fmt, value);}
  inline std::string to_string(const xtd::istring& value) {return to_string(value, "");}
  
  inline std::string to_string(const char* value, const std::string& fmt) {return __string_formater(fmt, value);}
  inline std::string to_string(const char* value) {return to_string(value, "");}
  
  inline std::string to_string(char value, const std::string& fmt) {return __character_formater(fmt, value);}
  inline std::string to_string(char value) {return to_string(value, "");}
  
  inline std::string to_string(char16_t value, const std::string& fmt) {return __character_formater(fmt, value);}
  inline std::string to_string(char16_t value) {return to_string(value, "");}
  
  inline std::string to_string(char32_t value, const std::string& fmt) {return __character_formater(fmt, value);}
  inline std::string to_string(char32_t value) {return to_string(value, "");}
  
  inline std::string to_string(wchar_t value, const std::string& fmt) {return __character_formater(fmt, value);}
  inline std::string to_string(wchar_t value) {return to_string(value, "");}

  template<typename Value>
  inline std::string to_string(Value value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
  }
  template<typename Value>
  inline std::string to_string(const Value& value, const std::string& fmt) {throw std::invalid_argument("to_string speciailisation not found");}

  template<typename Char>
  inline std::basic_string<Char> to_string(bool value, const std::basic_string<Char>& fmt) {return __boolean_formater(fmt, value);}
  template<typename Char>
  inline std::basic_string<Char> to_string(bool value) {return to_string<Char>(value, xtd::strings::empty<Char>());}
  
  template<typename Char>
  inline std::basic_string<Char> to_string(short value, const std::basic_string<Char>& fmt) {return __numeric_formater(fmt, value);}
  template<typename Char>
  inline std::basic_string<Char> to_string(short value) {return to_string<Char>(value, xtd::strings::empty<Char>());}
  
  template<typename Char>
  inline std::basic_string<Char> to_string(unsigned short value, const std::basic_string<Char>& fmt) {return __unsigned_numeric_formater(fmt, value);}
  template<typename Char>
  inline std::basic_string<Char> to_string(unsigned short value) {return to_string<Char>(value, xtd::strings::empty<Char>());}

  template<typename Char>
  inline std::basic_string<Char> to_string(int value, const std::basic_string<Char>& fmt) {return __numeric_formater(fmt, value);}
  template<typename Char>
  inline std::basic_string<Char> to_string(int value) {return to_string<Char>(value, xtd::strings::empty<Char>());}
  
  template<typename Char>
  inline std::basic_string<Char> to_string(unsigned int value, const std::basic_string<Char>& fmt) {return __unsigned_numeric_formater(fmt, value);}
  template<typename Char>
  inline std::basic_string<Char> to_string(unsigned int value) {return to_string<Char>(value, xtd::strings::empty<Char>());}
  
  template<typename Char>
  inline std::basic_string<Char> to_string(long value, const std::basic_string<Char>& fmt) {return __numeric_formater(fmt, value);}
  template<typename Char>
  inline std::basic_string<Char> to_string(long value) {return to_string<Char>(value, xtd::strings::empty<Char>());}
  
  template<typename Char>
  inline std::basic_string<Char> to_string(unsigned long value, const std::basic_string<Char>& fmt) {return __unsigned_numeric_formater(fmt, value);}
  template<typename Char>
  inline std::basic_string<Char> to_string(unsigned long value) {return to_string<Char>(value, xtd::strings::empty<Char>());}
  
  template<typename Char>
  inline std::basic_string<Char> to_string(long long value, const std::basic_string<Char>& fmt) {return __numeric_formater(fmt, value);}
  template<typename Char>
  inline std::basic_string<Char> to_string(long long value) {return to_string<Char>(value, xtd::strings::empty<Char>());}
  
  template<typename Char>
  inline std::basic_string<Char> to_string(unsigned long long value, const std::basic_string<Char>& fmt) {return __unsigned_numeric_formater(fmt, value);}
  template<typename Char>
  inline std::basic_string<Char> to_string(unsigned long long value) {return to_string<Char>(value, xtd::strings::empty<Char>());}
  
  template<typename Char>
  inline std::basic_string<Char> to_string(float value, const std::basic_string<Char>& fmt) {return __fixed_point_formater(fmt, value);}
  template<typename Char>
  inline std::basic_string<Char> to_string(float value) {return to_string<Char>(value, xtd::strings::empty<Char>());}
  
  template<typename Char>
  inline std::basic_string<Char> to_string(double value, const std::basic_string<Char>& fmt) {return __fixed_point_formater(fmt, value);}
  template<typename Char>
  inline std::basic_string<Char> to_string(double value) {return to_string<Char>(value, xtd::strings::empty<Char>());}
  
  template<typename Char>
  inline std::basic_string<Char> to_string(long double value, const std::basic_string<Char>& fmt) {return __fixed_point_formater(fmt, value);}
  template<typename Char>
  inline std::basic_string<Char> to_string(long double value) {return to_string<Char>(value, xtd::strings::empty<Char>());}
  
  template<typename Char>
  inline std::basic_string<Char> to_string(const std::basic_string<Char>& value, const std::basic_string<Char>& fmt) {return __string_formater(fmt, value);}
  template<typename Char>
  inline std::basic_string<Char> to_string(const std::basic_string<Char>& value) {return to_string<Char>(value, xtd::strings::empty<Char>());}
  
  template<typename Char>
  inline std::basic_string<Char> to_string(const xtd::immutable_basic_string<Char>& value, const std::basic_string<Char>& fmt) {return __string_formater(fmt, value);}
  template<typename Char>
  inline std::basic_string<Char> to_string(const xtd::immutable_basic_string<Char>& value) {return to_string<Char>(value, xtd::strings::empty<Char>());}
  
  template<typename Char>
  inline std::basic_string<Char> to_string(const Char* value, const std::basic_string<Char>& fmt) {return __string_formater(fmt, value);}
  template<typename Char>
  inline std::basic_string<Char> to_string(const Char* value) {return to_string<Char>(value, xtd::strings::empty<Char>());}
  
  template<typename Char>
  inline std::basic_string<Char> to_string(char value, const std::string& fmt) {return __character_formater(fmt, value);}
  template<typename Char>
  inline std::basic_string<Char> to_string(char value) {return to_string<Char>(value, xtd::strings::empty<Char>());}
  
  template<typename Char>
  inline std::basic_string<Char> to_string(char16_t value, const std::string& fmt) {return __character_formater(fmt, value);}
  template<typename Char>
  inline std::basic_string<Char> to_string(char16_t value) {return to_string<Char>(value, xtd::strings::empty<Char>());}
  
  template<typename Char>
  inline std::basic_string<Char> to_string(char32_t value, const std::string& fmt) {return __character_formater(fmt, value);}
  template<typename Char>
  inline std::basic_string<Char> to_string(char32_t value) {return to_string<Char>(value, xtd::strings::empty<Char>());}
  
  template<typename Char>
  inline std::basic_string<Char> to_string(wchar_t value, const std::string& fmt) {return __character_formater(fmt, value);}
  template<typename Char>
  inline std::basic_string<Char> to_string(wchar_t value) {return to_string<Char>(value, xtd::strings::empty<Char>());}

  template<typename Char, typename Value>
  inline std::basic_string<Char> to_string(Value value) {
    std::basic_stringstream<Char> ss;
    ss << value;
    return ss.str();
  }

  template<typename Value>
  inline std::u16string to_string(const Value& value, const std::u16string& fmt) {throw std::invalid_argument("to_string speciailisation not found");}

  template<typename Value>
  inline std::u32string to_string(const Value& value, const std::u32string& fmt) {throw std::invalid_argument("to_string speciailisation not found");}

  template<typename Value>
  inline std::wstring to_string(const Value& value, const std::wstring& fmt) {throw std::invalid_argument("to_string speciailisation not found");}
}


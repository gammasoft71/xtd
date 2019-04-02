/// @file
/// @brief Contains xtd::strings class.
#pragma once

#include "number_styles.hpp"
#include "strings.hpp"
#include <string>

/// @cond
template <typename Value, typename Char>
inline long long int __parse_number(const std::basic_string<Char>& s, xtd::number_styles styles) {
  if ((styles & xtd::number_styles::allow_binary_specifier) == xtd::number_styles::allow_binary_specifier && (styles - xtd::number_styles::binary_number) != xtd::number_styles::none) throw std::invalid_argument("Invalid xtd::number_styles flags");
  if ((styles & xtd::number_styles::allow_octal_specifier) == xtd::number_styles::allow_octal_specifier && (styles - xtd::number_styles::octal_number) != xtd::number_styles::none) throw std::invalid_argument("Invalid xtd::number_styles flags");
  if ((styles & xtd::number_styles::allow_hex_specifier) == xtd::number_styles::allow_hex_specifier && (styles - xtd::number_styles::hex_number) != xtd::number_styles::none) throw std::invalid_argument("Invalid xtd::number_styles flags");

  int base = 10;
  if ((styles & xtd::number_styles::binary_number) == xtd::number_styles::binary_number) base = 2;
  if ((styles & xtd::number_styles::octal_number) == xtd::number_styles::octal_number) base = 8;
  if ((styles & xtd::number_styles::hex_number) == xtd::number_styles::hex_number) base = 16;

  std::basic_string<Char> str(s);
  if ((styles & xtd::number_styles::allow_leading_white) == xtd::number_styles::allow_leading_white) str = xtd::strings::trim_start(str);
  if ((styles & xtd::number_styles::allow_trailing_white) == xtd::number_styles::allow_trailing_white) str = xtd::strings::trim_end(str);
  if ((styles & xtd::number_styles::allow_binary_specifier) == xtd::number_styles::allow_binary_specifier && (xtd::strings::starts_with(str, "0b") || xtd::strings::starts_with(str, "0B"))) str = xtd::strings::remove(str, 0, 2);
  if ((styles & xtd::number_styles::allow_octal_specifier) == xtd::number_styles::allow_octal_specifier && xtd::strings::starts_with(str, '0')) str = xtd::strings::remove(str, 0, 1);
  if ((styles & xtd::number_styles::allow_hex_specifier) == xtd::number_styles::allow_hex_specifier && (xtd::strings::starts_with(str, "0x") || xtd::strings::starts_with(str, "0X"))) str = xtd::strings::remove(str, 0, 2);

  size_t pos = 0;
  if (std::is_unsigned<Value>::value) {
    unsigned long long result = std::stoull(str, &pos, base);
    if (result < std::numeric_limits<Value>::min() || result > std::numeric_limits<Value>::max()) throw std::range_error("Out of range");
    return static_cast<Value>(result);
  }

  long long result = std::stoll(str, &pos, base);
  if (result < std::numeric_limits<Value>::min() || result > std::numeric_limits<Value>::max()) throw std::range_error("Out of range");
  return static_cast<Value>(result);
}

/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  template<typename Value>
  inline Value parse(const std::string& str) {throw std::invalid_argument("Parse speciailisation not found");}

  template<>
  inline std::string parse<std::string>(const std::string& str) {return str;}

  template<typename Value>
  inline Value parse(const std::string& str, number_styles) {throw std::invalid_argument("Parse speciailisation not found");}
  
  template<>
  inline char parse<char>(const std::string& str, number_styles styles) {return __parse_number<char>(str, styles);}
  
  template<>
  inline unsigned char parse<unsigned char>(const std::string& str, number_styles styles) {return __parse_number<unsigned char>(str, styles);}
  
  template<>
  inline short parse<short>(const std::string& str, number_styles styles) {return __parse_number<short>(str, styles);}
  
  template<>
  inline unsigned short parse<unsigned short>(const std::string& str, number_styles styles) {return __parse_number<unsigned short>(str, styles);}

  template<>
  inline int parse<int>(const std::string& str, number_styles styles) {return __parse_number<int>(str, styles);}
  
  template<>
  inline unsigned int parse<unsigned int>(const std::string& str, number_styles styles) {return __parse_number<unsigned int>(str, styles);}

  template<>
  inline long parse<long>(const std::string& str, number_styles styles) {return __parse_number<long>(str, styles);}
  
  template<>
  inline unsigned long parse<unsigned long>(const std::string& str, number_styles styles) {return __parse_number<unsigned long>(str, styles);}

  template<>
  inline long long parse<long long>(const std::string& str, number_styles styles) {return __parse_number<long long>(str, styles);}
  
  template<>
  inline unsigned long long parse<unsigned long long>(const std::string& str, number_styles styles) {return __parse_number<unsigned long long>(str, styles);}

  template<>
  inline char parse<char>(const std::string& str) {return parse<char>(str, number_styles::integer);}
  
  template<>
  inline unsigned char parse<unsigned char>(const std::string& str) {return parse<unsigned char>(str, number_styles::integer);}

  template<>
  inline short parse<short>(const std::string& str) {return parse<short>(str, number_styles::integer);}
  
  template<>
  inline unsigned short parse<unsigned short>(const std::string& str) {return parse<unsigned short>(str, number_styles::integer);}

  template<>
  inline int parse<int>(const std::string& str) {return parse<int>(str, number_styles::integer);}
  
  template<>
  inline unsigned int parse<unsigned int>(const std::string& str) {return parse<unsigned int>(str, number_styles::integer);}

  template<>
  inline long parse<long>(const std::string& str) {return parse<long>(str, number_styles::integer);}
  
  template<>
  inline unsigned long parse<unsigned long>(const std::string& str) {return parse<unsigned long>(str, number_styles::integer);}

  template<>
  inline long long parse<long long>(const std::string& str) {return parse<long long>(str, number_styles::integer);}

  template<>
  inline unsigned long long parse<unsigned long long>(const std::string& str) {return parse<unsigned long long>(str, number_styles::integer);}

  template<typename Value>
  inline bool try_parse(const std::string& str, Value& value) {
    try {
      value = parse<Value>(str);
      return true;
    } catch(...) {
      return false;
    }
  }
}


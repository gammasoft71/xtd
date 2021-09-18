/// @file
/// @brief Contains xtd::parse methods.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <string>
/// @cond
#define __XTD_CORE_INTERNAL__
#include "internal/__parse.h"
#undef __XTD_CORE_INTERNAL__
/// @endcond
#include "number_styles.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  template<typename value_t>
  inline value_t parse(const std::string& str) {__throw_parse_format_exception("Parse specialisation not found"); return {};}

  template<typename value_t>
  inline value_t parse(const std::string& str, const std::string& fmt) {__throw_parse_format_exception("Parse specialisation not found"); return {};}

  template<>
  inline std::string parse<std::string>(const std::string& str) {return str;}

  template<typename value_t>
  inline value_t parse(const std::string& str, number_styles) {__throw_parse_format_exception("Parse specialisation not found"); return {};}
  
  template<>
  inline int8_t parse<int8_t>(const std::string& str, number_styles styles) {return __parse_number<int8_t>(str, styles);}
  
  template<>
  inline char parse<char>(const std::string& str, number_styles styles) {return __parse_number<char>(str, styles);}
  
  template<>
  inline unsigned char parse<unsigned char>(const std::string& str, number_styles styles) {return __parse_unsigned_number<unsigned char>(str, styles);}
  
  template<>
  inline short parse<short>(const std::string& str, number_styles styles) {return __parse_number<short>(str, styles);}
  
  template<>
  inline unsigned short parse<unsigned short>(const std::string& str, number_styles styles) {return __parse_unsigned_number<unsigned short>(str, styles);}

  template<>
  inline int parse<int>(const std::string& str, number_styles styles) {return __parse_number<int>(str, styles);}
  
  template<>
  inline unsigned int parse<unsigned int>(const std::string& str, number_styles styles) {return __parse_unsigned_number<unsigned int>(str, styles);}

  template<>
  inline long parse<long>(const std::string& str, number_styles styles) {return __parse_number<long>(str, styles);}
  
  template<>
  inline unsigned long parse<unsigned long>(const std::string& str, number_styles styles) {return __parse_unsigned_number<unsigned long>(str, styles);}

  template<>
  inline long long parse<long long>(const std::string& str, number_styles styles) {return __parse_number<long long>(str, styles);}
  
  template<>
  inline unsigned long long parse<unsigned long long>(const std::string& str, number_styles styles) {return __parse_unsigned_number<unsigned long long>(str, styles);}

  template<>
  inline float parse<float>(const std::string& str, number_styles styles) {return __parse_floating_point_number<float>(str, styles);}

  template<>
  inline double parse<double>(const std::string& str, number_styles styles) {return __parse_floating_point_number<double>(str, styles);}

  template<>
  inline long double parse<long double>(const std::string& str, number_styles styles) {return __parse_floating_point_number<long double>(str, styles);}

  template<>
  inline int8_t parse<int8_t>(const std::string& str) {return parse<int8_t>(str, number_styles::integer);}
  
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

  template<>
  inline float parse<float>(const std::string& str) {return parse<float>(str, number_styles::fixed_point);}

  template<>
  inline double parse<double>(const std::string& str) {return parse<double>(str, number_styles::fixed_point);}

  template<>
  inline long double parse<long double>(const std::string& str) {return parse<long double>(str, number_styles::fixed_point);}

  template<>
  inline bool parse<bool>(const std::string& str) {
    std::string lower_str = str;
    while(lower_str.size() > 0 && (lower_str[0] == 9 || lower_str[0] == 10 || lower_str[0] == 11 || lower_str[0] == 12 || lower_str[0] == 13 || lower_str[0] == 32))
      lower_str.erase(0, 1);
    for (auto& c : lower_str)
      c = static_cast<char>(std::tolower(c));
    if (lower_str != "true" && lower_str != "1" && lower_str != "false" && lower_str != "0")  __throw_parse_format_exception("Invalid string format");
    return lower_str == "true" || lower_str == "1";
  }

  template<typename value_t>
  inline value_t parse(const std::wstring& str) {__throw_parse_format_exception("Parse specialisation not found"); return {};}

  template<typename value_t>
  inline value_t parse(const std::u16string& str) {__throw_parse_format_exception("Parse specialisation not found"); return {};}

  template<typename value_t>
  inline value_t parse(const std::u32string& str) {__throw_parse_format_exception("Parse specialisation not found"); return {};}

  template<typename value_t, typename char_t>
  inline bool try_parse(const std::basic_string<char_t>& str, value_t& value) {
    try {
      value = parse<value_t>(str);
      return true;
    } catch(...) {
      return false;
    }
  }

  template<typename value_t, typename char_t>
  inline bool try_parse(const char_t* str, value_t& value) {
    return try_parse(std::basic_string<char_t>(str), value);
  }
}


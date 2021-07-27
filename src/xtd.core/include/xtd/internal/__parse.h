/// @file
/// @brief Contains parse methods.
#pragma once
/// @cond
#ifndef __XTD_CORE_INTERNAL__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <locale>
#include <string>
#include <sstream>
#include "__parse_exception.h"
#include "../number_styles.h"

/// @cond
template <typename char_t>
inline std::basic_string<char_t> __parse_remove_decorations(const std::basic_string<char_t>& s, xtd::number_styles styles) {
  std::basic_string<char_t> str(s);
  if ((styles & xtd::number_styles::allow_leading_white) == xtd::number_styles::allow_leading_white) {
    while(str.size() > 0 && (str[0] == 9 || str[0] == 10 || str[0] == 11 || str[0] == 12 || str[0] == 13 || str[0] == 32))
      str.erase(0, 1);
  }
  if ((styles & xtd::number_styles::allow_trailing_white) == xtd::number_styles::allow_trailing_white) {
    while(str.size() > 0 && (str[str.size() - 1] == 9 || str[str.size() - 1] == 10 || str[str.size() - 1] == 11 || str[str.size() - 1] == 12 || str[str.size() - 1] == 13 || str[str.size() - 1] == 32))
      str.erase(str.size() - 1, 1);
  }
  if ((styles & xtd::number_styles::allow_currency_symbol) == xtd::number_styles::allow_currency_symbol && str.find(std::use_facet<std::moneypunct<char_t>>(std::locale()).curr_symbol()) == 0) str.erase(0, std::use_facet<std::moneypunct<char_t>>(std::locale()).curr_symbol().size());
  if ((styles & xtd::number_styles::allow_currency_symbol) == xtd::number_styles::allow_currency_symbol && str.rfind(std::use_facet<std::moneypunct<char_t>>(std::locale()).curr_symbol()) + std::use_facet<std::moneypunct<char_t>>(std::locale()).curr_symbol().size() == str.size()) str = str.substr(0, str.size() - std::use_facet<std::moneypunct<char_t>>(std::locale()).curr_symbol().size());
  if ((styles & xtd::number_styles::allow_binary_specifier) == xtd::number_styles::allow_binary_specifier && (str.find("0b") == 0 || str.find("0B") == 0)) str.erase(0, 2);
  if ((styles & xtd::number_styles::allow_octal_specifier) == xtd::number_styles::allow_octal_specifier && str.find('0') == 0) str.erase(0, 1);
  if ((styles & xtd::number_styles::allow_hex_specifier) == xtd::number_styles::allow_hex_specifier && (str.find("0x") == 0 || str.find("0X") == 0)) str.erase(0, 2);
  return str;
}

template <typename char_t>
inline int __parse_remove_signs(std::basic_string<char_t>& str, xtd::number_styles styles) {
  int sign = 0;
  
  while ((styles & xtd::number_styles::allow_leading_sign) == xtd::number_styles::allow_leading_sign && str.find("+") == 0) {
    if (sign != 0) __throw_parse_argument_exception("String contains more than one sign");
    str = str.substr(1, str.size()-1);
    sign += 1;
  }
  
  while ((styles & xtd::number_styles::allow_leading_sign) == xtd::number_styles::allow_leading_sign && str.find("-") == 0) {
    if (sign != 0) __throw_parse_argument_exception("String contains more than one sign");
    str = str.substr(1, str.size()-1);
    sign -= 1;
  }
  
  while ((styles & xtd::number_styles::allow_trailing_sign) == xtd::number_styles::allow_trailing_sign && str.rfind("+") + 1 == str.size()) {
    if (sign != 0) __throw_parse_argument_exception("String contains more than one sign");
    str = str.substr(0, str.size()-1);
    sign += 1;
  }
  
  while ((styles & xtd::number_styles::allow_trailing_sign) == xtd::number_styles::allow_trailing_sign && str.rfind("-") + 1 == str.size()) {
    if (sign != 0) __throw_parse_argument_exception("String contains more than one sign");
    str = str.substr(0, str.size()-1);
    sign -= 1;
  }
  
  while ((styles & xtd::number_styles::allow_parentheses) == xtd::number_styles::allow_parentheses && str.find("(") == 0 && str.rfind(")") + 1 == str.size()) {
    str = str.substr(1, str.size()-2);
    if (sign != 0) __throw_parse_argument_exception("String contains more than one sign");
    sign -= 1;
  }
  return sign;
}

template <typename char_t>
inline void __parse_check_valid_characters(const std::basic_string<char_t>& str, xtd::number_styles styles) {
  std::basic_string<char_t> valid_characters = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  if ((styles & xtd::number_styles::allow_binary_specifier) == xtd::number_styles::allow_binary_specifier) valid_characters.erase(2);
  if ((styles & xtd::number_styles::allow_octal_specifier) == xtd::number_styles::allow_octal_specifier) valid_characters.erase(7);
  if ((styles & xtd::number_styles::allow_hex_specifier) == xtd::number_styles::allow_hex_specifier) valid_characters += std::basic_string<char_t> {'A', 'B', 'C', 'D', 'E', 'F', 'a', 'b', 'c', 'd', 'e', 'f'};
  if ((styles & xtd::number_styles::allow_decimal_point) == xtd::number_styles::allow_decimal_point) valid_characters += std::basic_string<char_t> {std::use_facet<std::numpunct<char_t>>(std::locale()).decimal_point(), '.'};
  if ((styles & xtd::number_styles::allow_thousands) == xtd::number_styles::allow_thousands) valid_characters += std::use_facet<std::numpunct<char_t>>(std::locale()).thousands_sep();
  if ((styles & xtd::number_styles::allow_exponent) == xtd::number_styles::allow_exponent) valid_characters += std::basic_string<char_t> {'E', 'e', '+', '-'};
  
  for (auto c : str) {
    if (valid_characters.find(c) == std::basic_string<char_t>::npos)
      __throw_parse_argument_exception("invalid character found");
  }
  
  if ((styles & xtd::number_styles::allow_decimal_point) == xtd::number_styles::allow_decimal_point) {
    size_t index = str.find(std::use_facet<std::numpunct<char_t>>(std::locale()).decimal_point());
    if (index != std::basic_string<char_t>::npos && str.find(std::use_facet<std::numpunct<char_t>>(std::locale()).decimal_point(), index + 1) != std::basic_string<char_t>::npos)
      __throw_parse_argument_exception("invalid character found");
  }
  
  if ((styles & xtd::number_styles::allow_thousands) == xtd::number_styles::allow_thousands) {
    size_t index = 1;
    while((index = str.find(std::use_facet<std::numpunct<char_t>>(std::locale()).thousands_sep(), index)) != std::basic_string<char_t>::npos) {
      if (str[index - 1] == std::use_facet<std::numpunct<char_t>>(std::locale()).thousands_sep())
        __throw_parse_argument_exception("invalid character found");
      ++index;
    }
  }
  
  if ((styles & xtd::number_styles::allow_exponent) == xtd::number_styles::allow_exponent) {
    size_t index = str.find('+');
    if (index == std::basic_string<char_t>::npos) index = str.find('-');
    if (index != std::basic_string<char_t>::npos && str[index - 1] != 'e' && str[index - 1] != 'E')
      __throw_parse_argument_exception("invalid character found");
  }
}

template <typename value_t, typename char_t>
inline value_t __parse_floating_point(const std::basic_string<char_t>& str, int sign, xtd::number_styles styles) {
  long double result;
  if ((styles & xtd::number_styles::allow_thousands) != xtd::number_styles::allow_thousands)
    result = std::stold(str, nullptr);
  else {
    std::stringstream ss(str);
    ss.imbue(std::locale());
    ss >> result;
  }
  
  result = sign < 0 ? -result : result;
  if (result < std::numeric_limits<value_t>::min() || result > std::numeric_limits<value_t>::max()) __throw_parse_index_out_of_range_exception();
  return static_cast<value_t>(result);
}

template <typename value_t, typename char_t>
inline value_t __parse_signed(const std::basic_string<char_t>& str, int base, int sign, xtd::number_styles styles) {
  long long result;
  if ((styles & xtd::number_styles::allow_thousands) != xtd::number_styles::allow_thousands)
    result = std::stoll(str, nullptr, base);
  else {
    std::stringstream ss(str);
    ss.imbue(std::locale());
    ss >> result;
  }
  
  result = sign < 0 ? -result : result;
  if (result < std::numeric_limits<value_t>::min() || result > std::numeric_limits<value_t>::max()) __throw_parse_index_out_of_range_exception();
  return static_cast<value_t>(result);
}

template <typename value_t, typename char_t>
inline value_t __parse_unsigned(const std::basic_string<char_t>& str, int base, xtd::number_styles styles) {
  unsigned long long result = 0;
  if ((styles & xtd::number_styles::allow_thousands) != xtd::number_styles::allow_thousands)
    result = std::stoull(str, nullptr, base);
  else{
    std::stringstream ss(str);
    ss.imbue(std::locale());
    ss >> result;
  }
  
  if (result > std::numeric_limits<value_t>::max()) __throw_parse_index_out_of_range_exception();
  return static_cast<value_t>(result);
}

template <typename value_t, typename char_t>
inline value_t __parse_floating_point_number(const std::basic_string<char_t>& s, xtd::number_styles styles) {
  if ((styles & xtd::number_styles::binary_number) == xtd::number_styles::binary_number) __throw_parse_argument_exception("xtd::number_styles::binary_number not supported by floating point");
  if ((styles & xtd::number_styles::octal_number) == xtd::number_styles::octal_number) __throw_parse_argument_exception("xtd::number_styles::octal_number not supported by floating point");
  if ((styles & xtd::number_styles::hex_number) == xtd::number_styles::hex_number) __throw_parse_argument_exception("xtd::number_styles::hex_number not supported by floating point");
  
  std::basic_string<char_t> str = __parse_remove_decorations(s, styles);
  int sign = __parse_remove_signs(str, styles);
  
  __parse_check_valid_characters(str, styles);
  
  long double result;
  if ((styles & xtd::number_styles::allow_thousands) != xtd::number_styles::allow_thousands)
    result = std::stold(str, nullptr);
  else {
    std::stringstream ss(str);
    ss.imbue(std::locale());
    ss >> result;
  }
  
  result = sign < 0 ? -result : result;
  if (result < -std::numeric_limits<value_t>::max() || result > std::numeric_limits<value_t>::max()) __throw_parse_index_out_of_range_exception();
  return static_cast<value_t>(result);
}

template <typename value_t, typename char_t>
inline value_t __parse_number(const std::basic_string<char_t>& s, xtd::number_styles styles) {
  if ((styles & xtd::number_styles::allow_binary_specifier) == xtd::number_styles::allow_binary_specifier && (styles - xtd::number_styles::binary_number) != xtd::number_styles::none) __throw_parse_argument_exception("Invalid xtd::number_styles flags");
  if ((styles & xtd::number_styles::allow_octal_specifier) == xtd::number_styles::allow_octal_specifier && (styles - xtd::number_styles::octal_number) != xtd::number_styles::none) __throw_parse_argument_exception("Invalid xtd::number_styles flags");
  if ((styles & xtd::number_styles::allow_hex_specifier) == xtd::number_styles::allow_hex_specifier && (styles - xtd::number_styles::hex_number) != xtd::number_styles::none) __throw_parse_argument_exception("Invalid xtd::number_styles flags");
  
  int base = 10;
  if ((styles & xtd::number_styles::binary_number) == xtd::number_styles::binary_number) base = 2;
  if ((styles & xtd::number_styles::octal_number) == xtd::number_styles::octal_number) base = 8;
  if ((styles & xtd::number_styles::hex_number) == xtd::number_styles::hex_number) base = 16;
  
  std::basic_string<char_t> str = __parse_remove_decorations(s, styles);
  int sign = __parse_remove_signs(str, styles);
  
  __parse_check_valid_characters(str, styles);
  
  if (std::is_floating_point<value_t>::value || (styles & xtd::number_styles::allow_exponent) == xtd::number_styles::allow_exponent) return __parse_floating_point<value_t>(str, sign, styles);
  return __parse_signed<value_t>(str, base, sign, styles);
}

template <typename value_t, typename char_t>
inline value_t __parse_unsigned_number(const std::basic_string<char_t>& s, xtd::number_styles styles) {
  if ((styles & xtd::number_styles::allow_binary_specifier) == xtd::number_styles::allow_binary_specifier && (styles - xtd::number_styles::binary_number) != xtd::number_styles::none) __throw_parse_argument_exception("Invalid xtd::number_styles flags");
  if ((styles & xtd::number_styles::allow_octal_specifier) == xtd::number_styles::allow_octal_specifier && (styles - xtd::number_styles::octal_number) != xtd::number_styles::none) __throw_parse_argument_exception("Invalid xtd::number_styles flags");
  if ((styles & xtd::number_styles::allow_hex_specifier) == xtd::number_styles::allow_hex_specifier && (styles - xtd::number_styles::hex_number) != xtd::number_styles::none) __throw_parse_argument_exception("Invalid xtd::number_styles flags");
  
  int base = 10;
  if ((styles & xtd::number_styles::binary_number) == xtd::number_styles::binary_number) base = 2;
  if ((styles & xtd::number_styles::octal_number) == xtd::number_styles::octal_number) base = 8;
  if ((styles & xtd::number_styles::hex_number) == xtd::number_styles::hex_number) base = 16;
  
  std::basic_string<char_t> str = __parse_remove_decorations(s, styles);
  if (__parse_remove_signs(str, styles) < 0) __throw_parse_argument_exception("unsigned type can't have minus sign");
  
  __parse_check_valid_characters(str, styles);
  
  if ((styles & xtd::number_styles::allow_exponent) == xtd::number_styles::allow_exponent) return __parse_floating_point<value_t>(str, 0, styles);
  return __parse_unsigned<value_t>(str, base, styles);
}
/// @endcond

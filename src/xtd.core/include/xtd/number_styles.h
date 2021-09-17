/// @file
/// @brief Contains xtd::number_styles enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Determines the styles permitted in numeric string arguments that are passed to the xtd::parse and xtd::try_parse methods of the integral and floating-point numeric types.
  /// This enumeration has a flags attribute that allows a bitwise combination of its member values.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  enum class number_styles {
    /// @brief Indicates that no style elements, such as leading or trailing white space, thousands separators, or a decimal separator, can be present in the parsed string. The string to be parsed must consist of integral decimal digits only.
    none = 0x0,
    /// @brief Indicates that leading white-space characters can be present in the parsed string. Valid white-space characters have the Unicode values U+0009, U+000A, U+000B, U+000C, U+000D, and U+0020. Note that this is a subset of the characters for which the std::isspace(char) method returns true.
    allow_leading_white = 0b1,
    /// @brief Indicates that trailing white-space characters can be present in the parsed string. Valid white-space characters have the Unicode values U+0009, U+000A, U+000B, U+000C, U+000D, and U+0020. Note that this is a subset of the characters for which the std::isspace(char) method returns true.
    allow_trailing_white = 0b10,
    /// @brief Indicates that the numeric string can have a leading sign.
    allow_leading_sign = 0b100,
    /// @brief Indicates that the numeric string can have a trailing sign. Valid trailing sign characters are determined by the positive_sign and negative_sign properties.
    allow_trailing_sign = 0b1000,
    /// @brief Indicates that the numeric string can have one pair of parentheses enclosing the number. The parentheses indicate that the string to be parsed represents a negative number.
    allow_parentheses = 0b10000,
    /// @brief Indicates that the numeric string can have a decimal point. If the number_styles value includes the allow_currency_symbol flag and the parsed string includes a currency symbol, the decimal separator character is determined by the std::use_facet<std::numpunct<char>>(std::locale()).decimal_point() method.
    allow_decimal_point = 0b100000,
    /// @brief Indicates that the numeric string can have group separators, such as symbols that separate hundreds from thousands. If the number_styles value includes the allow_currency_symbol flag and the string to be parsed includes a currency symbol, the valid group separator character is determined by the currency_group_separator property, and the number of digits in each group is determined by the currency_Group_sizes property. Otherwise, the valid group separator character is determined by the number_group_separator property, and the number of digits in each group is determined by the number_group_sizes property.
    allow_thousands = 0b1000000,
    /// @brief Indicates that the numeric string can be in exponential notation. The allow_exponent flag allows the parsed string to contain an exponent that begins with the "E" or "e" character and that is followed by an optional positive or negative sign and an integer. In other words, it successfully parses strings in the form nnnExx, nnnE+xx, and nnnE-xx. It does not allow a decimal separator or sign in the significand or mantissa; to allow these elements in the string to be parsed, use the allow_decimal_point and allow_leading_sign flags, or use a composite style that includes these individual flags.
    allow_exponent = 0b10000000,
    /// @brief Indicates that the numeric string can contain a currency symbol. Valid currency symbols are determined by the std::use_facet<std::moneypunct<char>>(std::locale()).curr_symbol() method.
    allow_currency_symbol = 0b100000000,
    /// @brief Indicates that the numeric string represents a hexadecimal value. Valid hexadecimal values include the numeric digits 0-9 and the hexadecimal digits A-F and a-f. Strings that are parsed using this style can be prefixed with "0x". A string that is parsed with the allow_hex_specifier style will always be interpreted as a hexadecimal value. The only flags that can be combined with allow_hex_specifier are allow_leading_white and allow_trailing_white. The number_styles enumeration includes a composite style, hex_number, that consists of these three flags.
    allow_hex_specifier = 0b1000000000,
    /// @brief Indicates that the numeric string represents a binary value. Valid binary values include the numeric digits 0 and 1. Strings that are parsed using this style can be prefixed with "0b". A string that is parsed with the allow_binary_specifier style will always be interpreted as a binary value. The only flags that can be combined with allow_binary_specifier are allow_leading_white and allow_trailing_white. The number_styles enumeration includes a composite style, binary_number, that consists of these three flags.
    allow_binary_specifier = 0b10000000000,
    /// @brief Indicates that the numeric string represents a octal value. Valid octal values include the numeric digits 0-7. Strings that are parsed using this style can be prefixed with "0". A string that is parsed with the allow_octal_specifier style will always be interpreted as an octal value. The only flags that can be combined with allow_octal_specifier are allow_leading_white and allow_trailing_white. The number_styles enumeration includes a composite style, octal_number, that consists of these three flags.
    allow_octal_specifier = 0b100000000000,
    /// @brief Indicates that the allow_leading_white, allow_trailing_white, and allow_leading_sign styles are used. This is a composite number style.
    integer = allow_leading_white + allow_trailing_white + allow_leading_sign,
    /// @brief Indicates that the allow_leading_white, allow_trailing_white, allow_leading_sign, allow_trailing_sign, allow_decimal_point, and allow_thousands styles are used. This is a composite number style.
    number = allow_leading_white + allow_trailing_white + allow_leading_sign + allow_trailing_sign + allow_decimal_point + allow_thousands,
    /// @brief Indicates that the allow_leading_white, allow_trailing_white, allow_leading_sign, allow_decimal_point, and allow_exponent styles are used. This is a composite number style.
    fixed_point = allow_leading_white + allow_trailing_white + allow_leading_sign + allow_decimal_point + allow_exponent,
    /// @brief Indicates that all styles except allow_exponent, allow_hex_specifier, allow_binary_specifier and allow_octal_specifier are used. This is a composite number style.
    currency = allow_leading_white + allow_trailing_white + allow_leading_sign + allow_trailing_sign + allow_parentheses + allow_decimal_point + allow_thousands + allow_currency_symbol,
    /// @brief Indicates that all styles except allow_binary_specifier, allow_octal_specifier and allow_hex_specifier are used. This is a composite number style.
    any = allow_leading_white + allow_trailing_white + allow_leading_sign + allow_trailing_sign + allow_parentheses + allow_decimal_point + allow_thousands + allow_exponent + allow_currency_symbol,
    /// @brief Indicates that the allow_leading_white, allow_trailing_white, and allow_hex_specifier styles are used. This is a composite number style.
    hex_number = allow_leading_white + allow_trailing_white + allow_hex_specifier,
    /// @brief Indicates that the allow_leading_white, allow_trailing_white, and allow_binary_specifier styles are used. This is a composite number style.
    binary_number = allow_leading_white + allow_trailing_white + allow_binary_specifier,
    /// @brief Indicates that the allow_leading_white, allow_trailing_white, and allow_octal_specifier styles are used. This is a composite number style.
    octal_number = allow_leading_white + allow_trailing_white + allow_octal_specifier,
  };

  /// @cond
  inline xtd::number_styles& operator^=(xtd::number_styles& lhs, xtd::number_styles rhs) {lhs = static_cast<xtd::number_styles>(static_cast<int>(lhs) ^ static_cast<int>(rhs)); return lhs;}
  inline xtd::number_styles& operator&=(xtd::number_styles& lhs, xtd::number_styles rhs) {lhs = static_cast<xtd::number_styles>(static_cast<int>(lhs) & static_cast<int>(rhs)); return lhs;}
  inline xtd::number_styles& operator|=(xtd::number_styles& lhs, xtd::number_styles rhs) {lhs = static_cast<xtd::number_styles>(static_cast<int>(lhs) | static_cast<int>(rhs)); return lhs;}
  inline xtd::number_styles& operator+=(xtd::number_styles& lhs, xtd::number_styles rhs) {lhs = static_cast<xtd::number_styles>(static_cast<int>(lhs) + static_cast<int>(rhs)); return lhs;}
  inline xtd::number_styles& operator-=(xtd::number_styles& lhs, xtd::number_styles rhs) {lhs = static_cast<xtd::number_styles>(static_cast<int>(lhs) - static_cast<int>(rhs)); return lhs;}
  
  inline xtd::number_styles operator^(xtd::number_styles lhs, xtd::number_styles rhs) {return static_cast<xtd::number_styles>(static_cast<int>(lhs) ^ static_cast<int>(rhs));}
  inline xtd::number_styles operator&(xtd::number_styles lhs, xtd::number_styles rhs) {return static_cast<xtd::number_styles>(static_cast<int>(lhs) & static_cast<int>(rhs));}
  inline xtd::number_styles operator|(xtd::number_styles lhs, xtd::number_styles rhs) {return static_cast<xtd::number_styles>(static_cast<int>(lhs) | static_cast<int>(rhs));}
  inline xtd::number_styles operator+(xtd::number_styles lhs, xtd::number_styles rhs) {return static_cast<xtd::number_styles>(static_cast<int>(lhs) + static_cast<int>(rhs));}
  inline xtd::number_styles operator-(xtd::number_styles lhs, xtd::number_styles rhs) {return static_cast<xtd::number_styles>(static_cast<int>(lhs) - static_cast<int>(rhs));}
  
  inline xtd::number_styles operator~(xtd::number_styles lhs) {return static_cast<xtd::number_styles>(~static_cast<int>(lhs));}
  /// @endcond
}

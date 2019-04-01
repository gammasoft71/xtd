/// @file
/// @brief Contains xtd::strings class.
#pragma once

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  enum class number_styles {
    none = 0x0,
    allow_leading_white = 0x1,
    allow_trailing_white = 0x2,
    allow_leading_sign = 0x4,
    integer = 0x7,
    allow_trailing_sign = 0x8,
    allow_parentheses = 0x10,
    allow_decimal_point = 0x20,
    allow_thousands = 0x40,
    number = 0x6F,
    allow_exponent = 0x80,
    fixed_point = 0xA7,
    allow_currency_symbol = 0x100,
    currency = 0x17F,
    any = 0x1FF,
    allow_hex_specifier = 0x200,
    hex_number = 0x203,
    allow_binary_specifier = 0x400,
    binary_number = 0x403,
    allow_octal_specifier = 0x800,
    octal_number = 0x803,
  };
}

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

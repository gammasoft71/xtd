/// @file
/// @brief Containsenum definitions.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once

#include "enum_attribute.h"
#include "enum_collection.h"
#include "enum_object.h"
#include "enum_register.h"
#include "enum_set_attribute.h"

/// @cond
template<> struct xtd::enum_register<xtd::enum_attribute> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::enum_attribute> {{enum_attribute::standard, "standard"}, {enum_attribute::flags, "flags"}};}
};

template<> struct xtd::enum_set_attribute<xtd::number_styles> {
  explicit operator auto() const noexcept {return xtd::enum_attribute::flags;}
};

template<> struct xtd::enum_register<xtd::number_styles> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::number_styles> {{xtd::number_styles::none, "none"}, {xtd::number_styles::allow_leading_white, "allow_leading_white"}, {xtd::number_styles::allow_trailing_white, "allow_trailing_white"}, {xtd::number_styles::allow_leading_sign, "allow_leading_sign"}, {xtd::number_styles::allow_trailing_sign, "allow_trailing_sign"}, {xtd::number_styles::allow_parentheses, "allow_parentheses"}, {xtd::number_styles::allow_decimal_point, "allow_decimal_point"}, {xtd::number_styles::allow_thousands, "allow_thousands"}, {xtd::number_styles::allow_exponent, "allow_exponent"}, {xtd::number_styles::allow_currency_symbol, "allow_currency_symbol"}, {xtd::number_styles::allow_hex_specifier, "allow_hex_specifier"}, {xtd::number_styles::allow_binary_specifier, "allow_binary_specifier"}, {xtd::number_styles::allow_octal_specifier, "allow_octal_specifier"}, {xtd::number_styles::integer, "integer"}, {xtd::number_styles::number, "number"}, {xtd::number_styles::fixed_point, "fixed_point"}, {xtd::number_styles::currency, "currency"}, {xtd::number_styles::any, "any"}, {xtd::number_styles::hex_number, "hex_number"}, {xtd::number_styles::binary_number, "binary_number"}, {xtd::number_styles::octal_number, "octal_number"}};}
};

template<> struct xtd::enum_register<xtd::string_comparison> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::string_comparison> {{xtd::string_comparison::ordinal, "ordinal"}, {xtd::string_comparison::ordinal_ignore_case, "ordinal_ignore_case"}};}
};

template<> struct xtd::enum_register<xtd::string_split_options> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::string_split_options> {{xtd::string_split_options::none, "none"}, {xtd::string_split_options::remove_empty_entries, "remove_empty_entries"}};}
};
/// @endcond


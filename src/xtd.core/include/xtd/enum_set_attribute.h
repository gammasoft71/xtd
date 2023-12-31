/// @file
/// @brief Contains xtd::enum_set_attribute strcut.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "enum_attribute.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides the set attribute struct for enumerations.
  /// @code
  /// template<typename enum_t>
  /// struct enum_set_attribute
  /// @endcode
  /// @par Header
  /// @code #include <xtd/enum_set_attribute> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks The overloading of this operator is necessary for enum classes to be recognized as having a flags attribute to be properly handled by xtd::ustring::format().
  /// @remarks For more information about enumeration, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/enum_class">enum class</a> guide.
  /// @remarks When an enumeration is registered, we can display its name instead of its value, we can format it and parse it.
  /// @remarks See <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Format%20number%20dates%20other%20types/enumeration_format_strings">Enumeration Format Strings</a>. For more information about formatting in general, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Format%20number%20dates%20other%20types/overview">Formatting Types</a>.
  /// @par Examples
  /// The following code show how to use xtd::enum_set_attribute operator.
  /// @include format_enum_class_flags_without_helpers.cpp
  template<typename enum_t>
  struct enum_set_attribute {
    /// Allows to set attribute to an enumeration that can be used by xtd::enum_object.
    /// @return One of xtd::enum_attribute values.
    /// @remarks To set attribute to an enumeration just override xtd::enum_set_attribute.
    /// @par Examples
    /// The following code show how to set attribute to the value_flags enum class.
    /// @code
    /// enum class value_flags {
    ///   value_none = 0,
    ///   value_one = 0b1,
    ///   value_two = 0b10,
    ///   value_three = 0b100,
    /// };
    ///
    /// template<>
    /// xtd::enum_set_attribute<value_flags> {
    ///   explicit operator auto() const noexcept {return xtd::enum_attribute::flags;}
    /// };
    /// @endcode
    explicit operator auto() const noexcept {return xtd::enum_attribute::standard;}
  };
}

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

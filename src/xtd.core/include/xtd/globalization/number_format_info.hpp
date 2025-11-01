/// @file
/// @brief Contains xtd::globalization::number_format_info class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once

#include "../core_export.hpp"
#include "../collections/generic/dictionary.hpp"
#include "../object.hpp"
#include "../string.hpp"
#include <locale>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Contains classes that define culture-related information, including language, country/region, calendars in use, format patterns for dates, currency, and numbers, and sort order for strings.
  namespace globalization {
    /// @cond
    class culture_info;
    /// @endcond
    
    /// @brief Provides culture-specific information about the format of numbers, currency, and percentages.
    /// ```cpp
    /// class number_format_info : public xtd::object
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::globalization::number_format_info
    /// @par Header
    /// ```cpp
    /// #include <xtd/globalization/number_format_info>
    /// ```
    /// @par Namespace
    /// xtd::globalization
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core globalization
    class core_export_ number_format_info : public xtd::object {
    public:
      /// @name Public Constructors
      /// @{
      number_format_info();
      number_format_info(number_format_info&& info) = default;
      number_format_info(const number_format_info& info);
      /// @}
      
      /// @name Public Properties
      /// @{
      int32 currency_decimal_digits() const noexcept;
      number_format_info& currency_decimal_digits(int32 value) noexcept;
      
      const xtd::string& currency_decimal_separator() const noexcept;
      number_format_info& currency_decimal_separator(const xtd::string& value) noexcept;
      
      const xtd::string& currency_group_separator() const noexcept;
      number_format_info& currency_group_separator(const xtd::string& value) noexcept;
      
      const xtd::array<int32>& currency_group_sizes() const noexcept;
      number_format_info& currency_group_sizes(const xtd::array<int32>& value) noexcept;
      
      int32 currency_negative_pattern() const noexcept;
      number_format_info& currency_negative_pattern(int32 value) noexcept;
      
      int32 currency_positive_pattern() const noexcept;
      number_format_info& currency_positive_pattern(int32 value) noexcept;
      
      const xtd::string& currency_symbol() const noexcept;
      number_format_info& currency_symbol(const xtd::string& value) noexcept;
      
      int32 digit_substitution() const noexcept;
      number_format_info& digit_substitution(int32 value) noexcept;
      
      const xtd::string& nan_symbol() const noexcept;
      number_format_info& nan_symbol(const xtd::string& value) noexcept;
      
      const xtd::string& negative_infinity_symbol() const noexcept;
      number_format_info& negative_infinity_symbol(const xtd::string& value) noexcept;
      
      const xtd::string& negative_sign() const noexcept;
      number_format_info& negative_sign(const xtd::string& value) noexcept;
      
      int32 number_decimal_digits() const noexcept;
      number_format_info& number_decimal_digits(int32 value) noexcept;
      
      const xtd::string& number_decimal_separator() const noexcept;
      number_format_info& number_decimal_separator(const xtd::string& value) noexcept;
      
      const xtd::string& number_group_separator() const noexcept;
      number_format_info& number_group_separator(const xtd::string& value) noexcept;
      
      const xtd::array<int32>& number_group_sizes() const noexcept;
      number_format_info& number_group_sizes(const xtd::array<int32>& value) noexcept;
      
      int32 number_negative_pattern() const noexcept;
      number_format_info& number_negative_pattern(int32 value) noexcept;
      
      int32 percent_decimal_digits() const noexcept;
      number_format_info& percent_decimal_digits(int32 value) noexcept;
      
      const xtd::string& percent_decimal_separator() const noexcept;
      number_format_info& percent_decimal_separator(const xtd::string& value) noexcept;
      
      const xtd::string& percent_group_separator() const noexcept;
      number_format_info& percent_group_separator(const xtd::string& value) noexcept;
      
      const xtd::array<int32>& percent_group_sizes() const noexcept;
      number_format_info& percent_group_sizes(const xtd::array<int32>& value) noexcept;
      
      int32 percent_negative_pattern() const noexcept;
      number_format_info& percent_negative_pattern(int32 value) noexcept;
      
      int32 percent_positive_pattern() const noexcept;
      number_format_info& percent_positive_pattern(int32 value) noexcept;
      
      const xtd::string& percent_symbol() const noexcept;
      number_format_info& percent_symbol(const xtd::string& value) noexcept;
      
      const xtd::string& per_mille_symbol() const noexcept;
      number_format_info& per_mille_symbol(const xtd::string& value) noexcept;
      
      const xtd::string& positive_infinity_symbol() const noexcept;
      number_format_info& positive_infinity_symbol(const xtd::string& value) noexcept;
      
      const xtd::string& positive_sign() const noexcept;
      number_format_info& positive_sign(const xtd::string& value) noexcept;
      /// @}
      
      /// @name Public Static Properties
      /// @{
      static const number_format_info& current_info() noexcept;
      static const number_format_info& invariant_info() noexcept;
      /// @}
      
      /// @name Public Operators
      /// @{
      number_format_info& operator=(number_format_info&& info) = default;
      number_format_info& operator=(const number_format_info& info);
      /// @}
      
    private:
      friend class culture_info;
      number_format_info(int32 currency_decimal_digits, xtd::string&& currency_decimal_separator, xtd::string&& currency_group_separator, xtd::array<int32>&& currency_group_sizes, int32 currency_negative_pattern, int32 currency_positive_pattern, xtd::string&& currency_symbol, int32 digit_substitution, xtd::string&& nan_symbol, xtd::string&& negative_infinity_symbol, xtd::string&& negative_sign, int32 number_decimal_digits, xtd::string&& number_decimal_separator, xtd::string&& number_group_separator, xtd::array<int32>&& number_group_sizes, int32 number_negative_pattern, int32 percent_decimal_digits, xtd::string&& percent_decimal_separator, xtd::string&& percent_group_separator, xtd::array<int32>&& percent_group_sizes, int32 percent_negative_pattern, int32 percent_positive_pattern, xtd::string&& percent_symbol, xtd::string&& per_mille_symbol, xtd::string&& positive_infinity_symbol, xtd::string&& positive_sign);
      static xtd::collections::generic::dictionary<xtd::string, number_format_info>& formats();
      
      struct data;
      ptr<data> data_;
    };
  }
}

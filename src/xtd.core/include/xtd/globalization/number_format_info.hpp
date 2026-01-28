/// @file
/// @brief Contains xtd::globalization::number_format_info class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
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
      number_format_info(xtd::globalization::number_format_info&& info) = default;
      number_format_info(const xtd::globalization::number_format_info& info);
      /// @}
      
      /// @name Public Properties
      /// @{
      [[nodiscard]] auto currency_decimal_digits() const noexcept -> xtd::int32;
      auto currency_decimal_digits(xtd::int32 value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto currency_decimal_separator() const noexcept -> const xtd::string&;
      auto currency_decimal_separator(const xtd::string& value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto currency_group_separator() const noexcept -> const xtd::string&;
      auto currency_group_separator(const xtd::string& value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto currency_group_sizes() const noexcept -> const xtd::array<xtd::int32>& ;
      auto currency_group_sizes(const xtd::array<xtd::int32>& value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto currency_negative_pattern() const noexcept -> xtd::int32;
      auto currency_negative_pattern(xtd::int32 value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto currency_positive_pattern() const noexcept -> xtd::int32;
      auto currency_positive_pattern(xtd::int32 value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto currency_symbol() const noexcept -> const xtd::string&;
      auto currency_symbol(const xtd::string& value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto digit_substitution() const noexcept -> xtd::int32;
      auto digit_substitution(xtd::int32 value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto nan_symbol() const noexcept -> const xtd::string&;
      auto nan_symbol(const xtd::string& value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto negative_infinity_symbol() const noexcept -> const xtd::string&;
      auto negative_infinity_symbol(const xtd::string& value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto negative_sign() const noexcept -> const xtd::string&;
      auto negative_sign(const xtd::string& value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto number_decimal_digits() const noexcept -> xtd::int32;
      auto number_decimal_digits(xtd::int32 value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto number_decimal_separator() const noexcept -> const xtd::string&;
      auto number_decimal_separator(const xtd::string& value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto number_group_separator() const noexcept -> const xtd::string&;
      auto number_group_separator(const xtd::string& value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto number_group_sizes() const noexcept -> const xtd::array<xtd::int32>& ;
      auto number_group_sizes(const xtd::array<xtd::int32>& value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto number_negative_pattern() const noexcept -> xtd::int32;
      auto number_negative_pattern(xtd::int32 value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto percent_decimal_digits() const noexcept -> xtd::int32;
      auto percent_decimal_digits(xtd::int32 value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto percent_decimal_separator() const noexcept -> const xtd::string&;
      auto percent_decimal_separator(const xtd::string& value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto percent_group_separator() const noexcept -> const xtd::string&;
      auto percent_group_separator(const xtd::string& value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto percent_group_sizes() const noexcept -> const xtd::array<xtd::int32>& ;
      auto percent_group_sizes(const xtd::array<xtd::int32>& value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto percent_negative_pattern() const noexcept -> xtd::int32;
      auto percent_negative_pattern(xtd::int32 value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto percent_positive_pattern() const noexcept -> xtd::int32;
      auto percent_positive_pattern(xtd::int32 value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto percent_symbol() const noexcept -> const xtd::string&;
      auto percent_symbol(const xtd::string& value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto per_mille_symbol() const noexcept -> const xtd::string&;
      auto per_mille_symbol(const xtd::string& value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto positive_infinity_symbol() const noexcept -> const xtd::string&;
      auto positive_infinity_symbol(const xtd::string& value) noexcept -> xtd::globalization::number_format_info&;
      
      [[nodiscard]] auto positive_sign() const noexcept -> const xtd::string&;
      auto positive_sign(const xtd::string& value) noexcept -> xtd::globalization::number_format_info&;
      /// @}
      
      /// @name Public Static Properties
      /// @{
      [[nodiscard]] static auto current_info() noexcept -> const xtd::globalization::number_format_info&;
      [[nodiscard]] static auto invariant_info() noexcept -> const xtd::globalization::number_format_info&;
      /// @}
      
      /// @name Public Operators
      /// @{
      auto operator=(xtd::globalization::number_format_info&& info) -> xtd::globalization::number_format_info& = default;
      auto operator=(const xtd::globalization::number_format_info& info) -> xtd::globalization::number_format_info&;
      /// @}
      
    private:
      friend class culture_info;
      number_format_info(xtd::int32 currency_decimal_digits, xtd::string&& currency_decimal_separator, xtd::string&& currency_group_separator, xtd::array<xtd::int32>&& currency_group_sizes, xtd::int32 currency_negative_pattern, xtd::int32 currency_positive_pattern, xtd::string&& currency_symbol, xtd::int32 digit_substitution, xtd::string&& nan_symbol, xtd::string&& negative_infinity_symbol, xtd::string&& negative_sign, xtd::int32 number_decimal_digits, xtd::string&& number_decimal_separator, xtd::string&& number_group_separator, xtd::array<xtd::int32>&& number_group_sizes, xtd::int32 number_negative_pattern, xtd::int32 percent_decimal_digits, xtd::string&& percent_decimal_separator, xtd::string&& percent_group_separator, xtd::array<xtd::int32>&& percent_group_sizes, xtd::int32 percent_negative_pattern, xtd::int32 percent_positive_pattern, xtd::string&& percent_symbol, xtd::string&& per_mille_symbol, xtd::string&& positive_infinity_symbol, xtd::string&& positive_sign);
      static auto formats() -> xtd::collections::generic::dictionary<xtd::string, xtd::globalization::number_format_info>& ;
      
      struct data;
      ptr<data> data_;
    };
  }
}

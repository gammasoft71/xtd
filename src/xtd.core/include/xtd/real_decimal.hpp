/// @file
/// @brief Contains xtd::real_decimal concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "decimal.hpp"
#include "raw_type.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Concept real_decimal.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::real_decimal = std::same_as<xtd::raw_type<type_t>, xtd::single>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/real_decimal>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::real_decimal conceps
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_real_decimal(auto value) noexcept {
  ///   println("{} ({}) {} real_decimal", value, type_of(value), real_decimal<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_real_decimal(42_s8);
  ///   print_is_real_decimal(42_s16);
  ///   print_is_real_decimal(42_s32);
  ///   print_is_real_decimal(42_s64);
  ///   print_is_real_decimal(42_u8);
  ///   print_is_real_decimal(42_u16);
  ///   print_is_real_decimal(42_u32);
  ///   print_is_real_decimal(42_u64);
  ///   print_is_real_decimal(42_z);
  ///   print_is_real_decimal(42.84f);
  ///   print_is_real_decimal(42.84);
  ///   print_is_real_decimal(42.84l);
  ///   print_is_real_decimal('a');
  ///   print_is_real_decimal(true);
  ///   print_is_real_decimal("string"_s);
  ///   print_is_real_decimal("string");
  ///   print_is_real_decimal(1_h + 12_min + 24_s + 48_ms);
  ///   print_is_real_decimal(day_of_week::wednesday);
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (signed char) is not real_decimal
  /// // 42 (short) is not real_decimal
  /// // 42 (int) is not real_decimal
  /// // 42 (long long) is not real_decimal
  /// // 42 (unsigned char) is not real_decimal
  /// // 42 (unsigned short) is not real_decimal
  /// // 42 (unsigned int) is not real_decimal
  /// // 42 (unsigned long long) is real_decimal
  /// // 42 (unsigned long) is real_decimal
  /// // 42.84 (float) is not real_decimal
  /// // 42.84 (decimal) is real_decimal
  /// // 42.84 (long decimal) is not real_decimal
  /// // true (bool) is not real_decimal
  /// // string (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) is not real_decimal
  /// // string (char const*) is not real_decimal
  /// // 01:12:24.0480000 (xtd::time_span) is not real_decimal
  /// // wednesday (xtd::day_of_week) is not real_decimal
  /// ```
  template<typename type_t>
  concept real_decimal =
  std::same_as<xtd::raw_type<type_t>, xtd::decimal>;
}

/// @file
/// @brief Contains xtd::numeric concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "types"
#include <type_traits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @concept xtd::numeric
  /// @brief Concept numeric.
  /// @par Definition
  /// ```cpp
  /// template<typename value_t>
  /// concept numeric;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/numeric>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::numeric conceps
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_numeric(auto value) noexcept {
  ///   println("{} ({}) {} numeric", value, type_of(value), numeric<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_numeric(42_s8);
  ///   print_is_numeric(42_s16);
  ///   print_is_numeric(42_s32);
  ///   print_is_numeric(42_s64);
  ///   print_is_numeric(42_u8);
  ///   print_is_numeric(42_u16);
  ///   print_is_numeric(42_u32);
  ///   print_is_numeric(42_u64);
  ///   print_is_numeric(42_z);
  ///   print_is_numeric(42.84f);
  ///   print_is_numeric(42.84);
  ///   print_is_numeric(42.84l);
  ///   print_is_numeric('a');
  ///   print_is_numeric(true);
  ///   print_is_numeric("string"_s);
  ///   print_is_numeric("string");
  ///   print_is_numeric(1_h + 12_min + 24_s + 48_ms);
  ///   print_is_numeric(day_of_week::wednesday);
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (signed char) is numeric
  /// // 42 (short) is numeric
  /// // 42 (int) is numeric
  /// // 42 (long long) is numeric
  /// // 42 (unsigned char) is numeric
  /// // 42 (unsigned short) is numeric
  /// // 42 (unsigned int) is numeric
  /// // 42 (unsigned long long) is numeric
  /// // 42 (unsigned long) is numeric
  /// // 42.84 (float) is numeric
  /// // 42.84 (double) is numeric
  /// // 42.84 (long double) is numeric
  /// // true (bool) is not numeric
  /// // string (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) is not numeric
  /// // string (char const*) is not numeric
  /// // 01:12:24.0480000 (xtd::time_span) is not numeric
  /// // wednesday (xtd::day_of_week) is not numeric
  /// ```
  template<typename value_t>
  concept numeric =
  std::same_as<value_t, xtd::byte> ||
  std::same_as<value_t, xtd::decimal> ||
  std::same_as<value_t, xtd::double_> ||
  std::same_as<value_t, xtd::int16> ||
  std::same_as<value_t, xtd::int32> ||
  std::same_as<value_t, xtd::int64> ||
  std::same_as<value_t, xtd::slong> ||
  std::same_as<value_t, xtd::sbyte> ||
  std::same_as<value_t, xtd::single> ||
  std::same_as<value_t, xtd::uint16> ||
  std::same_as<value_t, xtd::uint32> ||
  std::same_as<value_t, xtd::uint64> ||
  std::same_as<value_t, xtd::ulong>;
}

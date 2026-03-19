/// @file
/// @brief Contains xtd::integer concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "types"
#include <type_traits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @concept xtd::integer
  /// @brief Concept integer.
  /// @par Definition
  /// ```cpp
  /// template<typename value_t>
  /// concept integer;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/integer>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::integer conceps
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_integer(auto value) noexcept {
  ///   println("{} ({}) {} integer", value, type_of(value), integer<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_integer(42_s8);
  ///   print_is_integer(42_s16);
  ///   print_is_integer(42_s32);
  ///   print_is_integer(42_s64);
  ///   print_is_integer(42_u8);
  ///   print_is_integer(42_u16);
  ///   print_is_integer(42_u32);
  ///   print_is_integer(42_u64);
  ///   print_is_integer(42_z);
  ///   print_is_integer(42.84f);
  ///   print_is_integer(42.84);
  ///   print_is_integer(42.84l);
  ///   print_is_integer('a');
  ///   print_is_integer(true);
  ///   print_is_integer("string"_s);
  ///   print_is_integer("string");
  ///   print_is_integer(1_h + 12_min + 24_s + 48_ms);
  ///   print_is_integer(day_of_week::wednesday);
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (signed char) is integer
  /// // 42 (short) is integer
  /// // 42 (int) is integer
  /// // 42 (long long) is integer
  /// // 42 (unsigned char) is integer
  /// // 42 (unsigned short) is integer
  /// // 42 (unsigned int) is integer
  /// // 42 (unsigned long long) is integer
  /// // 42 (unsigned long) is integer
  /// // 42.84 (float) is not integer
  /// // 42.84 (double) is not integer
  /// // 42.84 (long double) is not integer
  /// // true (bool) is not integer
  /// // string (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) is not integer
  /// // string (char const*) is not integer
  /// // 01:12:24.0480000 (xtd::time_span) is not integer
  /// // wednesday (xtd::day_of_week) is not integer
  /// ```
  template<typename value_t>
  concept integer =
  std::same_as<value_t, xtd::byte> ||
  std::same_as<value_t, xtd::int16> ||
  std::same_as<value_t, xtd::int32> ||
  std::same_as<value_t, xtd::int64> ||
  std::same_as<value_t, xtd::slong> ||
  std::same_as<value_t, xtd::sbyte> ||
  std::same_as<value_t, xtd::uint16> ||
  std::same_as<value_t, xtd::uint32> ||
  std::same_as<value_t, xtd::uint64> ||
  std::same_as<value_t, xtd::ulong>;
}

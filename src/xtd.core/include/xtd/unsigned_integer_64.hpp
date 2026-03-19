/// @file
/// @brief Contains xtd::unsigned_integer_64 concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "uint64.hpp"
#include "ulong.hpp"
#include <type_traits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @concept xtd::unsigned_integer_64
  /// @brief Concept unsigned_integer_64.
  /// @par Definition
  /// ```cpp
  /// template<typename value_t>
  /// concept xtd::unsigned_integer_64 = std::same_as<value_t, xtd::uint64> || std::same_as<value_t, xtd::ulong>
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/unsigned_integer_64>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::unsigned_integer_64 conceps
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_unsigned_integer_64(auto value) noexcept {
  ///   println("{} ({}) {} unsigned_integer_64", value, type_of(value), unsigned_integer_64<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_unsigned_integer_64(42_s8);
  ///   print_is_unsigned_integer_64(42_s16);
  ///   print_is_unsigned_integer_64(42_s32);
  ///   print_is_unsigned_integer_64(42_s64);
  ///   print_is_unsigned_integer_64(42_u8);
  ///   print_is_unsigned_integer_64(42_u16);
  ///   print_is_unsigned_integer_64(42_u32);
  ///   print_is_unsigned_integer_64(42_u64);
  ///   print_is_unsigned_integer_64(42_z);
  ///   print_is_unsigned_integer_64(42.84f);
  ///   print_is_unsigned_integer_64(42.84);
  ///   print_is_unsigned_integer_64(42.84l);
  ///   print_is_unsigned_integer_64('a');
  ///   print_is_unsigned_integer_64(true);
  ///   print_is_unsigned_integer_64("string"_s);
  ///   print_is_unsigned_integer_64("string");
  ///   print_is_unsigned_integer_64(1_h + 12_min + 24_s + 48_ms);
  ///   print_is_unsigned_integer_64(day_of_week::wednesday);
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (signed char) is not unsigned_integer_64
  /// // 42 (short) is not unsigned_integer_64
  /// // 42 (int) is not unsigned_integer_64
  /// // 42 (long long) is not unsigned_integer_64
  /// // 42 (unsigned char) is not unsigned_integer_64
  /// // 42 (unsigned short) is not unsigned_integer_64
  /// // 42 (unsigned int) is not unsigned_integer_64
  /// // 42 (unsigned long long) is unsigned_integer_64
  /// // 42 (unsigned long) is unsigned_integer_64
  /// // 42.84 (float) is not unsigned_integer_64
  /// // 42.84 (double) is not unsigned_integer_64
  /// // 42.84 (long double) is not unsigned_integer_64
  /// // true (bool) is not unsigned_integer_64
  /// // string (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) is not unsigned_integer_64
  /// // string (char const*) is not unsigned_integer_64
  /// // 01:12:24.0480000 (xtd::time_span) is not unsigned_integer_64
  /// // wednesday (xtd::day_of_week) is not unsigned_integer_64
  /// ```
  template<typename value_t>
  concept unsigned_integer_64 =
  std::same_as<value_t, xtd::uint64> ||
  std::same_as<value_t, xtd::ulong>;
}

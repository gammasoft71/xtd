/// @file
/// @brief Contains xtd::integer_32 concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/integer_32> or <xtd/integer_32.hpp> instead."

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the integer 32 bits concept.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::integer_32 = xtd::signed_integer_32<type_t> || xtd::unsigned_integer_32<type_t>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/integer_32>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::integer_32 concept
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_integer_32(auto value) noexcept {
  ///   println("{} ({}) {} integer_32", value, type_of(value), integer_32<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_integer_32(42_s8);
  ///   print_is_integer_32(42_s16);
  ///   print_is_integer_32(42_s32);
  ///   print_is_integer_32(42_s64);
  ///   print_is_integer_32(42_u8);
  ///   print_is_integer_32(42_u16);
  ///   print_is_integer_32(42_u32);
  ///   print_is_integer_32(42_u64);
  ///   print_is_integer_32(42_z);
  ///   print_is_integer_32(42.84f);
  ///   print_is_integer_32(42.84);
  ///   print_is_integer_32(42.84l);
  ///   print_is_integer_32('a');
  ///   print_is_integer_32(true);
  ///   print_is_integer_32("string"_s);
  ///   print_is_integer_32("string");
  ///   print_is_integer_32(1_h + 12_min + 24_s + 48_ms);
  ///   print_is_integer_32(day_of_week::wednesday);
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (signed char) is not integer_32
  /// // 42 (short) is not integer_32
  /// // 42 (int) is integer_32
  /// // 42 (long long) is not integer_32
  /// // 42 (unsigned char) is not integer_32
  /// // 42 (unsigned short) is not integer_32
  /// // 42 (unsigned int) is integer_32
  /// // 42 (unsigned long long) is not integer_32
  /// // 42 (unsigned long) is not integer_32
  /// // 42.84 (float) is not integer_32
  /// // 42.84 (double) is not integer_32
  /// // 42.84 (long double) is not integer_32
  /// // true (bool) is not integer_32
  /// // string (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) is not integer_32
  /// // string (char const*) is not integer_32
  /// // 01:12:24.0480000 (xtd::time_span) is not integer_32
  /// // wednesday (xtd::day_of_week) is not integer_32
  /// ```
  template<typename type_t>
  struct integer_32;
}

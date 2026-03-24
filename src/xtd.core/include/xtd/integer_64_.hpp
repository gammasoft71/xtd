/// @file
/// @brief Contains xtd::integer_64 concept docuemntation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/integer_64> or <xtd/integer_64.hpp> instead."

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the integer 64 bits concept.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::integer_64 = xtd::signed_integer_64<type_t> || xtd::unsigned_integer_64<type_t>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/integer_64>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::integer_64 concept
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_integer_64(auto value) noexcept {
  ///   println("{} ({}) {} integer_64", value, type_of(value), integer_64<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_integer_64(42_s8);
  ///   print_is_integer_64(42_s16);
  ///   print_is_integer_64(42_s32);
  ///   print_is_integer_64(42_s64);
  ///   print_is_integer_64(42_u8);
  ///   print_is_integer_64(42_u16);
  ///   print_is_integer_64(42_u32);
  ///   print_is_integer_64(42_u64);
  ///   print_is_integer_64(42_z);
  ///   print_is_integer_64(42.84f);
  ///   print_is_integer_64(42.84);
  ///   print_is_integer_64(42.84l);
  ///   print_is_integer_64('a');
  ///   print_is_integer_64(true);
  ///   print_is_integer_64("string"_s);
  ///   print_is_integer_64("string");
  ///   print_is_integer_64(1_h + 12_min + 24_s + 48_ms);
  ///   print_is_integer_64(day_of_week::wednesday);
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (signed char) is not integer_64
  /// // 42 (short) is not integer_64
  /// // 42 (int) is not integer_64
  /// // 42 (long long) is integer_64
  /// // 42 (unsigned char) is not integer_64
  /// // 42 (unsigned short) is not integer_64
  /// // 42 (unsigned int) is not integer_64
  /// // 42 (unsigned long long) is integer_64
  /// // 42 (unsigned long) is integer_64
  /// // 42.84 (float) is not integer_64
  /// // 42.84 (double) is not integer_64
  /// // 42.84 (long double) is not integer_64
  /// // true (bool) is not integer_64
  /// // string (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) is not integer_64
  /// // string (char const*) is not integer_64
  /// // 01:12:24.0480000 (xtd::time_span) is not integer_64
  /// // wednesday (xtd::day_of_week) is not integer_64
  /// ```
  template<typename type_t>
  struct integer_64;
}

/// @file
/// @brief Contains xtd::signed_integer_16 concept documention.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/signed_integer_16> or <xtd/signed_integer_16.hpp> instead."

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the signed integer 16 bits concept.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::signed_integer_16 = std::same_as<xtd::raw_type<type_t>, xtd::int16>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/signed_integer_16>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::signed_integer_16 concept
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_signed_integer_16(auto value) noexcept {
  ///   println("{} ({}) {} signed_integer_16", value, type_of(value), signed_integer_16<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_signed_integer_16(42_s8);
  ///   print_is_signed_integer_16(42_s16);
  ///   print_is_signed_integer_16(42_s32);
  ///   print_is_signed_integer_16(42_s64);
  ///   print_is_signed_integer_16(42_u8);
  ///   print_is_signed_integer_16(42_u16);
  ///   print_is_signed_integer_16(42_u32);
  ///   print_is_signed_integer_16(42_u64);
  ///   print_is_signed_integer_16(42_z);
  ///   print_is_signed_integer_16(42.84f);
  ///   print_is_signed_integer_16(42.84);
  ///   print_is_signed_integer_16(42.84l);
  ///   print_is_signed_integer_16('a');
  ///   print_is_signed_integer_16(true);
  ///   print_is_signed_integer_16("string"_s);
  ///   print_is_signed_integer_16("string");
  ///   print_is_signed_integer_16(1_h + 12_min + 24_s + 48_ms);
  ///   print_is_signed_integer_16(day_of_week::wednesday);
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (signed char) is not signed_integer_16
  /// // 42 (short) is signed_integer_16
  /// // 42 (int) is not signed_integer_16
  /// // 42 (long long) is not signed_integer_16
  /// // 42 (unsigned char) is not signed_integer_16
  /// // 42 (unsigned short) is not signed_integer_16
  /// // 42 (unsigned int) is not signed_integer_16
  /// // 42 (unsigned long long) is not signed_integer_16
  /// // 42 (unsigned long) is not signed_integer_16
  /// // 42.84 (float) is not signed_integer_16
  /// // 42.84 (double) is not signed_integer_16
  /// // 42.84 (long double) is not signed_integer_16
  /// // true (bool) is not signed_integer_16
  /// // string (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) is not signed_integer_16
  /// // string (char const*) is not signed_integer_16
  /// // 01:12:24.0480000 (xtd::time_span) is not signed_integer_16
  /// // wednesday (xtd::day_of_week) is not signed_integer_16
  /// ```
  template<typename type_t>
  struct signed_integer_16;
}

/// @file
/// @brief Contains xtd::signed_integer concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/signed_integer> or <xtd/signed_integer.hpp> instead."

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the signed integer concept.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::signed_integer = xtd::signed_integer_8<type_t> || xtd::signed_integer_16<type_t> || xtd::signed_integer_32<type_t> || xtd::signed_integer_64<type_t>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/signed_integer>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::signed_integer concept
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_signed_integer(auto value) noexcept {
  ///   println("{} ({}) {} signed_integer", value, type_of(value), signed_integer<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_signed_integer(42_s8);
  ///   print_is_signed_integer(42_s16);
  ///   print_is_signed_integer(42_s32);
  ///   print_is_signed_integer(42_s64);
  ///   print_is_signed_integer(42_u8);
  ///   print_is_signed_integer(42_u16);
  ///   print_is_signed_integer(42_u32);
  ///   print_is_signed_integer(42_u64);
  ///   print_is_signed_integer(42_z);
  ///   print_is_signed_integer(42.84f);
  ///   print_is_signed_integer(42.84);
  ///   print_is_signed_integer(42.84l);
  ///   print_is_signed_integer('a');
  ///   print_is_signed_integer(true);
  ///   print_is_signed_integer("string"_s);
  ///   print_is_signed_integer("string");
  ///   print_is_signed_integer(1_h + 12_min + 24_s + 48_ms);
  ///   print_is_signed_integer(day_of_week::wednesday);
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (signed char) is signed_integer
  /// // 42 (short) is signed_integer
  /// // 42 (int) is signed_integer
  /// // 42 (long long) is signed_integer
  /// // 42 (unsigned char) is not signed_integer
  /// // 42 (unsigned short) is not signed_integer
  /// // 42 (unsigned int) is not signed_integer
  /// // 42 (unsigned long long) is not signed_integer
  /// // 42 (unsigned long) is not signed_integer
  /// // 42.84 (float) is not signed_integer
  /// // 42.84 (double) is not signed_integer
  /// // 42.84 (long double) is not signed_integer
  /// // true (bool) is not signed_integer
  /// // string (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) is not signed_integer
  /// // string (char const*) is not signed_integer
  /// // 01:12:24.0480000 (xtd::time_span) is not signed_integer
  /// // wednesday (xtd::day_of_week) is not signed_integer
  /// ```
  template<typename type_t>
  struct signed_integer;
}

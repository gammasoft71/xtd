/// @file
/// @brief Contains xtd::enumeration concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/enumeration> or <xtd/enumeration.hpp> instead."

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent the enumeration concept.
  /// @par Definition
  /// ```cpp
  /// template<class type_t>
  /// concept xtd::enumeration = std::is_enum_v<xtd::raw_type<type_t>>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/enumeration>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::enumeration concept
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_enumeration(auto value) noexcept {
  ///   println("{} ({}) {} enumeration", value, type_of(value), enumeration<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_enumeration(42_s8);
  ///   print_is_enumeration(42_s16);
  ///   print_is_enumeration(42_s32);
  ///   print_is_enumeration(42_s64);
  ///   print_is_enumeration(42_u8);
  ///   print_is_enumeration(42_u16);
  ///   print_is_enumeration(42_u32);
  ///   print_is_enumeration(42_u64);
  ///   print_is_enumeration(42_z);
  ///   print_is_enumeration(42.84f);
  ///   print_is_enumeration(42.84);
  ///   print_is_enumeration(42.84l);
  ///   print_is_enumeration('a');
  ///   print_is_enumeration(true);
  ///   print_is_enumeration("string"_s);
  ///   print_is_enumeration("string");
  ///   print_is_enumeration(1_h + 12_min + 24_s + 48_ms);
  ///   print_is_enumeration(day_of_week::wednesday);
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (signed char) is not enumeration
  /// // 42 (short) is not enumeration
  /// // 42 (int) is not enumeration
  /// // 42 (long long) is not enumeration
  /// // 42 (unsigned char) is not enumeration
  /// // 42 (unsigned short) is not enumeration
  /// // 42 (unsigned int) is not enumeration
  /// // 42 (unsigned long long) is not enumeration
  /// // 42 (unsigned long) is not enumeration
  /// // 42.84 (float) is not enumeration
  /// // 42.84 (double) is not enumeration
  /// // 42.84 (long double) is not enumeration
  /// // true (bool) is not enumeration
  /// // string (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) is not enumeration
  /// // string (char const*) is not enumeration
  /// // 01:12:24.0480000 (xtd::time_span) is not enumeration
  /// // wednesday (xtd::day_of_week) is enumeration
  /// ```
  template<class type_t>
  struct enumeration;
}

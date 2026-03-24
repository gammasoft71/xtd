/// @file
/// @brief Contains xtd::logical concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/logical> or <xtd/logical.hpp> instead."

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent a logical concept.
  /// @par Definition
  /// ```cpp
  /// template<class type_t>
  /// concept xtd::logical = std::same_as<xtd::raw_type<type_t>, xtd::boolean>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/logical>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::logical concept
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_logical(auto value) noexcept {
  ///   println("{} ({}) {} logical", value, type_of(value), logical<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_logical(42_s8);
  ///   print_is_logical(42_s16);
  ///   print_is_logical(42_s32);
  ///   print_is_logical(42_s64);
  ///   print_is_logical(42_u8);
  ///   print_is_logical(42_u16);
  ///   print_is_logical(42_u32);
  ///   print_is_logical(42_u64);
  ///   print_is_logical(42_z);
  ///   print_is_logical(42.84f);
  ///   print_is_logical(42.84);
  ///   print_is_logical(42.84l);
  ///   print_is_logical('a');
  ///   print_is_logical(true);
  ///   print_is_logical("string"_s);
  ///   print_is_logical("string");
  ///   print_is_logical(1_h + 12_min + 24_s + 48_ms);
  ///   print_is_logical(day_of_week::wednesday);
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (signed char) is not logical
  /// // 42 (short) is not logical
  /// // 42 (int) is not logical
  /// // 42 (long long) is not logical
  /// // 42 (unsigned char) is not logical
  /// // 42 (unsigned short) is not logical
  /// // 42 (unsigned int) is not logical
  /// // 42 (unsigned long long) is not logical
  /// // 42 (unsigned long) is not logical
  /// // 42.84 (float) is not logical
  /// // 42.84 (double) is not logical
  /// // 42.84 (long double) is not logical
  /// // a (char) is not logical
  /// // true (bool) is logical
  /// // string (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) is not logical
  /// // string (char const*) is not logical
  /// // 01:12:24.0480000 (xtd::time_span) is not logical
  /// // wednesday (xtd::day_of_week) is not logical
  /// ```
  template<class type_t>
  struct logical;
}

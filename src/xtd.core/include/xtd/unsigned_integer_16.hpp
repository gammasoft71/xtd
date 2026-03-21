/// @file
/// @brief Contains xtd::unsigned_integer_16 concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "raw_type.hpp"
#include "uint16.hpp"
#include <concepts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Concept unsigned_integer_16.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::unsigned_integer_16 = std::same_as<xtd::raw_type<type_t>, xtd::uint16>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/unsigned_integer_16>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::unsigned_integer_16 conceps
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_unsigned_integer_16(auto value) noexcept {
  ///   println("{} ({}) {} unsigned_integer_16", value, type_of(value), unsigned_integer_16<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_unsigned_integer_16(42_s8);
  ///   print_is_unsigned_integer_16(42_s16);
  ///   print_is_unsigned_integer_16(42_s32);
  ///   print_is_unsigned_integer_16(42_s64);
  ///   print_is_unsigned_integer_16(42_u8);
  ///   print_is_unsigned_integer_16(42_u16);
  ///   print_is_unsigned_integer_16(42_u32);
  ///   print_is_unsigned_integer_16(42_u64);
  ///   print_is_unsigned_integer_16(42_z);
  ///   print_is_unsigned_integer_16(42.84f);
  ///   print_is_unsigned_integer_16(42.84);
  ///   print_is_unsigned_integer_16(42.84l);
  ///   print_is_unsigned_integer_16('a');
  ///   print_is_unsigned_integer_16(true);
  ///   print_is_unsigned_integer_16("string"_s);
  ///   print_is_unsigned_integer_16("string");
  ///   print_is_unsigned_integer_16(1_h + 12_min + 24_s + 48_ms);
  ///   print_is_unsigned_integer_16(day_of_week::wednesday);
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (signed char) is not unsigned_integer_16
  /// // 42 (short) is not unsigned_integer_16
  /// // 42 (int) is not unsigned_integer_16
  /// // 42 (long long) is not unsigned_integer_16
  /// // 42 (unsigned char) is not unsigned_integer_16
  /// // 42 (unsigned short) is unsigned_integer_16
  /// // 42 (unsigned int) is not unsigned_integer_16
  /// // 42 (unsigned long long) is not unsigned_integer_16
  /// // 42 (unsigned long) is not unsigned_integer_16
  /// // 42.84 (float) is not unsigned_integer_16
  /// // 42.84 (double) is not unsigned_integer_16
  /// // 42.84 (long double) is not unsigned_integer_16
  /// // true (bool) is not unsigned_integer_16
  /// // string (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) is not unsigned_integer_16
  /// // string (char const*) is not unsigned_integer_16
  /// // 01:12:24.0480000 (xtd::time_span) is not unsigned_integer_16
  /// // wednesday (xtd::day_of_week) is not unsigned_integer_16
  /// ```
  template<typename type_t>
  concept unsigned_integer_16 =
  std::same_as<xtd::raw_type<type_t>, xtd::uint16>;
}

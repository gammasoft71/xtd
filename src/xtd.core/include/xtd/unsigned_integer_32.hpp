/// @file
/// @brief Contains xtd::unsigned_integer_32 concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "raw_type.hpp"
#include "uint32.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Concept unsigned_integer_32.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::unsigned_integer_32 = std::same_as<xtd::raw_type<type_t>, xtd::uint32>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/unsigned_integer_32>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::unsigned_integer_32 conceps
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_unsigned_integer_32(auto value) noexcept {
  ///   println("{} ({}) {} unsigned_integer_32", value, type_of(value), unsigned_integer_32<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_unsigned_integer_32(42_s8);
  ///   print_is_unsigned_integer_32(42_s16);
  ///   print_is_unsigned_integer_32(42_s32);
  ///   print_is_unsigned_integer_32(42_s64);
  ///   print_is_unsigned_integer_32(42_u8);
  ///   print_is_unsigned_integer_32(42_u16);
  ///   print_is_unsigned_integer_32(42_u32);
  ///   print_is_unsigned_integer_32(42_u64);
  ///   print_is_unsigned_integer_32(42_z);
  ///   print_is_unsigned_integer_32(42.84f);
  ///   print_is_unsigned_integer_32(42.84);
  ///   print_is_unsigned_integer_32(42.84l);
  ///   print_is_unsigned_integer_32('a');
  ///   print_is_unsigned_integer_32(true);
  ///   print_is_unsigned_integer_32("string"_s);
  ///   print_is_unsigned_integer_32("string");
  ///   print_is_unsigned_integer_32(1_h + 12_min + 24_s + 48_ms);
  ///   print_is_unsigned_integer_32(day_of_week::wednesday);
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (signed char) is not unsigned_integer_32
  /// // 42 (short) is not unsigned_integer_32
  /// // 42 (int) is not unsigned_integer_32
  /// // 42 (long long) is not unsigned_integer_32
  /// // 42 (unsigned char) is not unsigned_integer_32
  /// // 42 (unsigned short) is not unsigned_integer_32
  /// // 42 (unsigned int) is unsigned_integer_32
  /// // 42 (unsigned long long) is not unsigned_integer_32
  /// // 42 (unsigned long) is not unsigned_integer_32
  /// // 42.84 (float) is not unsigned_integer_32
  /// // 42.84 (double) is not unsigned_integer_32
  /// // 42.84 (long double) is not unsigned_integer_32
  /// // true (bool) is not unsigned_integer_32
  /// // string (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) is not unsigned_integer_32
  /// // string (char const*) is not unsigned_integer_32
  /// // 01:12:24.0480000 (xtd::time_span) is not unsigned_integer_32
  /// // wednesday (xtd::day_of_week) is not unsigned_integer_32
  /// ```
  template<typename type_t>
  concept unsigned_integer_32 =
  std::same_as<xtd::raw_type<type_t>, xtd::uint32>;
}

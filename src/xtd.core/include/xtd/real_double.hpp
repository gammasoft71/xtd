/// @file
/// @brief Contains xtd::real_double concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "double.hpp"
#include "raw_type.hpp"
#include <concepts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Concept real_double.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::real_double = std::same_as<xtd::raw_type<type_t>, xtd::single>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/real_double>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::real_double conceps
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_real_double(auto value) noexcept {
  ///   println("{} ({}) {} real_double", value, type_of(value), real_double<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_real_double(42_s8);
  ///   print_is_real_double(42_s16);
  ///   print_is_real_double(42_s32);
  ///   print_is_real_double(42_s64);
  ///   print_is_real_double(42_u8);
  ///   print_is_real_double(42_u16);
  ///   print_is_real_double(42_u32);
  ///   print_is_real_double(42_u64);
  ///   print_is_real_double(42_z);
  ///   print_is_real_double(42.84f);
  ///   print_is_real_double(42.84);
  ///   print_is_real_double(42.84l);
  ///   print_is_real_double('a');
  ///   print_is_real_double(true);
  ///   print_is_real_double("string"_s);
  ///   print_is_real_double("string");
  ///   print_is_real_double(1_h + 12_min + 24_s + 48_ms);
  ///   print_is_real_double(day_of_week::wednesday);
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (signed char) is not real_double
  /// // 42 (short) is not real_double
  /// // 42 (int) is not real_double
  /// // 42 (long long) is not real_double
  /// // 42 (unsigned char) is not real_double
  /// // 42 (unsigned short) is not real_double
  /// // 42 (unsigned int) is not real_double
  /// // 42 (unsigned long long) is real_double
  /// // 42 (unsigned long) is real_double
  /// // 42.84 (float) is not real_double
  /// // 42.84 (double) is real_double
  /// // 42.84 (long double) is not real_double
  /// // true (bool) is not real_double
  /// // string (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) is not real_double
  /// // string (char const*) is not real_double
  /// // 01:12:24.0480000 (xtd::time_span) is not real_double
  /// // wednesday (xtd::day_of_week) is not real_double
  /// ```
  template<typename type_t>
  concept real_double =
  std::same_as<xtd::raw_type<type_t>, xtd::double_>;
}

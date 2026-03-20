/// @file
/// @brief Contains xtd::real concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "real_decimal.hpp"
#include "real_double.hpp"
#include "real_single.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Concept real.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::real = xtd::real_single<type_t> || xtd::real_double<type_t> || xtd::real_decimal<type_t>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/real>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::real conceps
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_real(auto value) noexcept {
  ///   println("{} ({}) {} real", value, type_of(value), real<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_real(42_s8);
  ///   print_is_real(42_s16);
  ///   print_is_real(42_s32);
  ///   print_is_real(42_s64);
  ///   print_is_real(42_u8);
  ///   print_is_real(42_u16);
  ///   print_is_real(42_u32);
  ///   print_is_real(42_u64);
  ///   print_is_real(42_z);
  ///   print_is_real(42.84f);
  ///   print_is_real(42.84);
  ///   print_is_real(42.84l);
  ///   print_is_real('a');
  ///   print_is_real(true);
  ///   print_is_real("string"_s);
  ///   print_is_real("string");
  ///   print_is_real(1_h + 12_min + 24_s + 48_ms);
  ///   print_is_real(day_of_week::wednesday);
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (signed char) is not real
  /// // 42 (short) is not real
  /// // 42 (int) is not real
  /// // 42 (long long) is not real
  /// // 42 (unsigned char) is not real
  /// // 42 (unsigned short) is not real
  /// // 42 (unsigned int) is not real
  /// // 42 (unsigned long long) is not real
  /// // 42 (unsigned long) is not real
  /// // 42.84 (float) is real
  /// // 42.84 (double) is real
  /// // 42.84 (long double) is real
  /// // true (bool) is not real
  /// // string (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) is not real
  /// // string (char const*) is not real
  /// // 01:12:24.0480000 (xtd::time_span) is not real
  /// // wednesday (xtd::day_of_week) is not real
  /// ```
  template<typename type_t>
  concept real =
  xtd::real_single<type_t> ||
  xtd::real_double<type_t> ||
  xtd::real_decimal<type_t>;
}

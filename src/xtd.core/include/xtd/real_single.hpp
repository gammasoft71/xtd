/// @file
/// @brief Contains xtd::real_single concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "single.hpp"
#include "raw_type.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Concept real_single.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::real_single = std::same_as<xtd::raw_type<type_t>, xtd::single>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/real_single>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::real_single conceps
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_real_single(auto value) noexcept {
  ///   println("{} ({}) {} real_single", value, type_of(value), real_single<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_real_single(42_s8);
  ///   print_is_real_single(42_s16);
  ///   print_is_real_single(42_s32);
  ///   print_is_real_single(42_s64);
  ///   print_is_real_single(42_u8);
  ///   print_is_real_single(42_u16);
  ///   print_is_real_single(42_u32);
  ///   print_is_real_single(42_u64);
  ///   print_is_real_single(42_z);
  ///   print_is_real_single(42.84f);
  ///   print_is_real_single(42.84);
  ///   print_is_real_single(42.84l);
  ///   print_is_real_single('a');
  ///   print_is_real_single(true);
  ///   print_is_real_single("string"_s);
  ///   print_is_real_single("string");
  ///   print_is_real_single(1_h + 12_min + 24_s + 48_ms);
  ///   print_is_real_single(day_of_week::wednesday);
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (signed char) is not real_single
  /// // 42 (short) is not real_single
  /// // 42 (int) is not real_single
  /// // 42 (long long) is not real_single
  /// // 42 (unsigned char) is not real_single
  /// // 42 (unsigned short) is not real_single
  /// // 42 (unsigned int) is not real_single
  /// // 42 (unsigned long long) is real_single
  /// // 42 (unsigned long) is real_single
  /// // 42.84 (float) is real_single
  /// // 42.84 (double) is not real_single
  /// // 42.84 (long double) is not real_single
  /// // true (bool) is not real_single
  /// // string (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) is not real_single
  /// // string (char const*) is not real_single
  /// // 01:12:24.0480000 (xtd::time_span) is not real_single
  /// // wednesday (xtd::day_of_week) is not real_single
  /// ```
  template<typename type_t>
  concept real_single =
  std::same_as<xtd::raw_type<type_t>, xtd::single>;
}

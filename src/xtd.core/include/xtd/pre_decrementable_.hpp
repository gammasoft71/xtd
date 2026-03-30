/// @file
/// @brief Contains xtd::pre_decrementable concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/pre_decrementable> or <xtd/pre_decrementable.hpp> instead."

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the pre decrementable concept.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::pre_decrementable = requires(xtd::raw_type<type_t>& a) {{--a} -> std::same_as<xtd::raw_type<type_t>>;}
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/pre_decrementable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::pre_decrementable concept
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_pre_decrementable(auto value) noexcept {
  ///   println("{} ({}) {} pre_decrementable", value, type_of(value), pre_decrementable<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_pre_decrementable(42);
  ///   print_is_pre_decrementable(time_span {1, 2, 3});
  ///   print_is_pre_decrementable(version {1, 2, 3});
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (int) is pre_decrementable
  /// // 01:02:03 (xtd::time_span) is pre_decrementable
  /// // 1.2.3 (xtd::version) is not pre_decrementable
  /// ```
  template<typename type_t>
  struct pre_decrementable;
}

/// @file
/// @brief Contains xtd::decrementable concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/decrementable> or <xtd/decrementable.hpp> instead."


/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the decrementable concept.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::decrementable = xxtd::post_decrementable<type_t> && xtd::pre_decrementable<type_t>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/decrementable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::decrementable concept
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_decrementable(auto value) noexcept {
  ///   println("{} ({}) {} decrementable", value, type_of(value), decrementable<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_decrementable(42);
  ///   print_is_decrementable(time_span {1, 2, 3});
  ///   print_is_decrementable(version {1, 2, 3});
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (int) is decrementable
  /// // 01:02:03 (xtd::time_span) is decrementable
  /// // 1.2.3 (xtd::version) is not decrementable
  /// ```
  template<typename type_t>
  struct decrementable;
}

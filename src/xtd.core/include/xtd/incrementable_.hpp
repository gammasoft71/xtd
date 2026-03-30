/// @file
/// @brief Contains xtd::incrementable concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/incrementable> or <xtd/incrementable.hpp> instead."


/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the incrementable concept.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::incrementable = xxtd::post_incrementable<type_t> && xtd::pre_incrementable<type_t>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/incrementable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::incrementable concept
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_incrementable(auto value) noexcept {
  ///   println("{} ({}) {} incrementable", value, type_of(value), incrementable<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_incrementable(42);
  ///   print_is_incrementable(time_span {1, 2, 3});
  ///   print_is_incrementable(version {1, 2, 3});
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (int) is incrementable
  /// // 01:02:03 (xtd::time_span) is incrementable
  /// // 1.2.3 (xtd::version) is not incrementable
  /// ```
  template<typename type_t>
  struct incrementable;
}

/// @file
/// @brief Contains xtd::pre_incrementable concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/pre_incrementable> or <xtd/pre_incrementable.hpp> instead."

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the post decrementable concept.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::pre_incrementable = requires(xtd::raw_type<type_t>& a) {{++a} -> std::same_as<xtd::raw_type<type_t>>;}
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/pre_incrementable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::pre_incrementable concept
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_pre_incrementable(auto value) noexcept {
  ///   println("{} ({}) {} pre_incrementable", value, type_of(value), pre_incrementable<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_pre_incrementable(42);
  ///   print_is_pre_incrementable(time_span {1, 2, 3});
  ///   print_is_pre_incrementable(version {1, 2, 3});
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (int) is pre_incrementable
  /// // 01:02:03 (xtd::time_span) is pre_incrementable
  /// // 1.2.3 (xtd::version) is not pre_incrementable
  /// ```
  template<typename type_t>
  struct pre_incrementable;
}

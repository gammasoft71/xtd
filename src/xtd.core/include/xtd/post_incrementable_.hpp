/// @file
/// @brief Contains xtd::post_incrementable concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/post_incrementable> or <xtd/post_incrementable.hpp> instead."

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the post decrementable concept.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::post_incrementable = requires(xtd::raw_type<type_t>& a) {{a++} -> std::same_as<xtd::raw_type<type_t>>;}
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/post_incrementable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::post_incrementable concept
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_post_incrementable(auto value) noexcept {
  ///   println("{} ({}) {} post_incrementable", value, type_of(value), post_incrementable<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_post_incrementable(42);
  ///   print_is_post_incrementable(time_span {1, 2, 3});
  ///   print_is_post_incrementable(version {1, 2, 3});
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (int) is post_incrementable
  /// // 01:02:03 (xtd::time_span) is post_incrementable
  /// // 1.2.3 (xtd::version) is not post_incrementable
  /// ```
  template<typename type_t>
  struct post_incrementable;
}

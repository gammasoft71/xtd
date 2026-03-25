/// @file
/// @brief Contains xtd::post_decrementable concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/post_decrementable> or <xtd/post_decrementable.hpp> instead."

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the post decrementable concept.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::post_decrementable = requires(xtd::raw_type<type_t>& a) {{a--} -> std::same_as<xtd::raw_type<type_t>>;}
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/post_decrementable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::post_decrementable concept
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_post_decrementable(auto value) noexcept {
  ///   println("{} ({}) {} post_decrementable", value, type_of(value), post_decrementable<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_post_decrementable(42);
  ///   print_is_post_decrementable(time_span {1, 2, 3});
  ///   print_is_post_decrementable(version {1, 2, 3});
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (int) is post_decrementable
  /// // 01:02:03 (xtd::time_span) is post_decrementable
  /// // 1.2.3 (xtd::version) is not post_decrementable
  /// ```
  template<typename type_t>
  struct post_decrementable;
}

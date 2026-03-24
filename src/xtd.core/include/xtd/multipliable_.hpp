/// @file
/// @brief Contains xtd::multipliable concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/multipliable> or <xtd/multipliable.hpp> instead."

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the multipliable concept.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::multipliable = requires(const xtd::raw_type<type_t>& a, const xtd::raw_type<type_t>& b) {{a * b} -> std::same_as<xtd::raw_type<type_t>>;};
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/multipliable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::multipliable concept
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_multipliable(auto value) noexcept {
  ///   println("{} ({}) {} multipliable", value, type_of(value), multipliable<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_multipliable(42);
  ///   print_is_multipliable(time_span {1, 2, 3});
  ///   print_is_multipliable(version {1, 2, 3});
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (int) is multipliable
  /// // 01:02:03 (xtd::time_span) is not multipliable
  /// // 1.2.3 (xtd::version) is not multipliable
  /// ```
  template<typename type_t>
  struct multipliable;
}

/// @file
/// @brief Contains xtd::modable concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/modable> or <xtd/modable.hpp> instead."

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the modable concept.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::modable = requires(const xtd::raw_type<type_t>& a, const xtd::raw_type<type_t>& b) {{a % b} -> std::same_as<xtd::raw_type<type_t>>;};
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/modable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::modable concept
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_modable(auto value) noexcept {
  ///   println("{} ({}) {} modable", value, type_of(value), modable<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_modable(42);
  ///   print_is_modable(time_span {1, 2, 3});
  ///   print_is_modable(version {1, 2, 3});
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (int) is modable
  /// // 01:02:03 (xtd::time_span) is not modable
  /// // 1.2.3 (xtd::version) is not modable
  /// ```
  template<typename type_t>
  struct modable;
}

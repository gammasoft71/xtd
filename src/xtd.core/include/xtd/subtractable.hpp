/// @file
/// @brief Contains xtd::subtractable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "raw_type.hpp"
#include <concepts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Concept subtractable.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::subtractable = requires(const xtd::raw_type<type_t>& a, const xtd::raw_type<type_t>& b) {{a - b} -> std::same_as<xtd::raw_type<type_t>>;};
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/subtractable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::subtractable concept
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_subtractable(auto value) noexcept {
  ///   println("{} ({}) {} subtractable", value, type_of(value), subtractable<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_subtractable(42);
  ///   print_is_subtractable(time_span {1, 2, 3});
  ///   print_is_subtractable(version {1, 2, 3});
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (int) is subtractable
  /// // 01:02:03 (xtd::time_span) is subtractable
  /// // 1.2.3 (xtd::version) is not subtractable
  /// ```
  template<typename type_t>
  concept subtractable = requires(const xtd::raw_type<type_t>& a, const xtd::raw_type<type_t>& b) {
    {a - b} -> std::same_as<xtd::raw_type<type_t>>;
  };
}

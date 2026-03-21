/// @file
/// @brief Contains xtd::addable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "raw_type.hpp"
#include <concepts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Concept addable.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::addable = requires(const xtd::raw_type<type_t>& a, const xtd::raw_type<type_t>& b) {{a + b} -> std::same_as<xtd::raw_type<type_t>>;};
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/addable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::addable concept
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_addable(auto value) noexcept {
  ///   println("{} ({}) {} addable", value, type_of(value), addable<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_addable(42);
  ///   print_is_addable(time_span {1, 2, 3});
  ///   print_is_addable(version {1, 2, 3});
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (int) is addable
  /// // 01:02:03 (xtd::time_span) is addable
  /// // 1.2.3 (xtd::version) is not addable
  /// ```
  template<typename type_t>
  concept addable = requires(const xtd::raw_type<type_t>& a, const xtd::raw_type<type_t>& b) {
    {a + b} -> std::same_as<xtd::raw_type<type_t>>;
  };
}

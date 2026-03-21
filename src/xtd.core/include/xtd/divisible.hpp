/// @file
/// @brief Contains xtd::divisible concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "raw_type.hpp"
#include <concepts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Concept divisible.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::divisible = requires(const xtd::raw_type<type_t>& a, const xtd::raw_type<type_t>& b) {{a / b} -> std::same_as<xtd::raw_type<type_t>>;};
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/divisible>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::divisible concept
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_divisible(auto value) noexcept {
  ///   println("{} ({}) {} divisible", value, type_of(value), divisible<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_divisible(42);
  ///   print_is_divisible(time_span {1, 2, 3});
  ///   print_is_divisible(version {1, 2, 3});
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (int) is divisible
  /// // 01:02:03 (xtd::time_span) is divisible
  /// // 1.2.3 (xtd::version) is not divisible
  /// ```
  template<typename type_t>
  concept divisible = requires(const xtd::raw_type<type_t>& a, const xtd::raw_type<type_t>& b) {
    {a / b} -> std::same_as<xtd::raw_type<type_t>>;
  };
}

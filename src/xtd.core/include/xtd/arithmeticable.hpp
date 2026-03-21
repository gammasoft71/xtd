/// @file
/// @brief Contains xtd::arithmeticable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "addable.hpp"
#include "divisible.hpp"
#include "multipliable.hpp"
#include "subtractable.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Concept arithmeticable.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::arithmeticable = xtd::addable<type_t> && xtd::divisible<type_t> && xtd::multipliable<type_t> && xtd::subtractable<type_t>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/arithmeticable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::arithmeticable concept
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_arithmeticable(auto value) noexcept {
  ///   println("{} ({}) {} arithmeticable", value, type_of(value), arithmeticable<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_arithmeticable(42);
  ///   print_is_arithmeticable(time_span {1, 2, 3});
  ///   print_is_arithmeticable(version {1, 2, 3});
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (int) is arithmeticable
  /// // 01:02:03 (xtd::time_span) is not arithmeticable
  /// // 1.2.3 (xtd::version) is not arithmeticable
  /// ```
  template<typename type_t>
  concept arithmeticable =
  xtd::addable<type_t> &&
  xtd::divisible<type_t> &&
  xtd::multipliable<type_t> &&
  xtd::subtractable<type_t>;
}

/// @file
/// @brief Contains xtd::integer_arithmeticable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "arithmeticable.hpp"
#include "modable.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Concept integer_arithmeticable.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::integer_arithmeticable = xtd::arithmeticable<type_t> && xtd::modable<type_t>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/integer_arithmeticable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::integer_arithmeticable concept
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_integer_arithmeticable(auto value) noexcept {
  ///   println("{} ({}) {} integer_arithmeticable", value, type_of(value), integer_arithmeticable<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_integer_arithmeticable(42);
  ///   print_is_integer_arithmeticable(time_span {1, 2, 3});
  ///   print_is_integer_arithmeticable(version {1, 2, 3});
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (int) is integer_arithmeticable
  /// // 01:02:03 (xtd::time_span) is not integer_arithmeticable
  /// // 1.2.3 (xtd::version) is not integer_arithmeticable
  /// ```
  template<typename type_t>
  concept integer_arithmeticable =
  xtd::arithmeticable<type_t> &&
  xtd::modable<type_t>;
}

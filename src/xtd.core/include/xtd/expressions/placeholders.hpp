/// @file
/// @brief Contains xtd::expressions::placeholder struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "placeholder.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief Generates a set of positional placeholders that can be decomposed using structured bindings to build readable and composable expression templates.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/placeholders>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::expression::placeholders.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   //auto expr1 = [](auto&& operand_one, auto&& operand_two) {return operand_one + operand_two;};
    ///   auto [operand_one, operand_two] = placeholders<2>();
    ///   auto expr1 = operand_one + operand_two;
    ///   println("expr1 result => {}", expr1(10, 20));
    ///   auto expr2 = _1 + _2;
    ///   println("expr2 result => {}", expr2(10, 20));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // expr1 result => 30
    /// // expr2 result => 30
    /// ```
    template <size_t count>
    struct placeholders {
      template <size_t index>
      constexpr auto get() const noexcept {
        return placeholder<index + 1> {};
      }
    };
  }
}

/// @cond
namespace std {
  template <size_t count>
  struct tuple_size<xtd::expressions::placeholders<count>> : std::integral_constant<size_t, count> {};
  
  template <size_t index, size_t count>
  struct tuple_element<index, xtd::expressions::placeholders<count>> {
    using type = placeholder<index + 1>;
  };
}

namespace xtd::expressions {
  template <size_t index, size_t count>
  constexpr auto get(xtd::expressions::placeholders<count> const& p) noexcept {
    return p.template get<index>();
  }
}
/// @endcond

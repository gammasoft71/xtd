/// @file
/// @brief Contains xtd::expressions::placeholder struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "operator_precedence.hpp"
#include "placeholder_base.hpp"
#include <concepts>
#include <ostream>
#include <tuple>
#include <type_traits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::placeholder object is placeholder for all expressions.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/placeholder>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// ```cpp
    /// auto expr = placeholder<0> {} + placeholder<1> {} + placeholder<2> {} + placeholder<4> {} + placeholder<5> {};
    /// println("expr result => {}", expr(10, 20, 30, 40, 50)); // expr result => 150
    /// ```
    /// @remarks Prefer the xtd::expressions::arg <N> or xtd::expressions::_, xtd::expressions::_1 ... xtd::expressions::_10 instead que xtd::expressions::placeholder.
    template <size_t index>
    struct placeholder : placeholder_base {
      /// @name Public Fields
      
      /// @{
      /// @brief The operator precedence. That contains one of xtd::expressions::operator_precedence values.
      static constexpr operator_precedence precedence = operator_precedence::placeholder;
      /// @}

      /// @name Public Constructors
      
      /// @{
      placeholder() = default;
      /// @}

      /// @name Public Operators
      
      /// @{
      /// @brief Gets the placeholder value.
      /// @return The placeholder value.
      template <typename... args_t>
      constexpr decltype(auto) operator()(args_t&&... args) const {
        return std::get<index>(std::forward_as_tuple(std::forward<args_t>(args)...));
      }
      /// @}
    };

    /// @cond
    template <size_t index>
    inline auto operator <<(std::ostream& os, const placeholder<index>&) -> std::ostream& {return os << "_" << (index + 1);}
    /// @endcond
  }
}

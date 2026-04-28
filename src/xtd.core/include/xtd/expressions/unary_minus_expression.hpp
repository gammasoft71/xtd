/// @file
/// @brief Contains xtd::expressions::unary_minus_expression operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "expression_operand.hpp"
#include "expression_stream.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::unary_minus_expression is the unary minus expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::unary_minus_expression struct is used by xtd::expressions::operator -().
    template <typename value_t>
    struct unary_minus_expression : expression {
      /// @name Public Fields
      
      /// @{
      /// @brief The operator precedence. That contains one of xtd::expressions::operator_precedence values.
      static constexpr operator_precedence precedence = operator_precedence::unary_minus;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::unary_minus_expression object with specified value operand.
      /// @param value The value operand.
      constexpr unary_minus_expression(value_t value) : value {std::move(value)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Add the specified arguments.
      /// @param args the arguments to add.
      /// @return The result of unary minus.
      template <typename... args_t>
      constexpr auto operator()(args_t&&... args) const {return -value(std::forward<args_t>(args)...);}
      /// @}
      
      /// @cond
      friend inline auto operator <<(std::ostream& os, const unary_minus_expression& e) -> std::ostream& {return os << "-" << expression_stream {e.value, e.precedence};}
      /// @endcond

    private:
      [[no_unique_address]] value_t value;
    };

    /// @name Public Operators
    
    /// @{
    /// @brief Add the specified left and right operands.
    /// @param left The left operand.
    /// @param right The right operand.
    /// @return The result of unary minus.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::unary_minus_expression.
    /// @include unary_minus_expression.cpp
    template <typename value_t>
    requires expression_operand<value_t>
    constexpr auto operator -(value_t value) {
      auto expression = as_expression(value);
      return unary_minus_expression<std::decay_t<decltype(expression)>> {std::move(expression)};
    }
    /// @}
  }
}

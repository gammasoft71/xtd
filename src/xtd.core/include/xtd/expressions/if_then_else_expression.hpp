/// @file
/// @brief Contains xtd::expressions::if_then_else_expression operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "conditional_expression.hpp"
#include "expression_operand.hpp"
#include "expression_stream.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::if_then_else_expression is the addition expression.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/if_then_else_expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks The xtd::expressions::if_then_else_expression struct is used by xtd::expressions::operator +().
    /// @par Examples
    /// The following example shows how to use xtd::expressions::if_then_else_expression.
    /// @include if_then_else_expression.cpp
    template <typename condition_t, typename then_t, typename else_t>
    struct if_then_else_expression : conditional_expression {
      /// @name Public Fields
      
      /// @{
      /// @brief The operator precedence. That contains one of xtd::expressions::operator_precedence values.
      static constexpr operator_precedence precedence = operator_precedence::ternary;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::if_then_else_expression object.
      constexpr if_then_else_expression() = default;
      
      /// @brief Initialize a new xtd::expressions::logical_or_expression object with specified left and right operands.
      /// @oaram condition The condition.
      /// @param then_ The then expression.
      /// @param else The else expression.
      constexpr if_then_else_expression(condition_t condition, then_t then_, else_t else_) : condition(std::move(condition)), then_(std::move(then_)), else_(std::move(else_)) {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Equal to the specified arguments.
      /// @param args the arguments to or.
      /// @return The result of if then else.
      template <typename... args_t>
      constexpr auto operator()(args_t&&... args) const {return condition(args...) ? then_(args...) : else_(args...);}
      /// @}
      
      /// @cond
      friend inline auto operator <<(std::ostream& os, const if_then_else_expression& e) -> std::ostream& {return os << expression_stream {e.condition, e.precedence} << " ? " << expression_stream {e.then_, e.precedence} << " : " << expression_stream {e.else_, e.precedence};}
      /// @endcond
      
    private:
      [[no_unique_address]] condition_t condition;
      [[no_unique_address]] then_t then_;
      [[no_unique_address]] else_t else_;
    };

    /// @name Public Operators
    
    /// @{
    /// @brief If condition is true return then_ else retur nelse_.
    /// @param left The left operand.
    /// @param right The right operand.
    /// @return The result of addition.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/if_then_else_expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::if_then_else_expression.
    /// @include if_then_else_expression.cpp
    template <typename condition_t, typename then_t, typename else_t>
    requires expression_operand<condition_t> || expression_operand<then_t> || expression_operand<else_t>
    constexpr auto if_then_else(condition_t condition, then_t then_, else_t else_) {
      auto condition_expression = as_expression(condition);
      auto then_expression = as_expression(then_);
      auto else_expression = as_expression(else_);
      return if_then_else_expression<std::decay_t<decltype(condition_expression)>, std::decay_t<decltype(then_expression)>, std::decay_t<decltype(else_expression)>> {std::move(condition_expression), std::move(then_expression), std::move(else_expression)};
    }
    /// @}
  }
}

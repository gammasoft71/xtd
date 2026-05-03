/// @file
/// @brief Contains xtd::expressions::unary_minus_expression operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "expression_operand.hpp"
#include "expression_stream.hpp"
#include "unary_expression.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::unary_minus_expression is the unary minus expression.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/unari_minus_expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks The xtd::expressions::unary_minus_expression struct is used by xtd::expressions::expression::unary_minus expression.
    template <typename value_t>
    struct unary_minus_expression : unary_expression {
      /// @name Public Fields
      
      /// @{
      /// @brief The operator precedence. That contains one of xtd::expressions::operator_precedence values.
      static constexpr operator_precedence precedence = operator_precedence::unary_minus;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::unary_minus_expression object.
      constexpr unary_minus_expression() = default;
      
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
    
    /// @cond
    template <typename vakue_t>
    requires std::is_base_of_v<expression, std::decay_t<vakue_t>>
    constexpr auto expression::negate(vakue_t value) {return expression::unary_minus(std::move(value));}

    template <typename vakue_t>
    requires std::is_base_of_v<expression, std::decay_t<vakue_t>>
    constexpr auto expression::unary_minus(vakue_t value) {
      auto expression = as_expression(value);
      return unary_minus_expression<std::decay_t<decltype(expression)>> {std::move(expression)};
    }
    /// @endcond

    /// @name Public Operators
    
    /// @{
    /// @brief Add the specified left and right operands.
    /// @param left The left operand.
    /// @param right The right operand.
    /// @return The result of unary minus.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/unari_minus_expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::expression::unary_minus.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   // auto unary_minus1 = [value](auto&& _) {return -_;};
    ///   auto unary_minus1 = -_;
    ///   println("unary_minus1 result => {}", unary_minus1(42));
    ///   auto unary_minus2 = expression::unary_minus(_);
    ///   println("unary_minus2 result => {}", unary_minus2(42));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // unary_minus1 result => -42
    /// // unary_minus2 result => -42
    /// ```
    template <typename value_t>
    requires expression_operand<value_t>
    constexpr auto operator -(value_t value) {return expression::unary_minus(std::move(value));}
    /// @}
  }
}

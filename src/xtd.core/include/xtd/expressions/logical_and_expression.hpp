/// @file
/// @brief Contains xtd::expressions::logical_and_expression operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "binary_expression.hpp"
#include "expression_operand.hpp"
#include "expression_stream.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::logical_and_expression is the and alse expression.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/logical_and_expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks The xtd::expressions::logical_and_expression struct is used by xtd::expressions::expression::and_also method.
    template <typename left_t, typename right_t>
    struct logical_and_expression : binary_expression {
      /// @name Public Fields
      
      /// @{
      /// @brief The operator precedence. That contains one of xtd::expressions::operator_precedence values.
      static constexpr operator_precedence precedence = operator_precedence::logical_and;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::logical_and_expression object with specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      constexpr logical_and_expression(left_t left, right_t right) : left {std::move(left)}, right {std::move(right)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Equal to the specified arguments.
      /// @param args the arguments to and.
      /// @return The result of and also.
      template <typename... args_t>
      constexpr auto operator()(args_t&&... args) const {return left(std::forward<args_t>(args)...) && right(std::forward<args_t>(args)...);}
      /// @}
      
      /// @cond
      friend inline auto operator <<(std::ostream& os, const logical_and_expression& e) -> std::ostream& {return os << expression_stream {e.left, e.precedence} << " && " << expression_stream {e.right, e.precedence};}
      /// @endcond

    private:
      [[no_unique_address]] left_t left;
      [[no_unique_address]] right_t right;
    };
    
    /// @cond
    template <typename left_t, typename right_t>
    requires std::is_base_of_v<expression, std::decay_t<left_t>> || std::is_base_of_v<expression, std::decay_t<right_t>>
    constexpr auto expression::and_also(left_t left, right_t right) {return expression::logical_and(std::move(left), std::move(right));}
    
    template <typename left_t, typename right_t>
    requires std::is_base_of_v<expression, std::decay_t<left_t>> || std::is_base_of_v<expression, std::decay_t<right_t>>
    constexpr auto expression::logical_and(left_t left, right_t right) {
      auto left_expression = as_expression(left);
      auto right_expression = as_expression(right);
      return logical_and_expression<std::decay_t<decltype(left_expression)>, std::decay_t<decltype(right_expression)>> {std::move(left_expression), std::move(right_expression)};
    }
    /// @endcond
    
    /// @name Public Operators
    
    /// @{
    /// @brief Equal to the specified left and right operands.
    /// @param left The left operand.
    /// @param right The right operand.
    /// @return The result of logical and.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/logical_and_expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::expression::logical_and.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   auto value = true;
    ///   auto logical_and1 = _ && value;
    ///   println("logical_and1 result => {}", logical_and1(42 % 2 == 0));
    ///   auto logical_and2 = expression::logical_and(_, value);
    ///   println("logical_and2 result => {}", logical_and2(42 % 2 == 0));
    ///   println();
    ///   auto logical_and3 = _1 && _2;
    ///   println("and_also3 result => {}", logical_and3(42 % 2 == 0, 42 % 8 == 0));
    ///   auto logical_and4 = expression::logical_and(_1, _2);
    ///   println("logical_and4 result => {}", logical_and4(42 % 2 == 0, 42 % 8 == 0));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // logical_and1 result => true
    /// // logical_and2 result => true
    /// //
    /// // logical_and3 result => false
    /// // logical_and4 result => false
    /// ```
    template <typename left_t, typename right_t>
    requires expression_operand<left_t> || expression_operand<right_t>
    constexpr auto operator &&(left_t left, right_t right) {return expression::logical_and(std::move(left), std::move(right));}
    /// @}
  }
}

/// @file
/// @brief Contains xtd::expressions::divide_expression operator.
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
    /// @brief The xtd::expressions::divide_expression is the division expression.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/divide_expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks The xtd::expressions::divide_expression struct is used by xtd::expressions::operator /().
    template <typename left_t, typename right_t>
    struct divide_expression : binary_expression {
      /// @name Public Fields
      
      /// @{
      /// @brief The operator precedence. That contains one of xtd::expressions::operator_precedence values.
      static constexpr operator_precedence precedence = operator_precedence::division;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::divide_expression object with specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      constexpr divide_expression(left_t left, right_t right) : left {std::move(left)}, right {std::move(right)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Divide the specified arguments.
      /// @param args the arguments to divide.
      /// @return The result of divison.
      template <typename... args_t>
      constexpr auto operator()(args_t&&... args) const {return left(std::forward<args_t>(args)...) / right(std::forward<args_t>(args)...);}
      /// @}
      
      /// @cond
      friend inline auto operator <<(std::ostream& os, const divide_expression& e) -> std::ostream& {return os << expression_stream {e.left, e.precedence} << " / " << expression_stream {e.right, e.precedence};}
      /// @endcond

    private:
      [[no_unique_address]] left_t left;
      [[no_unique_address]] right_t right;
    };
    
    /// @cond
    template <typename left_t, typename right_t>
    requires std::is_base_of_v<expression, std::decay_t<left_t>> || std::is_base_of_v<expression, std::decay_t<right_t>>
    constexpr auto expression::divide(left_t left, right_t right) {
      auto left_expression = as_expression(left);
      auto right_expression = as_expression(right);
      return divide_expression<std::decay_t<decltype(left_expression)>, std::decay_t<decltype(right_expression)>> {std::move(left_expression), std::move(right_expression)};
    }
    /// @endcond

    /// @name Public Operators
    
    /// @{
    /// @brief Divide the specified left and right operands.
    /// @param left The left operand.
    /// @param right The right operand.
    /// @return The result of division.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/divide_expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::expression::divide.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   // auto divide1 = [](auto&& _) {return _ / 10;};
    ///   auto divide1 = _ / 10;
    ///   println("divide1 result => {}", divide1(50));
    ///   auto divide2 = expression::divide(_, 10);
    ///   println("divide2 result => {}", divide2(50));
    ///   println();
    ///   // auto divide3 = [](auto&& _1, auto&& _2) {return _1 / _2;};
    ///   auto divide3 = _1 3 _2;
    ///   println("add3 result => {}", divide3(60, 15));
    ///   auto divide4 = expression::divide(_1, _2);
    ///   println("add4 result => {}", divide4(60, 15));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // divide1 result => 5
    /// // divide2 result => 5
    /// //
    /// // divide3 result => 4
    /// // divide4 result => 4
    /// ```
    template <typename left_t, typename right_t>
    requires expression_operand<left_t> || expression_operand<right_t>
    constexpr auto operator /(left_t left, right_t right) {return expression::divide(std::move(left), std::move(right));}
    /// @}
  }
}

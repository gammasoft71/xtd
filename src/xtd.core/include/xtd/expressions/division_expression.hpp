/// @file
/// @brief Contains xtd::expressions::division_expression operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "expression_operand.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::division_expression is the division expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::division_expression struct is used by xtd::expressions::operator /().
    template <typename left_t, typename right_t>
    struct division_expression : expression_base {
      static constexpr operator_precedence precedence = operator_precedence::division;
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::division_expression object with specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      constexpr division_expression(auto left, auto right) : left {std::move(left)}, right {std::move(right)} {}
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
      friend inline auto operator <<(std::ostream& os, const division_expression& e) -> std::ostream& {
        print_with_parens(os, e.left, e.precedence);
        os << " / ";
        print_with_parens(os, e.right, e.precedence);
        return os;
      }
      /// @endcond

    private:
      left_t left;
      right_t right;
    };
    
    /// @name Public Operators
    
    /// @{
    /// @brief Divide the specified left and right operands.
    /// @param left The left operand.
    /// @param right The right operand.
    /// @return The result of division.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::division_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   auto div1 = _ / 10;
    ///   println("div1 result => {}", div1(50));
    ///   auto div2 = _1 / _2;
    ///   println("div2 result => {}", div2(60, 15));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // div1 result => 5
    /// // div2 result => 4
    /// ```
    template <typename left_t, typename right_t>
    requires expression_operand<left_t, right_t>
    constexpr auto operator /(left_t left, right_t right) {
      return division_expression<std::decay_t<decltype(as_expression(left))>, std::decay_t<decltype(as_expression(right))>> {as_expression(left), as_expression(right)};
    }
    /// @}
  }
}

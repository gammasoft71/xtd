/// @file
/// @brief Contains xtd::expressions::and_expression operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "expression_operand.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::and_expression is the and expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::and_expression struct is used by xtd::expressions::operator &&().
    template <typename left_t, typename right_t>
    struct and_expression : expression_base {
      static constexpr operator_precedence precedence = operator_precedence::logical_and;
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::and_expression object with specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      constexpr and_expression(auto&& left, auto&& right) : left {std::forward<decltype(left)>(left)}, right {std::forward<decltype(right)>(right)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Equal to the specified arguments.
      /// @param args the arguments to and.
      /// @return The result of and.
      template <typename... args_t>
      constexpr auto operator()(args_t&&... args) const {return left(std::forward<args_t>(args)...) && right(std::forward<args_t>(args)...);}
      /// @}
      
      /// @cond
      friend inline auto operator <<(std::ostream& os, const and_expression& e) -> std::ostream& {
        print_with_parens(os, e.left, e.precedence);
        os << " && ";
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
    /// @brief Equal to the specified left and right operands.
    /// @param left The left operand.
    /// @param right The right operand.
    /// @return The result of and.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::and_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   auto eq1 = _ && true;
    ///   println("eq1 result => {}", eq1(true));
    ///   auto eq2 = _1 > _2;
    ///   println("eq2 result => {}", eq2(true, false));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // eq1 result => true
    /// // eq2 result => false
    /// ```
    template <typename left_t, typename right_t>
    requires expression_operand<left_t, right_t>
    constexpr auto operator &&(left_t left, right_t right) {return and_expression<decltype(as_expression(left)), decltype(as_expression(right))> {as_expression(left), as_expression(right)};}
    /// @}
  }
}

/// @file
/// @brief Contains xtd::expressions::greater_or_equal_expression operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "expression_operand.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::greater_or_equal_expression is the greater or equal expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::greater_or_equal_expression struct is used by xtd::expressions::operator >=().
    template <typename left_t, typename right_t>
    struct greater_or_equal_expression : expression_base {
      static constexpr operator_precedence precedence = operator_precedence::greater_or_equal;
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::greater_or_equal_expression object with specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      constexpr greater_or_equal_expression(auto&& left, auto&& right) : left {std::forward<decltype(left)>(left)}, right {std::forward<decltype(right)>(right)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Equal to the specified arguments.
      /// @param args the arguments to greater or equal.
      /// @return The result of greater or equal.
      template <typename... args_t>
      constexpr auto operator()(args_t&&... args) const {return left(std::forward<args_t>(args)...) >= right(std::forward<args_t>(args)...);}
      /// @}
      
      /// @cond
      friend inline auto operator <<(std::ostream& os, const greater_or_equal_expression& e) -> std::ostream& {
        print_with_parens(os, e.left, e.precedence);
        os << " >= ";
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
    /// @return The result of addition.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::greater_or_equal_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   auto geq1 = _ >= 10;
    ///   println("geq1 result => {}", geq1(42));
    ///   auto geq2 = _1 >= _2;
    ///   println("geq2 result => {}", geq2(32, 42));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // geq1 result => true
    /// // geq2 result => false
    /// ```
    template <typename left_t, typename right_t>
    requires expression_operand<left_t, right_t>
    constexpr auto operator >=(left_t left, right_t right) {return greater_or_equal_expression<decltype(as_expression(left)), decltype(as_expression(right))> {as_expression(left), as_expression(right)};}
    /// @}
  }
}

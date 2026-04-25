/// @file
/// @brief Contains xtd::expressions::not_equal_to_expression operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "expression_operand.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::not_equal_to_expression is the not equal expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::not_equal_to_expression struct is used by xtd::expressions::operator !=().
    template <typename left_t, typename right_t>
    struct not_equal_to_expression : expression_base {
      static constexpr operator_precedence precedence = operator_precedence::not_equal;
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::not_equal_to_expression object with specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      constexpr not_equal_to_expression(auto&& left, auto&& right) : left {std::forward<decltype(left)>(left)}, right {std::forward<decltype(right)>(right)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Equal to the specified arguments.
      /// @param args the arguments to not equal.
      /// @return The result of not equal.
      template <typename... args_t>
      constexpr auto operator()(args_t&&... args) const {return left(std::forward<args_t>(args)...) != right(std::forward<args_t>(args)...);}
      /// @}
      
      /// @cond
      friend inline auto operator <<(std::ostream& os, const not_equal_to_expression& e) -> std::ostream& {
        print_with_parens(os, e.left, e.precedence);
        os << " != ";
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
    /// @return The result of not equal.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::not_equal_to_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   auto neq1 = _ != 10;
    ///   println("neq1 result => {}", neq1(42));
    ///   auto neq2 = _1 != _2;
    ///   println("neq2 result => {}", neq2(42, 42));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // neq1 result => true
    /// // neq2 result => false
    /// ```
    template <typename left_t, typename right_t>
    requires expression_operand<left_t, right_t>
    constexpr auto operator !=(left_t left, right_t right) {return not_equal_to_expression<decltype(as_expression(left)), decltype(as_expression(right))> {as_expression(left), as_expression(right)};}
    /// @}
  }
}

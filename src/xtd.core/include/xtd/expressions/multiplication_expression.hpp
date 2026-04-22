/// @file
/// @brief Contains xtd::expressions::multiplication_expression operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "expression_operand.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::multiplication_expression is the multiplication expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::multiplication_expression struct is used by xtd::expressions::operator *().
    template <typename left_t, typename right_t>
    struct multiplication_expression : expression_base {
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::multiplication_expression object with specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      constexpr multiplication_expression(auto&& left, auto&& right) : left {std::forward<decltype(left)>(left)}, right {std::forward<decltype(right)>(right)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Multiply the specified arguments.
      /// @param args the arguments to multiply.
      /// @return The result of addition.
      template <typename... args_t>
      constexpr auto operator()(args_t&&... args) const {return left(std::forward<args_t>(args)...) * right(std::forward<args_t>(args)...);}
      /// @}
      
    private:
      left_t left;
      right_t right;
    };
    
    /// @name Public Operators
    
    /// @{
    /// @brief Multiply the specified left and right operands.
    /// @param left The left operand.
    /// @param right The right operand.
    /// @return The result of division.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::multiplication_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   auto mul1 = _ * 10;
    ///   println("mul1 result => {}", mul1(5));
    ///   auto mul2 = _1 * _2;
    ///   println("mul2 result => {}", mul2(4, 15));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // mul1 result => 50
    /// // mul2 result => 60
    /// ```
    template <typename left_t, typename right_t>
    requires expression_operand<left_t, right_t>
    constexpr auto operator *(left_t left, right_t right) {return multiplication_expression<decltype(as_expression(left)), decltype(as_expression(right))> {as_expression(left), as_expression(right)};}
    /// @}
  }
}

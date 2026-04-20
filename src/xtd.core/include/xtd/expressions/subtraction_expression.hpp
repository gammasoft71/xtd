/// @file
/// @brief Contains xtd::expressions::subtraction_expression operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "expression_operand.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::subtraction_expression is the subtraction expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::subtraction_expression struct is used by xtd::expressions::operator -().
    template <typename left_t, typename right_t>
    struct subtraction_expression : expression_base {
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::subtraction_expression object with specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      constexpr subtraction_expression(auto&& left, auto&& right) : left {std::forward<decltype(left)>(left)}, right {std::forward<decltype(right)>(right)} {}
      template <typename... args_t>
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Subtract the specified arguments.
      /// @param args the arguments to subtract.
      /// @return The result of addition.
      constexpr auto operator()(args_t&&... args) const {return left(std::forward<args_t>(args)...) - right(std::forward<args_t>(args)...);}
      /// @}
      
    private:
      left_t left;
      right_t right;
    };
    
    /// @name Public Operators
    
    /// @{
    /// @brief Subtract the specified left and right operands.
    /// @param left The left operand.
    /// @param right The right operand.
    /// @return The result of addition.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::subtraction_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   auto sub1 = _ - 10;
    ///   println("sub1 result => {}", sub1(42));
    ///   auto sub2 = _1 - _2;
    ///   println("sub2 result => {}", sub2(42, 12));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // sub1 result => 32
    /// // sub2 result => 30
    /// ```
    template <typename left_t, typename right_t>
    requires expression_operand<left_t, right_t>
    constexpr auto operator -(left_t left, right_t right) {return subtraction_expression<decltype(as_expression(left)), decltype(as_expression(right))> {as_expression(left), as_expression(right)};}
    /// @}
  }
}

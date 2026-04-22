/// @file
/// @brief Contains xtd::expressions::addition_expression operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "expression_operand.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::addition_expression is the addition expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::addition_expression struct is used by xtd::expressions::operator +().
    template <typename left_t, typename right_t>
    struct addition_expression : expression_base {
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::addition_expression object with specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      constexpr addition_expression(auto&& left, auto&& right) : left {std::forward<decltype(left)>(left)}, right {std::forward<decltype(right)>(right)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Add the specified arguments.
      /// @param args the arguments to add.
      /// @return The result of addition.
      template <typename... args_t>
      constexpr auto operator()(args_t&&... args) const {return left(std::forward<args_t>(args)...) + right(std::forward<args_t>(args)...);}
      /// @}
      
    private:
      left_t left;
      right_t right;
    };
    
    /// @name Public Operators
    
    /// @{
    /// @brief Add the specified left and right operands.
    /// @param left The left operand.
    /// @param right The right operand.
    /// @return The result of addition.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::addition_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   auto add1 = _ + 10;
    ///   println("add1 result => {}", add1(42));
    ///   auto add2 = _1 + _2;
    ///   println("add2 result => {}", add2(42, 15));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // add1 result => 52
    /// // add2 result => 57
    /// ```
    template <typename left_t, typename right_t>
    requires expression_operand<left_t, right_t>
    constexpr auto operator +(left_t left, right_t right) {
      return addition_expression<decltype(as_expression(left)), decltype(as_expression(right))> {as_expression(left), as_expression(right)};
    }
    /// @}
  }
}

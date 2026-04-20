/// @file
/// @brief Contains xtd::expressions::equal_to_expression operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "expression_operand.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::equal_to_expression is the equal to expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::equal_to_expression struct is used by xtd::expressions::operator ==().
    template <typename left_t, typename right_t>
    struct equal_to_expression : expression_base {
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::equal_to_expression object with specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      constexpr equal_to_expression(auto&& left, auto&& right) : left {std::forward<decltype(left)>(left)}, right {std::forward<decltype(right)>(right)} {}
      template <typename... args_t>
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Equal to the specified arguments.
      /// @param args the arguments to equal to.
      /// @return The result of addition.
      constexpr auto operator()(args_t&&... args) const {return left(std::forward<args_t>(args)...) == right(std::forward<args_t>(args)...);}
      /// @}
      
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
    /// The following example shows how to use xtd::expressions::equal_to_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   auto eq1 = _ == 10;
    ///   println("eq1 result => {}", eq1(42));
    ///   auto eq2 = _1 == _2;
    ///   println("eq2 result => {}", eq2(42, 42));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // eq1 result => false
    /// // eq2 result => true
    /// ```
    template <typename left_t, typename right_t>
    requires expression_operand<left_t, right_t>
    constexpr auto operator ==(left_t left, right_t right) {return equal_to_expression<decltype(as_expression(left)), decltype(as_expression(right))> {as_expression(left), as_expression(right)};}
    /// @}
  }
}

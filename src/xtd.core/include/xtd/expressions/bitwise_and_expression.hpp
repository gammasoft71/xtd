/// @file
/// @brief Contains xtd::expressions::bitwise_and_expression operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "expression_operand.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::bitwise_and_expression is the bitwise and expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::bitwise_and_expression struct is used by xtd::expressions::operator |().
    /// @par Examples
    /// The following example shows how to use xtd::expressions::bitwise_and_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   //auto bit_and1 = [](auto&& _) {return _ & 0x0F;};
    ///   auto bit_and1 = _ & 0x0F;
    ///   println("sub1 result => {}", bit_and1(42));
    ///   //auto bit_and2 = [](auto&& _1, auto&& _2) {return _1 & _2;}
    ///   auto bit_and2 = _1 & _2;
    ///   println("bit_and2 result => {}", bit_and2(42, 0xF0));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // bit_and1 result => 10
    /// // bit_and2 result => 8
    /// ```
    template <typename left_t, typename right_t>
    struct bitwise_and_expression : expression_base {
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::bitwise_and_expression object with specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      constexpr bitwise_and_expression(auto&& left, auto&& right) : left {std::forward<decltype(left)>(left)}, right {std::forward<decltype(right)>(right)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Subtract the specified arguments.
      /// @param args the arguments to bitwise and.
      /// @return The result of addition.
      template <typename... args_t>
      constexpr auto operator()(args_t&&... args) const {return left(std::forward<args_t>(args)...) & right(std::forward<args_t>(args)...);}
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
    /// The following example shows how to use xtd::expressions::bitwise_and_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   //auto bit_and1 = [](auto&& _) {return _ & 0x0F;};
    ///   auto bit_and1 = _ & 0x0F;
    ///   println("sub1 result => {}", bit_and1(42));
    ///   //auto bit_and2 = [](auto&& _1, auto&& _2) {return _1 & _2;}
    ///   auto bit_and2 = _1 & _2;
    ///   println("bit_and2 result => {}", bit_and2(42, 0xF0));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // bit_and1 result => 10
    /// // bit_and2 result => 8
    /// ```
    template <typename left_t, typename right_t>
    requires expression_operand<left_t, right_t>
    constexpr auto operator &(left_t left, right_t right) {return bitwise_and_expression<decltype(as_expression(left)), decltype(as_expression(right))> {as_expression(left), as_expression(right)};}
    /// @}
  }
}

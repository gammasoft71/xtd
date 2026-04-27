/// @file
/// @brief Contains xtd::expressions::bitwise_right_expression operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "expression_operand.hpp"
#include "../numeric.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::bitwise_right_expression is the bitwise right expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::bitwise_right_expression struct is used by xtd::expressions::operator >>().
    /// @par Examples
    /// The following example shows how to use xtd::expressions::bitwise_right_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   //auto bit_right1 = [](auto&& _) {return _ >> 2;};
    ///   auto bit_right1 = _ >> 2;
    ///   println("bit_right1 result => {}", bit_right1(42));
    ///   //auto bit_right2 = [](auto&& _1, auto&& _2) {return _1 >> _2;};
    ///   auto bit_right2 = _1 >> _2;
    ///   println("bit_right2 result => {}", bit_right2(42, 4));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // bit_right1 result => 10
    /// // bit_right2 result => 2
    /// ```
    template <typename left_t, typename right_t>
    struct bitwise_right_expression : expression_base {
      /// @name Public Fields
      
      /// @{
      /// @brief The operator precedence. That contains one of xtd::expressions::operator_precedence values.
      static constexpr operator_precedence precedence = operator_precedence::bitwise_right;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::bitwise_right_expression object with specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      constexpr bitwise_right_expression(left_t left, right_t right) : left {std::move(left)}, right {std::move(right)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Bitwise left the specified arguments.
      /// @param args the arguments to bitwise right.
      /// @return The result of left.
      template <typename... args_t>
      constexpr auto operator()(args_t&&... args) const {
        auto&& l = left(std::forward<args_t>(args)...);
        using result_t = std::decay_t<decltype(l)>;
        if constexpr (xtd::numeric<result_t>) return static_cast<result_t>(l >> right(std::forward<args_t>(args)...));
        else return l >> right(std::forward<args_t>(args)...);
      }
      /// @}
      
      /// @cond
      friend inline auto operator <<(std::ostream& os, const bitwise_right_expression& e) -> std::ostream& {
        print_with_parens(os, e.left, e.precedence);
        os << " > ";
        print_with_parens(os, e.right, e.precedence);
        return os;
      }
      /// @endcond

    private:
      [[no_unique_address]] left_t left;
      [[no_unique_address]] right_t right;
    };

    /// @name Public Operators
    
    /// @{
    /// @brief Subtract the specified left and right operands.
    /// @param left The left operand.
    /// @param right The right operand.
    /// @return The result of bitwise right.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::bitwise_right_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   //auto bit_right1 = [](auto&& _) {return _ >> 2;};
    ///   auto bit_right1 = _ >> 2;
    ///   println("bit_right1 result => {}", bit_right1(42));
    ///   //auto bit_right2 = [](auto&& _1, auto&& _2) {return _1 >> _2;};
    ///   auto bit_right2 = _1 >> _2;
    ///   println("bit_right2 result => {}", bit_right2(42, 4));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // bit_right1 result => 10
    /// // bit_right2 result => 2
    /// ```
    template <typename left_t, typename right_t>
    requires expression_operand<left_t> || expression_operand<right_t>
    constexpr auto operator >>(left_t left, right_t right) {
      auto left_expression = as_expression(left);
      auto right_expression = as_expression(right);
      return bitwise_right_expression<std::decay_t<decltype(left_expression)>, std::decay_t<decltype(right_expression)>> {std::move(left_expression), std::move(right_expression)};
    }
    /// @}
  }
}

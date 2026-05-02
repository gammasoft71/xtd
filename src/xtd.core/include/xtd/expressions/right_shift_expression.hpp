/// @file
/// @brief Contains xtd::expressions::right_shift_expression operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "binary_expression.hpp"
#include "expression_operand.hpp"
#include "expression_stream.hpp"
#include "../numeric.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::right_shift_expression is the bitwise right expression.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/right_shift_expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks The xtd::expressions::right_shift_expression struct is used by xtd::expressions::expression::right_shift method.
    template <typename left_t, typename right_t>
    struct right_shift_expression : binary_expression {
      /// @name Public Fields
      
      /// @{
      /// @brief The operator precedence. That contains one of xtd::expressions::operator_precedence values.
      static constexpr operator_precedence precedence = operator_precedence::bitwise_right;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::right_shift_expression object with specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      constexpr right_shift_expression(left_t left, right_t right) : left {std::move(left)}, right {std::move(right)} {}
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
      friend inline auto operator <<(std::ostream& os, const right_shift_expression& e) -> std::ostream& {return os << expression_stream {e.left, e.precedence} << " >> " << expression_stream {e.right, e.precedence};}
      /// @endcond

    private:
      [[no_unique_address]] left_t left;
      [[no_unique_address]] right_t right;
    };
    
    /// @cond
    template <typename left_t, typename right_t>
    requires std::is_base_of_v<expression, std::decay_t<left_t>> || std::is_base_of_v<expression, std::decay_t<right_t>>
    constexpr auto expression::right_shift(left_t left, right_t right) {
      auto left_expression = as_expression(left);
      auto right_expression = as_expression(right);
      return right_shift_expression<std::decay_t<decltype(left_expression)>, std::decay_t<decltype(right_expression)>> {std::move(left_expression), std::move(right_expression)};
    }
    /// @endcond

    /// @name Public Operators
    
    /// @{
    /// @brief Subtract the specified left and right operands.
    /// @param left The left operand.
    /// @param right The right operand.
    /// @return The result of bitwise right.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/right_shift_expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::expression::right_shift.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   // auto right_shift1 = [](auto&& _) {return _ >> 2;};
    ///   auto right_shift1 = _ >> 2;
    ///   println("right_shift1 result => {}", right_shift1(42));
    ///   auto right_shift2 = expression::right_shift(_, 2);
    ///   println("right_shift2 result => {}", right_shift2(42));
    ///   println();
    ///   // auto right_shift3 = [](auto&& _1, auto&& _2) {return _1 >> _2;};
    ///   auto right_shift3 = _1 >> _2;
    ///   println("right_shift3 result => {}", right_shift3(42, 4));
    ///   auto right_shift4 = expression::right_shift(_1, _2);
    ///   println("right_shift4 result => {}", right_shift4(42, 4));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // right_shift1 result => 10
    /// // right_shift2 result => 10
    /// //
    /// // right_shift3 result => 2
    /// // right_shift4 result => 2
    /// ```
    template <typename left_t, typename right_t>
    requires expression_operand<left_t> || expression_operand<right_t>
    constexpr auto operator >>(left_t left, right_t right) {return expression::right_shift(std::move(left), std::move(right));}
    /// @}
  }
}

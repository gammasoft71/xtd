/// @file
/// @brief Contains xtd::expressions::and_expression operator.
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
    /// @brief The xtd::expressions::and_expression is the bitwise and expression.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/and_expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks The xtd::expressions::and_expression struct is used by xtd::expressions::expression::and_ method.
    template <typename left_t, typename right_t>
    struct and_expression : binary_expression {
      /// @name Public Fields
      
      /// @{
      /// @brief The operator precedence. That contains one of xtd::expressions::operator_precedence values.
      static constexpr operator_precedence precedence = operator_precedence::bitwise_and;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::and_expression object with specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      constexpr and_expression(left_t left, right_t right) : left {std::move(left)}, right {std::move(right)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Bitwise and the specified arguments.
      /// @param args the arguments to bitwise and.
      /// @return The result of bitwise and.
      template <typename... args_t>
      constexpr auto operator()(args_t&&... args) const {
        auto&& l = left(std::forward<args_t>(args)...);
        auto&& r = right(std::forward<args_t>(args)...);
        using result_t = std::decay_t<decltype(l & r)>;
        if constexpr (xtd::numeric<result_t>) return static_cast<result_t>(l & r);
        else return l & r;
      }
      /// @}
      
      /// @cond
      friend inline auto operator <<(std::ostream& os, const and_expression& e) -> std::ostream& {return os << expression_stream {e.left, e.precedence} << " & " << expression_stream {e.right, e.precedence};}
      /// @endcond

    private:
      [[no_unique_address]] left_t left;
      [[no_unique_address]] right_t right;
    };
    
    /// @cond
    template <typename left_t, typename right_t>
    requires std::is_base_of_v<expression, std::decay_t<left_t>> || std::is_base_of_v<expression, std::decay_t<right_t>>
    constexpr auto expression::and_(left_t left, right_t right) {
      auto left_expression = as_expression(left);
      auto right_expression = as_expression(right);
      return and_expression<std::decay_t<decltype(left_expression)>, std::decay_t<decltype(right_expression)>> {std::move(left_expression), std::move(right_expression)};
    }
    /// @endcond

    /// @name Public Operators
    
    /// @{
    /// @brief Subtract the specified left and right operands.
    /// @param left The left operand.
    /// @param right The right operand.
    /// @return The result of bitwise and.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/and_expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::expression::and_.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   auto and1 = _ & 0x0F;
    ///   println("and1 result => {:B}", and1(42));
    ///   auto and2 = expression::and_(_, 0x0F);
    ///   println("and2 result => {:B}", and2(42));
    ///   println();
    ///   auto and3 = _1 & _2;
    ///   println("and3 result => {:B}", and3(42, 0xF0));
    ///   auto and4 = expression::and_(_1, _2);
    ///   println("and4 result => {:B}", and4(42, 0xF0));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // and1 result => 1010
    /// // and2 result => 1010
    /// //
    /// // and3 result => 100000
    /// // and4 result => 100000
    /// ```
    template <typename left_t, typename right_t>
    requires expression_operand<left_t> || expression_operand<right_t>
    constexpr auto operator &(left_t left, right_t right) {return expression::and_(std::move(left), std::move(right));}
    /// @}
  }
}

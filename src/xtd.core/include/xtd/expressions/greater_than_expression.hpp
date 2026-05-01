/// @file
/// @brief Contains xtd::expressions::greater_than_expression operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "binary_expression.hpp"
#include "expression_operand.hpp"
#include "expression_stream.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::greater_than_expression is the greater expression.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/greater_than_expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks The xtd::expressions::greater_than_expression struct is used by xtd::expressions::operator >().
    template <typename left_t, typename right_t>
    struct greater_than_expression : binary_expression {
      /// @name Public Fields
      
      /// @{
      /// @brief The operator precedence. That contains one of xtd::expressions::operator_precedence values.
      static constexpr operator_precedence precedence = operator_precedence::greater;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::greater_than_expression object with specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      constexpr greater_than_expression(left_t left, right_t right) : left {std::move(left)}, right {std::move(right)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Equal to the specified arguments.
      /// @param args the arguments to greater.
      /// @return The result of greater.
      template <typename... args_t>
      constexpr auto operator()(args_t&&... args) const {return left(std::forward<args_t>(args)...) > right(std::forward<args_t>(args)...);}
      /// @}
      
      /// @cond
      friend inline auto operator <<(std::ostream& os, const greater_than_expression& e) -> std::ostream& {return os << expression_stream {e.left, e.precedence} << " > " << expression_stream {e.right, e.precedence};}
      /// @endcond

    private:
      [[no_unique_address]] left_t left;
      [[no_unique_address]] right_t right;
    };
    
    /// @cond
    template <typename left_t, typename right_t>
    requires std::is_base_of_v<expression, std::decay_t<left_t>> || std::is_base_of_v<expression, std::decay_t<right_t>>
    constexpr auto expression::greater_than(left_t left, right_t right) {
      auto left_expression = as_expression(left);
      auto right_expression = as_expression(right);
      return greater_than_expression<std::decay_t<decltype(left_expression)>, std::decay_t<decltype(right_expression)>> {std::move(left_expression), std::move(right_expression)};
    }
    /// @endcond

    /// @name Public Operators
    
    /// @{
    /// @brief Equal to the specified left and right operands.
    /// @param left The left operand.
    /// @param right The right operand.
    /// @return The result of greater.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/greater_than_expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::expression::greater_than.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   // auto greater_than1 = [](auto&& _) {return _ > 10;};
    ///   auto greater_than1 = _ > 10;
    ///   println("greater_than1 result => {}", greater_than1(42));
    ///   auto greater_than2 = expression::greater_than(_, 10);
    ///   println("greater_than2 result => {}", greater_than2(42));
    ///   println();
    ///   // auto greater_than3 = [](auto&& _1, auto&& _2) {return _1 > _2;};
    ///   auto greater_than3 = _1 > _2;
    ///   println("greater_than3 result => {}", greater_than3(42, 42));
    ///   auto greater_than4 = expression::greater_than(_1, _2);
    ///   println("greater_than4 result => {}", greater_than4(42, 42));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // equagreater_than1l1 result => true
    /// // greater_than2 result => true
    /// //
    /// // greater_than2 result => false
    /// // greater_than4 result => false
    /// ```
    template <typename left_t, typename right_t>
    requires expression_operand<left_t> || expression_operand<right_t>
    constexpr auto operator >(left_t left, right_t right) {return expression::greater_than(std::move(left), std::move(right));}
    /// @}
  }
}

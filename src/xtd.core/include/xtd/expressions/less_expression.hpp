/// @file
/// @brief Contains xtd::expressions::less_expression operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "expression_operand.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::less_expression is the less expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::less_expression struct is used by xtd::expressions::operator <().
    template <typename left_t, typename right_t>
    struct less_expression : expression_base {
      static constexpr operator_precedence precedence = operator_precedence::less;
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::less_expression object with specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      constexpr less_expression(left_t left, right_t right) : left {std::move(left)}, right {std::move(right)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Equal to the specified arguments.
      /// @param args the arguments to less.
      /// @return The result of less.
      template <typename... args_t>
      constexpr auto operator()(args_t&&... args) const {return left(std::forward<args_t>(args)...) < right(std::forward<args_t>(args)...);}
      /// @}
      
      /// @cond
      friend inline auto operator <<(std::ostream& os, const less_expression& e) -> std::ostream& {
        print_with_parens(os, e.left, e.precedence);
        os << " < ";
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
    /// @brief Equal to the specified left and right operands.
    /// @param left The left operand.
    /// @param right The right operand.
    /// @return The result of less.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::less_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   auto less1 = _ < 10;
    ///   println("less1 result => {}", less1(42));
    ///   auto less2 = _1 < _2;
    ///   println("less2 result => {}", less2(42, 52));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // less1 result => false
    /// // less2 result => true
    /// ```
    template <typename left_t, typename right_t>
    requires expression_operand<left_t> || expression_operand<right_t>
    constexpr auto operator <(left_t left, right_t right) {
      auto left_expression = as_expression(left);
      auto right_expression = as_expression(right);
      return less_expression<std::decay_t<decltype(left_expression)>, std::decay_t<decltype(right_expression)>> {std::move(left_expression), std::move(right_expression)};
    }
    /// @}
  }
}

/// @file
/// @brief Contains xtd::expressions::three_way_comparison_expression operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "expression_operand.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::three_way_comparison_expression is the three_way_comparison expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::three_way_comparison_expression struct is used by xtd::expressions::operator <=>().
    template <typename left_t, typename right_t>
    struct three_way_comparison_expression : expression_base {
      static constexpr operator_precedence precedence = operator_precedence::three_way_comparison;
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::three_way_comparison_expression object with specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      constexpr three_way_comparison_expression(auto left, auto right) : left {std::move(left)}, right {std::move(right)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Equal to the specified arguments.
      /// @param args the arguments to three_way_comparison.
      /// @return The result of three_way_comparison.
      template <typename... args_t>
      constexpr auto operator()(args_t&&... args) const {return left(std::forward<args_t>(args)...) <=> right(std::forward<args_t>(args)...);}
      /// @}
      
      /// @cond
      friend inline auto operator <<(std::ostream& os, const three_way_comparison_expression& e) -> std::ostream& {
        print_with_parens(os, e.left, e.precedence);
        os << " <=> ";
        print_with_parens(os, e.right, e.precedence);
        return os;
      }
      /// @endcond

    private:
      left_t left;
      right_t right;
    };
    
    /// @name Public Operators
    
    /// @{
    /// @brief Equal to the specified left and right operands.
    /// @param left The left operand.
    /// @param right The right operand.
    /// @return The result of three_way_comparison.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::three_way_comparison_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   //auto three_way_comparison1 = [](auto _) {return _ <=> 10;};
    ///   auto three_way_comparison1 = _ <=> 10;
    ///   println("three_way_comparison1 result => {}", three_way_comparison1(42));
    ///   //auto three_way_comparison2 = [](auto _1, auto _2) {return _1 <=> _2;};
    ///   auto three_way_comparison2 = _1 <=> _2;
    ///   println("three_way_comparison2 result => {}", three_way_comparison2(42, 42));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // three_way_comparison1 result => greater
    /// // three_way_comparison2 result => equivalent
    /// ```
    template <typename left_t, typename right_t>
    requires expression_operand<left_t, right_t>
    constexpr auto operator <=>(left_t left, right_t right) {
      return three_way_comparison_expression<std::decay_t<decltype(as_expression(left))>, std::decay_t<decltype(as_expression(right))>> {as_expression(left), as_expression(right)};
    }
    /// @}
  }
}

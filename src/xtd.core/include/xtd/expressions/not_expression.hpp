/// @file
/// @brief Contains xtd::expressions::not_expression operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "expression_operand.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::not_expression is the not expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::not_expression struct is used by xtd::expressions::operator !().
    /// @par Examples
    /// The following example shows how to use xtd::expressions::not_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   //auto not1 = [](auto _) {return !_;};
    ///   auto not1 = !_;
    ///   println("not1 result => {}", not1(true));
    ///   println("not1 result => {}", not1(false));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // not1 result => false
    /// // not1 result => true
    /// ```
    template <typename value_t>
    struct not_expression : expression_base {
      /// @name Public Fields
      
      /// @{
      /// @brief The operator precedence. That contains one of xtd::expressions::operator_precedence values.
      static constexpr operator_precedence precedence = operator_precedence::logical_not;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::not_expression object with specified value operand.
      /// @param value The value operand.
      constexpr not_expression(value_t value) : value {std::move(value)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Add the specified arguments.
      /// @param args the arguments to add.
      /// @return The result of not.
      template <typename... args_t>
      constexpr auto operator()(args_t&&... args) const {return !value(std::forward<args_t>(args)...);}
      /// @}
      
      /// @cond
      friend inline auto operator <<(std::ostream& os, const not_expression& e) -> std::ostream& {
        os << "!";
        print_with_parens(os, e.value, e.precedence);
        return os;
      }
      /// @endcond

    private:
      [[no_unique_address]] value_t value;
    };

    /// @name Public Operators
    
    /// @{
    /// @brief Add the specified left and right operands.
    /// @param left The left operand.
    /// @param right The right operand.
    /// @return The result of not.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::not_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   //auto not1 = [](auto _) {return !_;};
    ///   auto not1 = !_;
    ///   println("not1 result => {}", not1(true));
    ///   println("not1 result => {}", not1(false));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // not1 result => false
    /// // not1 result => true
    /// ```
    template <typename value_t>
    requires expression_operand<value_t>
    constexpr auto operator !(value_t value) {
      auto expression = as_expression(value);
      return not_expression<std::decay_t<decltype(expression)>> {std::move(expression)};
    }
    /// @}
  }
}

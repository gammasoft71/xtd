/// @file
/// @brief Contains xtd::expressions::unary_plus_expression operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "expression_operand.hpp"
#include "expression_stream.hpp"
#include "unary_expression.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::unary_plus_expression is the unary plus expression.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/unari_plus_expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::unary_plus_expression struct is used by xtd::expressions::expression::unary_plus expression.
    template<typename value_t>
    struct unary_plus_expression : unary_expression {
      /// @name Public Fields
      
      /// @{
      /// @brief The operator precedence. That contains one of xtd::expressions::operator_precedence values.
      static constexpr operator_precedence precedence = operator_precedence::unary_plus;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::unary_plus_expression object.
      constexpr unary_plus_expression() = default;
      
      /// @brief Initialize a new xtd::expressions::unary_plus_expression object with specified value operand.
      /// @param value The value operand.
      constexpr unary_plus_expression(value_t value) : value {std::move(value)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Add the specified arguments.
      /// @param args the arguments to add.
      /// @return The result of unary plus.
      template<typename... args_t>
      constexpr auto operator()(args_t&&... args) const {return +value(std::forward<args_t>(args)...);}
      /// @}
      
      /// @cond
      friend inline auto operator <<(std::ostream& os, const unary_plus_expression& e) -> std::ostream& {return os << "+" << expression_stream {e.value, e.precedence};}
      /// @endcond

    private:
      [[no_unique_address]] value_t value;
    };
    
    /// @cond
    template<typename vakue_t>
    requires std::is_base_of_v<expression, std::decay_t<vakue_t>>
    constexpr auto expression::unary_plus(vakue_t value) {
      auto expression = as_expression(value);
      return unary_plus_expression<std::decay_t<decltype(expression)>> {std::move(expression)};
    }
    /// @endcond

    /// @name Public Operators
    
    /// @{
    /// @brief Add the specified left and right operands.
    /// @param left The left operand.
    /// @param right The right operand.
    /// @return The result of unary plus.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/unari_plus_expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::expression::unary_plus.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   // auto unary_plus1 = [value](auto&& _) {return +_;};
    ///   auto unary_plus1 = +_;
    ///   println("unary_plus1 result => {}", unary_plus1(42));
    ///   auto unary_plus2 = expression::unary_plus(_);
    ///   println("unary_plus2 result => {}", unary_plus2(42));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // unary_plus1 result => 42
    /// // unary_plus2 result => 42
    /// ```
    template<typename value_t>
    requires expression_operand<value_t>
    constexpr auto operator +(value_t value) {return expression::unary_plus(std::move(value));}
    /// @}
  }
}

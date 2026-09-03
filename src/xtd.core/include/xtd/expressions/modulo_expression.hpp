/// @file
/// @brief Contains xtd::expressions::modulo_expression operator.
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
    /// @brief The xtd::expressions::modulo_expression is the modulo expression.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/modulo_expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::modulo_expression struct is used by xtd::expressions::expression::modulo expression.
    template<typename left_t, typename right_t>
    struct modulo_expression : binary_expression {
      /// @name Public Fields
      
      /// @{
      /// @brief The operator precedence. That contains one of xtd::expressions::operator_precedence values.
      static constexpr operator_precedence precedence = operator_precedence::modulo;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::modulo_expression object.
      constexpr modulo_expression() = default;
      
      /// @brief Initialize a new xtd::expressions::modulo_expression object with specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      constexpr modulo_expression(left_t left, right_t right) : left {std::move(left)}, right {std::move(right)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Performs a modulo on the specified arguments.
      /// @param args the arguments to perorm modulo.
      /// @return The result of modulo.
      template<typename... args_t>
      constexpr auto operator()(args_t&&... args) const {return left(std::forward<args_t>(args)...) % right(std::forward<args_t>(args)...);}
      /// @}
      
      /// @cond
      friend inline auto operator <<(std::ostream& os, const modulo_expression& e) -> std::ostream& {return os << expression_stream {e.left, e.precedence} << " & " << expression_stream {e.right, e.precedence};}
      /// @endcond

    private:
      [[no_unique_address]] left_t left;
      [[no_unique_address]] right_t right;
    };
    
    /// @cond
    template<typename left_t, typename right_t>
    requires std::is_base_of_v<expression, std::decay_t<left_t>> || std::is_base_of_v<expression, std::decay_t<right_t>>
    constexpr auto expression::modulo(left_t left, right_t right) {
      auto left_expression = as_expression(left);
      auto right_expression = as_expression(right);
      return modulo_expression<std::decay_t<decltype(left_expression)>, std::decay_t<decltype(right_expression)>> {std::move(left_expression), std::move(right_expression)};
    }
    /// @endcond

    /// @name Public Operators
    
    /// @{
    /// @brief Performs a modulo on the specified left and right operands.
    /// @param left The left operand.
    /// @param right The right operand.
    /// @return The result of division.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/modulo_expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::expression::modulo.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   // auto modulo1 = [](auto&& _) {return _ % 10;};
    ///   auto modulo1 = _ % 10;
    ///   println("modulo1 result => {}", modulo1(27));
    ///   auto modulo2 = expression::modulo(_, 10);
    ///   println("modulo2 result => {}", modulo2(27));
    ///   println();
    ///   // auto modulo3 = [](auto&& _1, auto&& _2) {return _1 % _2;};
    ///   auto modulo3 = _1 % _2;
    ///   println("modulo3 result => {}", modulo3(64, 6));
    ///   auto modulo4 = expression::modulo(_1, _2);
    ///   println("modulo4 result => {}", modulo4(64, 6));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // mul1 result => 7
    /// // mul2 result => 7
    /// //
    /// // mul3 result => 4
    /// // mul4 result => 4
    /// ```
    template<typename left_t, typename right_t>
    requires expression_operand<left_t> || expression_operand<right_t>
    constexpr auto operator %(left_t left, right_t right) {return expression::modulo(std::move(left), std::move(right));}
    /// @}
  }
}

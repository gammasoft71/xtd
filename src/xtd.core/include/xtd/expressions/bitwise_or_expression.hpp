/// @file
/// @brief Contains xtd::expressions::bitwise_or_expression operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "expression_operand.hpp"
#include "expression_stream.hpp"
#include "../numeric.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::bitwise_or_expression is the bitwise or expression.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/bitwise_or_expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks The xtd::expressions::bitwise_or_expression struct is used by xtd::expressions::operator |().
    /// @par Examples
    /// The following example shows how to use xtd::expressions::bitwise_or_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   //auto bit_or1 = [](auto&& _) {return _ | 0x0F;};
    ///   auto bit_or1 = _ | 0x0F;
    ///   println("bit_or1 result => {}", bit_or1(42));
    ///   //auto bit_or2 = [](auto&& _1, auto&& _2) {return _1 | _2;};
    ///   auto bit_or2 = _1 | _2;
    ///   println("bit_or2 result => {}", bit_or2(42, 0xF0));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // bit_or1 result => 47
    /// // bit_or2 result => 250
    /// ```
    template <typename left_t, typename right_t>
    struct bitwise_or_expression : expression {
      /// @name Public Fields
      
      /// @{
      /// @brief The operator precedence. That contains one of xtd::expressions::operator_precedence values.
      static constexpr operator_precedence precedence = operator_precedence::bitwise_or;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::bitwise_or_expression object with specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      constexpr bitwise_or_expression(left_t left, right_t right) : left {std::move(left)}, right {std::move(right)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Bitwise or the specified arguments.
      /// @param args the arguments to bitwise or.
      /// @return The result of bitwise or.
      template <typename... args_t>
      constexpr auto operator()(args_t&&... args) const {
        auto&& l = left(std::forward<args_t>(args)...);
        auto&& r = right(std::forward<args_t>(args)...);
        using result_t = std::decay_t<decltype(l & r)>;
        if constexpr (xtd::numeric<result_t>) return static_cast<result_t>(l | r);
        else return l | r;
      }
      /// @}
      
      /// @cond
      friend inline auto operator <<(std::ostream& os, const bitwise_or_expression& e) -> std::ostream& {return os << expression_stream {e.left, e.precedence} << " | " << expression_stream {e.right, e.precedence};}
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
    /// @return The result of bitwise or.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/bitwise_or_expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::bitwise_or_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   //auto bit_or1 = [](auto&& _) {return _ | 0x0F;};
    ///   auto bit_or1 = _ | 0x0F;
    ///   println("bit_or1 result => {}", bit_or1(42));
    ///   //auto bit_or2 = [](auto&& _1, auto&& _2) {return _1 | _2;};
    ///   auto bit_or2 = _1 | _2;
    ///   println("bit_or2 result => {}", bit_or2(42, 0xF0));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // bit_or1 result => 10
    /// // bit_or2 result => 8
    /// ```
    template <typename left_t, typename right_t>
    requires expression_operand<left_t> || expression_operand<right_t>
    constexpr auto operator |(left_t left, right_t right) {
      auto left_expression = as_expression(left);
      auto right_expression = as_expression(right);
      return bitwise_or_expression<std::decay_t<decltype(left_expression)>, std::decay_t<decltype(right_expression)>> {std::move(left_expression), std::move(right_expression)};
    }
    /// @}
  }
}

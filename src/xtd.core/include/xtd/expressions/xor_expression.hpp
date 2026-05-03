/// @file
/// @brief Contains xtd::expressions::xor_expression operator.
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
    /// @brief The xtd::expressions::xor_expression is the bitwise xor expression.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/xor_expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::xor_expression struct is used by xtd::expressions::expression::xor_ expression.
    /// @par Examples
    /// The following example shows how to use xtd::expressions::xor_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   //auto bit_xor1 = [](auto&& _) {return _ ^ 0x0F;};
    ///   auto bit_xor1 = _ ^ 0x0F;
    ///   println("bit_xor1 result => {}", bit_xor1(42));
    ///   //auto bit_xor2 = [](auto&& _1, auto&& _2) {return _1 ^ _2;};
    ///   auto bit_xor2 = _1 ` _2;
    ///   println("bit_xor2 result => {}", bit_xor2(42, 0xF0));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // bit_xor1 result => 37
    /// // bit_xor2 result => 218
    /// ```
    template <typename left_t, typename right_t>
    struct xor_expression : binary_expression {
      /// @name Public Fields
      
      /// @{
      /// @brief The operator precedence. That contains one of xtd::expressions::operator_precedence values.
      static constexpr operator_precedence precedence = operator_precedence::bitwise_xor;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::xor_expression object.
      constexpr xor_expression() = default;
      
      /// @brief Initialize a new xtd::expressions::xor_expression object with specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      constexpr xor_expression(left_t left, right_t right) : left {std::move(left)}, right {std::move(right)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Bitwise xor the specified arguments.
      /// @param args the arguments to bitwise xor.
      /// @return The result of xor.
      template <typename... args_t>
      constexpr auto operator()(args_t&&... args) const {
        auto&& l = left(std::forward<args_t>(args)...);
        auto&& r = right(std::forward<args_t>(args)...);
        using result_t = std::decay_t<decltype(l & r)>;
        if constexpr (xtd::numeric<result_t>) return static_cast<result_t>(l ^ r);
        else return l ^ r;
      }
      /// @}
      
      /// @cond
      friend inline auto operator <<(std::ostream& os, const xor_expression& e) -> std::ostream& {return os << expression_stream {e.left, e.precedence} << " ^ " << expression_stream {e.right, e.precedence};}
      /// @endcond

    private:
      [[no_unique_address]] left_t left;
      [[no_unique_address]] right_t right;
    };
    
    /// @cond
    template <typename left_t, typename right_t>
    requires std::is_base_of_v<expression, std::decay_t<left_t>> || std::is_base_of_v<expression, std::decay_t<right_t>>
    constexpr auto expression::xor_(left_t left, right_t right) {
      auto left_expression = as_expression(left);
      auto right_expression = as_expression(right);
      return xor_expression<std::decay_t<decltype(left_expression)>, std::decay_t<decltype(right_expression)>> {std::move(left_expression), std::move(right_expression)};
    }
    /// @endcond

    /// @name Public Operators
    
    /// @{
    /// @brief Subtract the specified left and right operands.
    /// @param left The left operand.
    /// @param right The right operand.
    /// @return The result of bitwise xor.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/xor_expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::expression::xor_.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   // auto or1 = [](auto&& _) {return _ ^ 0x0F;};
    ///   auto xor1 = _ ^ 0x0F;
    ///   println("xor1 result => {:B}", xor1(42));
    ///   auto xor2 = expression::xor_(_, 0x0F);
    ///   println("xor2 result => {:B}", xor2(42));
    ///   println();
    ///   // auto xor3 = [](auto&& _1, auto&& _2) {return _1 ^ _2;};
    ///   auto xor3 = _1 ^ _2;
    ///   println("xor3 result => {:B}", xor3(42, 0xF0));
    ///   auto xor4 = expression::xor_(_1, _2);
    ///   println("xor4 result => {:B}", xor4(42, 0xF0));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // xor1 result => 100101
    /// // xor2 result => 100101
    /// //
    /// // xor3 result => 11010010
    /// // xor4 result => 11010010
    /// ```
    template <typename left_t, typename right_t>
    requires expression_operand<left_t> || expression_operand<right_t>
    constexpr auto operator ^(left_t left, right_t right) {return expression::xor_(std::move(left), std::move(right));}
    /// @}
  }
}

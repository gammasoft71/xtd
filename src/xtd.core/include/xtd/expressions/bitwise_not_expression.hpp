/// @file
/// @brief Contains xtd::expressions::bitwise_not_expression operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "expression_operand.hpp"
#include "../numeric.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::bitwise_not_expression is the bitwise not expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::bitwise_not_expression struct is used by xtd::expressions::operator ~().
    /// @par Examples
    /// The following example shows how to use xtd::expressions::bitwise_not_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   //auto bit_not1 = [](auto _) {return static_cast<decltype(_)>(~_);};
    ///   auto bit_not1 = ~_;
    ///   println("bit_not1 result => 0b{:B}", bit_not1(42_u8));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // bit_not1 result => 0b11010101
    /// ```
    template <typename value_t>
    struct bitwise_not_expression : expression_base {
      static constexpr operator_precedence precedence = operator_precedence::bitwise_not;
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::bitwise_not_expression object with specified value operand.
      /// @param value The value operand.
      constexpr bitwise_not_expression(value_t value) : value {std::move(value)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Add the specified arguments.
      /// @param args the arguments to add.
      /// @return The result of bitwise not.
      template <typename... args_t>
      constexpr auto operator()(args_t&&... args) const {
        auto&& v = value(std::forward<args_t>(args)...);
        using result_t = std::decay_t<decltype(v)>;
        if constexpr (xtd::numeric<result_t>) return static_cast<result_t>(~v);
        else return ~v;
      }
      /// @}
      
      /// @cond
      friend inline auto operator <<(std::ostream& os, const bitwise_not_expression& e) -> std::ostream& {
        os << "~";
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
    /// @return The result of bitwise not.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::bitwise_not_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   //auto bit_not1 = [](auto _) {return static_cast<decltype(_)>(~_);};
    ///   auto bit_not1 = ~_;
    ///   println("bit_not1 result => 0b{:B}", bit_not1(42_u8));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // bit_not1 result => 0b11010101
    /// ```
    template <typename value_t>
    requires expression_operand<value_t>
    constexpr auto operator ~(value_t value) {
      auto expression = as_expression(value);
      return bitwise_not_expression<std::decay_t<decltype(expression)>> {std::move(expression)};
    }
    /// @}
  }
}

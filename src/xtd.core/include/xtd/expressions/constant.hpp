/// @file
/// @brief Contains xtd::expressions::constant struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "constant_expression.hpp"
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::constant is the constant wrapper.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/constant>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @par Examples
    /// The following example shows how to use xtd::expressions::expression::constant.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   // auto constant1 = [] {return 10;};
    ///   auto constant1 =  constant {10};
    ///   println("constant1 result => {}", constant1());
    ///   auto constant2 =  expression::constant(10);
    ///   println("constant2 result => {}", constant2());
    ///   auto value = 30;
    ///   //auto constant3 = [value] {return value;};
    ///   auto constant3 =  constant {value};
    ///   println("constant3 result => {}", constant3());
    ///   auto constant4 =  expression::constant(value);
    ///   println("constant4 result => {}", constant4());
    ///   println();
    ///   //auto expr1 = [value] {return 20 + value;};
    ///   auto expr1 = constant {20} + expression::constant(value);
    ///   println("expr1 result => {}", expr1());
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // constant1 result => 10
    /// // constant2 result => 10
    /// // constant3 result => 30
    /// // constant4 result => 30
    /// //
    /// // expr1 result => 50
    /// ```
    template <typename type_t>
    struct constant : constant_expression {
      /// @name Public Fields
      
      /// @{
      /// @brief The operator precedence. That contains one of xtd::expressions::operator_precedence values.
      static constexpr operator_precedence precedence = operator_precedence::constant;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::constant object with specified constant value.
      /// @param value The constant value.
      constexpr constant(type_t value) : value_ {std::move(value)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Gets the constant value.
      /// @return The constant value.
      template <typename... args_t>
      constexpr auto operator()(args_t&&...) const {return value_;}
      /// @}

      /// @cond
      friend auto operator <<(std::ostream& os, constant c) -> std::ostream& {return os << c.value_;}
      /// @endcond
      
    private:
      [[no_unique_address]] type_t value_;
    };
    
    /// @cond
    template <typename type_t>
    constexpr auto expression::constant(type_t value) {return xtd::expressions::constant {std::move(value)};}
    /// @endcond
  }
}

/// @file
/// @brief Contains xtd::expressions::value struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "value_expression.hpp"
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::value is the value wrapper.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/value>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @par Examples
    /// The following example shows how to use xtd::expressions::expression::value.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   // auto value1 = [] {return 10;};
    ///   auto value1 =  value {10};
    ///   println("value1 result => {}", value1());
    ///   auto value2 =  expression::value(10);
    ///   println("value2 result => {}", value2());
    ///   auto value = 30;
    ///   //auto value3 = [value] {return value;};
    ///   auto value3 =  value {value};
    ///   println("value3 result => {}", value3());
    ///   auto value4 =  expression::value(value);
    ///   println("value4 result => {}", value4());
    ///   println();
    ///   //auto expr1 = [value] {return 20 + value;};
    ///   auto expr1 = value {20} + expression::value(value);
    ///   println("expr1 result => {}", expr1());
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // value1 result => 10
    /// // value2 result => 10
    /// // value3 result => 30
    /// // value4 result => 30
    /// //
    /// // expr1 result => 50
    /// ```
    template<typename type_t>
    struct value : value_expression {
      /// @name Public Fields
      
      /// @{
      /// @brief The operator precedence. That contains one of xtd::expressions::operator_precedence values.
      static constexpr operator_precedence precedence = operator_precedence::value;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::value object with specified value value.
      /// @param value The value value.
      constexpr value(type_t value) : value_ {std::move(value)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Gets the value value.
      /// @return The value value.
      template<typename... args_t>
      constexpr auto operator()(args_t&&...) const {return value_;}
      /// @}

      /// @cond
      friend auto operator <<(std::ostream& os, value c) -> std::ostream& {return os << c.value_;}
      /// @endcond
      
    private:
      [[no_unique_address]] type_t value_;
    };
    
    /// @cond
    template<typename type_t>
    constexpr auto expression::value(type_t value) {return xtd::expressions::value {std::move(value)};}
    /// @endcond
  }
}

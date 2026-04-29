/// @file
/// @brief Contains xtd::expressions::expression struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "operator_precedence.hpp"
#include "../type_of.hpp"
#include <concepts>
#include <ostream>
#include <type_traits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief Provides the base class from which the classes that represent expression tree nodes are derived. It also contains static factory methods to create the various node types. This is an abstract class.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shos how to use xtd::expressions::expression class.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   auto value = 30;
    ///   auto expr1 = (_1 + _2) * value;
    ///   println("expr1 resutl = {}", expr1(10, 20));
    ///   println("expr1 = {}", expr1);
    ///   println("type_of(expr1) = {}", type_of(expr1));
    ///
    ///   println();
    ///   auto expr2 = expression::multiply(expression::add(_1, _2), value);
    ///   println("expr2 resutl = {}", expr2(10, 20));
    ///   println("expr2 = {}", expr2);
    ///   println("type_of(expr2) = {}", type_of(expr2));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // expr1 resutl = 900
    /// // expr1 = (_1 + _2) * 30
    /// // type_of(expr1) = xtd::expressions::multiply_expression<xtd::expressions::add_expression<xtd::expressions::placeholder<0ul>, xtd::expressions::placeholder<1ul>>, xtd::expressions::constant<int>>
    /// //
    /// // expr2 resutl = 900
    /// // expr2 = (_1 + _2) * 30
    /// // type_of(expr2) = xtd::expressions::multiply_expression<xtd::expressions::add_expression<xtd::expressions::placeholder<0ul>, xtd::expressions::placeholder<1ul>>, xtd::expressions::constant<int>>
    /// ```
    struct expression {
      /// @name Public Static Methods
      
      /// @{
      template <typename left_t, typename right_t>
      requires std::is_base_of_v<expression, std::decay_t<left_t>> || std::is_base_of_v<expression, std::decay_t<right_t>>
      static constexpr auto add(left_t left, right_t right);
      
      template <typename left_t, typename right_t>
      requires std::is_base_of_v<expression, std::decay_t<left_t>> || std::is_base_of_v<expression, std::decay_t<right_t>>
      static constexpr auto multiply(left_t left, right_t right);
      /// @}

    protected:
      /// @name Protected Constructors
      
      /// @{
      expression() = default;
      /// @}
    };
    
    /// @cond
    template<typename type_t>
    requires std::is_base_of_v<expression, std::decay_t<type_t>>
    auto operator <<(std::ostream& os, const type_t& e) -> std::ostream& {return os << type_of(e);}
    /// @endcond
  }
}


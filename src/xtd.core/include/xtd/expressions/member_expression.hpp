/// @file
/// @brief Contains xtd::expressions::member bind operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "expression_operand.hpp"
#include "expression_stream.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::member_type contains the member type.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::member_type struct is used by xtd::expressions::member.
    template <typename member_t>
    struct member_type {
      const char* name = nullptr;
      member_t member;
    };
    
    /// @brief The xtd::expressions::member is use to bind object member.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::member mzthod is used by xtd::expressions::operator ^().
    template <typename member_t>
    constexpr auto member(member_t member) {
      return member_type<member_t>{"<member>", member};
    }
    /// @brief The xtd::expressions::member is use to bind object member.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::member mzthod is used by xtd::expressions::operator ^().
    template <typename member_t>
    constexpr auto member(const char* name, member_t member) {
      return member_type<member_t>{name, member};
    }
    
    /// @brief The xtd::expressions::as_expression method convert a type as xtd::expressions::expression or xtd::expressions::constant.
    /// @param value The value to convert.
    /// @raturn The result as xtd::expressions::expression or xtd::expressions::constant.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::as_expression method is used by xtd::expressions operators.
    template <typename expression_t, typename member_t>
    struct member_expression : expression {
      /// @name Public Fields
      
      /// @{
      /// @brief The operator precedence. That contains one of xtd::expressions::operator_precedence values.
      static constexpr operator_precedence precedence = operator_precedence::member_access;
      /// @}

      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::addition_expression object with specified expression and member operands.
      /// @param expression The expression operand.
      /// @param member The member operand.
      constexpr member_expression(expression_t expression, member_t member) : expression {std::move(expression)}, member {std::move(member)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Add the specified arguments.
      /// @param args the arguments to add.
      /// @return The result of member.
      constexpr decltype(auto) operator()(auto&&... args) const {
        auto&& obj = expression(std::forward<decltype(args)>(args)...);
        if constexpr (std::is_pointer_v<std::decay_t<decltype(obj)>>) return (obj->*member.member);
        else return (obj.*member.member);
      }
      
      /// @cond
      friend inline auto operator <<(std::ostream& os, const member_expression& e) -> std::ostream& {return os << expression_stream {e.expression, e.precedence} << "." << e.member.name;}
      /// @endcond

    private:
      [[no_unique_address]] expression_t expression;
      [[no_unique_address]] member_t member;
    };
    
    /// @name Public Operators
    
    /// @{
    /// @brief Bind member operator.
    /// @param expression The expression that associate to the  binded member.
    /// @param member The binded mehtod to execute.
    /// @return The result of the binded member.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::not_equal_to_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   struct foo {
    ///     int value;
    ///   };
    ///
    ///   auto mem1 = _*member(&foo::value);
    ///   println("mem1 result => {}", mem1(foo {42}));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // mem1 result => 42
    /// ```
    template <typename expression_t, typename member_t>
    requires expression_operand<expression_t> || expression_operand<member_type<member_t>>
    constexpr auto operator *(expression_t expression, member_type<member_t> member) {
      auto expr = as_expression(expression);
      return member_expression<std::decay_t<decltype(expr)>, member_type<member_t>> {std::move(expr), std::move(member)};
    }

    /// @brief Bind member operator.
    /// @param expression The expression that associate to the  binded member.
    /// @param member The binded mehtod to execute.
    /// @return The result of the binded member.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::not_equal_to_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   struct foo {
    ///     int value;
    ///   };
    ///
    ///   auto mem1 = _ | member(&foo::value);
    ///   println("mem1 result => {}", mem1(foo {42}));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // mem1 result => 42
    /// ```
    template <typename expression_t, typename member_t>
    requires expression_operand<expression_t> || expression_operand<member_type<member_t>>
    constexpr auto operator |(expression_t expression, member_type<member_t> member) {
      return std::forward<expression_t>(expression) * std::forward<member_type<member_t>>(member);
    }
    /// @}
  }
}

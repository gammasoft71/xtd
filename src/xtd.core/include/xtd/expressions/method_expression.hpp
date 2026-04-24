/// @file
/// @brief Contains xtd::expressions::method bind operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "expression_operand.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::method_type contains the method type.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::method_type struct is used by xtd::expressions::method.
    template <typename method_t, typename... args_t>
    struct method_type {
      const char* name = nullptr;
      method_t method;
      std::tuple<args_t...> args;
    };
    
    /// @brief The xtd::expressions::method is use to bind object method.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::method mzthod is used by xtd::expressions::operator ^().
    template <typename method_t, typename... args_t>
    constexpr auto method(method_t method, args_t&&... args) {
      return method_type<method_t, decltype(as_expression(std::forward<args_t>(args)))...>{nullptr, method, std::make_tuple(as_expression(std::forward<args_t>(args))...)};
    }
    /// @brief The xtd::expressions::method is use to bind object method.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::method mzthod is used by xtd::expressions::operator ^().
    template <typename method_t, typename... args_t>
    constexpr auto method(const char* name, method_t method, args_t&&... args) {
      return method_type<method_t, decltype(as_expression(std::forward<args_t>(args)))...>{name, method, std::make_tuple(as_expression(std::forward<args_t>(args))...)};
    }

    /// @brief The xtd::expressions::as_expression method convert a type as xtd::expressions::expression_base or xtd::expressions::constant.
    /// @param value The value to convert.
    /// @raturn The result as xtd::expressions::expression_base or xtd::expressions::constant.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::as_expression method is used by xtd::expressions operators.
    template <typename expression_t, typename method_t>
    struct method_expression : expression_base {
      static constexpr operator_precedence precedence = operator_precedence::member_access;
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::addition_expression object with specified expression and method operands.
      /// @param expression The expression operand.
      /// @param method The method operand.
      constexpr method_expression(auto&& expression, auto&& method) : expression {std::forward<decltype(expression)>(expression)}, method {std::forward<decltype(method)>(method)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Add the specified arguments.
      /// @param args the arguments to add.
      /// @return The result of addition.
      template <typename... call_args_t>
      constexpr decltype(auto) operator()(call_args_t&&... call_args) const {
        auto&& obj = expression(std::forward<call_args_t>(call_args)...);
        auto invoke = [&](auto&&... evaluated_args) -> decltype(auto) {
          if constexpr (std::is_pointer_v<std::decay_t<decltype(obj)>>) return (obj->*method.method)(std::forward<decltype(evaluated_args)>(evaluated_args)...);
          else return (obj.*method.method)(std::forward<decltype(evaluated_args)>(evaluated_args)...);
        };
        auto eval_arg = [&](auto&& expr) -> decltype(auto) {return expr(std::forward<call_args_t>(call_args)...);};
        return std::apply([&](auto&&... exprs) -> decltype(auto) {return invoke(eval_arg(exprs)...);}, method.args);
      }
      /// @}
      
      /// @cond
      friend inline auto operator <<(std::ostream& os, const method_expression& e) -> std::ostream& {
        print_with_parens(os, e.expression, e.precedence);
        os << "." << (e.method.name != nullptr ? e.method.name : type_of(e.method.method).full_name().c_str()) << "(";
        std::apply([&os](auto&&... args) {
          bool first = true;
          ((os << (first ? "" : ", "), os << args, first = false), ...);
        }, e.method.args);
        os << ")";
        return os;
      }
      /// @endcond

    private:
      expression_t expression;
      method_t method;
    };

    /// @name Public Operators
    
    /// @{
    /// @brief Bind method operator.
    /// @param expression The expression that associate to the  binded method.
    /// @param method The binded mehtod to execute.
    /// @return The result of the binded method.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::not_equal_to_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   auto fct1 = _*method(&string::to_upper);
    ///   println("fct1 result => {}", fct1("Hello"_s));
    ///   auto fct2 = _*method(overload<usize, usize>{}(&string::substring), 7, 6);
    ///   println("fct2 result => {}", fct2("Hello, World!"_s));
    ///   auto fct3 = _1*method(overload<usize, usize>{}(&string::substring), _2, _3);
    ///   println("fct3 result => {}", fct3("Hello, World!"_s, 7, 6));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // fct1 result => HELLO
    /// // fct2 result => World!
    /// // fct3 result => World!
    /// ```
    template <typename expression_t, typename method_t, typename... stored_args_t>
    requires expression_operand<expression_t, method_type<method_t, stored_args_t...>>
    constexpr auto operator*(expression_t expression, method_type<method_t, stored_args_t...> method) {
      return method_expression<decltype(as_expression(expression)), method_type<method_t, stored_args_t...>>{as_expression(expression), method};
    }
    
    /// @brief Bind method alternative operator.
    /// @param expression The expression that associate to the  binded method.
    /// @param method The binded mehtod to execute.
    /// @return The result of the binded method.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::not_equal_to_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   auto fct1 = _ | method(&string::to_upper);
    ///   println("fct1 result => {}", fct1("Hello"_s));
    ///   auto fct2 = _ | method(overload<usize, usize>{}(&string::substring), 7, 6);
    ///   println("fct2 result => {}", fct2("Hello, World!"_s));
    ///   auto fct3 = _1 | method(overload<usize, usize>{}(&string::substring), _2, _3);
    ///   println("fct3 result => {}", fct3("Hello, World!"_s, 7, 6));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // fct1 result => HELLO
    /// // fct2 result => World!
    /// // fct3 result => World!
    /// ```
    template <typename expression_t, typename method_t, typename... stored_args_t>
    requires expression_operand<expression_t, method_type<method_t, stored_args_t...>>
    constexpr auto operator |(expression_t expression, method_type<method_t, stored_args_t...> method) {
      return std::forward<expression_t>(expression) * std::forward<method_type<method_t, stored_args_t...>>(method);
    }
    /// @}
  }
}

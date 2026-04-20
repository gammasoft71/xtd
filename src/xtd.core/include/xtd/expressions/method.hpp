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
      return method_type<method_t, std::decay_t<args_t>...> {method, std::tuple<std::decay_t<args_t>...>(std::forward<args_t>(args)...)};
    }
    
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
    ///   auto fct1 = _^method(&string::to_upper);
    ///   println("fct1 result => {}", fct1("Hello"_s));
    ///   auto fct2 = _^method(overload<usize, usize>{}(&string::substring), 7, 6);
    ///   println("fct2 result => {}", fct2("Hello, World!"_s));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // fct1 result => HELLO
    /// // fct2 result => World!
    /// ```
    template <typename expression_t, typename method_t, typename... stored_args_t>
    constexpr auto operator ^(expression_t expression, method_type<method_t, stored_args_t...> method) {
      return [=](auto&&... call_args) {
        auto&& obj = expression(std::forward<decltype(call_args)>(call_args)...);
        auto invoke = [&](auto&&... unpacked_args) {
          if constexpr (std::is_pointer_v<std::decay_t<decltype(obj)>>) return (obj->*method.method)(std::forward<decltype(unpacked_args)>(unpacked_args)...);
          else return (obj.*method.method)(std::forward<decltype(unpacked_args)>(unpacked_args)...);
        };
        return std::apply(invoke, method.args);
      };
    }    /// @}
  }
}

/// @file
/// @brief Contains xtd::expressions::placeholder struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "operator_precedence.hpp"
#include "placeholder_expression.hpp"
#include <concepts>
#include <ostream>
#include <tuple>
#include <type_traits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::placeholder object is placeholder for all expressions.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/placeholder>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks Prefer the xtd::expressions::arg <N> or xtd::expressions::_, xtd::expressions::_1 ... xtd::expressions::_10 instead xtd::expressions::placeholder.
    /// @par Examples
    /// The following example shows how to use xtd::expressions::expression::placeholder.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   // auto placeholder1 = [](auto&& _) {return _;};
    ///   auto placeholder1 = _;
    ///   println("placeholder1 result => {}", placeholder1(10));
    ///   auto placeholder2 = _1;
    ///   println("placeholder2 result => {}", placeholder2(10));
    ///   auto placeholder3 = placeholder<0> {};
    ///   println("placeholder3 result => {}", placeholder3(10));
    ///   auto placeholder4 = expression::placeholder<0>();
    ///   println("placeholder4 result => {}", placeholder4(10));
    ///   println();
    ///   // auto expr1 = [](auto&& _1, auto&& _2, auto&& _3) {return _1 + _2 + _3;};
    ///   auto expr1 = _1 + placeholder<1> {} + expression::placeholder<2>();
    ///   println("expr1 result => {}", expr1(10, 20, 30));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // placeholder1 result => 10
    /// // placeholder2 result => 10
    /// // placeholder3 result => 10
    /// // placeholder4 result => 10
    /// //
    /// // expr1 result => 60
    /// ```
    template <size_t index>
    struct placeholder : placeholder_expression {
      /// @name Public Fields
      
      /// @{
      /// @brief The operator precedence. That contains one of xtd::expressions::operator_precedence values.
      static constexpr operator_precedence precedence = operator_precedence::placeholder;
      /// @}

      /// @name Public Constructors
      
      /// @{
      placeholder() = default;
      /// @}

      /// @name Public Operators
      
      /// @{
      /// @brief Gets the placeholder value.
      /// @return The placeholder value.
      template <typename... args_t>
      constexpr decltype(auto) operator()(args_t&&... args) const {
        return std::get<index>(std::forward_as_tuple(std::forward<args_t>(args)...));
      }
      /// @}
    };

    /// @cond
    template <size_t index>
    constexpr auto expression::placeholder() {return xtd::expressions::placeholder<index> {};}

    template <size_t index>
    inline auto operator <<(std::ostream& os, const placeholder<index>&) -> std::ostream& {return os << "_" << (index + 1);}
    /// @endcond
  }
}

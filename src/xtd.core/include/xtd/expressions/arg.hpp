/// @file
/// @brief Contains xtd::expressions::arg struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "operator_precedence.hpp"
#include "argument_expression.hpp"
#include <concepts>
#include <ostream>
#include <tuple>
#include <type_traits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::arg object is arg for all expressions.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/arg>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks Prefer the xtd::expressions::arg <N> or xtd::expressions::_, xtd::expressions::_1 ... xtd::expressions::_10 instead xtd::expressions::arg.
    /// @par Examples
    /// The following example shows how to use xtd::expressions::expression::arg.
    /// @include arg_expression.cpp
    template <size_t index>
    struct argument : argument_expression {
      /// @name Public Fields
      
      /// @{
      /// @brief The operator precedence. That contains one of xtd::expressions::operator_precedence values.
      static constexpr operator_precedence precedence = operator_precedence::arg;
      /// @}

      /// @name Public Constructors
      
      /// @{
      argument() = default;
      /// @}

      /// @name Public Operators
      
      /// @{
      /// @brief Gets the arg value.
      /// @return The arg value.
      template<typename... args_t>
      constexpr decltype(auto) operator()(args_t&&... args) const {
        return std::get<index - 1>(std::forward_as_tuple(std::forward<args_t>(args)...));
      }
      /// @}
    };

    /// @brief Gets the `index` argument used by expression.
    /// ```cpp
    /// #include <xtd/expressions/arg>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The index start from 1 to N.
    /// @remarks Prefer the xtd::expressions::expression::arg <N> or xtd::expressions::_, xtd::expressions::_1 ... xtd::expressions::_10 instead xtd::expressions::expression::argument<N> {}.
    /// @par Examples
    /// The following example shows how to use xtd::expressions::expression::arg.
    /// @include arg_expression.cpp
    template <size_t index>
    constexpr argument<index> arg;

    /// @cond
    template <size_t index>
    const argument<index> expression::arg;
    
    template <size_t index>
    inline auto operator <<(std::ostream& os, const argument<index>&) -> std::ostream& {return os << "_" << index;}
    /// @endcond
  }
}

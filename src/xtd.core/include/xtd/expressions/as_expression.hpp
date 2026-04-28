/// @file
/// @brief Contains xtd::expressions::as_expression methods.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "args.hpp"
#include "constant.hpp"
#include "expression_operand.hpp"
#include "../usize.hpp"
#include <type_traits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @name Public Functions
    
    /// @{
    /// @brief The xtd::expressions::as_expression method convert a type as xtd::expressions::expression.
    /// @param value The value to convert.
    /// @raturn The result as xtd::expressions::expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::as_expression method is used by xtd::expressions operators.
    template <typename type_t>
    requires expression_operand<type_t>
    constexpr decltype(auto) as_expression(type_t&& value) {
      return std::forward<type_t>(value);
    }
    /// @brief The xtd::expressions::as_expression method convert a type as xtd::expressions::constant.
    /// @param value The value to convert.
    /// @raturn The result as xtd::expressions::constant.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::as_expression method is used by xtd::expressions operators.
    template <typename type_t>
    requires (!expression_operand<type_t>)
    constexpr auto as_expression(type_t&& value) {
      return constant<std::decay_t<type_t>> {std::forward<type_t>(value)};
    }
    /// @}
  }
}

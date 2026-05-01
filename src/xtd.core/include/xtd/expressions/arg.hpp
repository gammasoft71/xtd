/// @file
/// @brief Contains xtd::expressions::arg variable.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "placeholder.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @cond
    template <size_t index>
    constexpr auto expression::arg() {return xtd::expressions::placeholder<index - 1> {};}
    /// @endcond
    
    /// @name Public Variables
    
    /// @{
    /// @brief The xtd::expressions::arg instance is the `index` argument used by expression.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/arg>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The index start from 1 to N.
    /// @par Examples
    /// ```cpp
    /// auto expr = arg<1> + arg<2> + arg<3> + arg<4> + arg<5>;
    /// println("expr result => {}", expr(10, 20, 30, 40, 50)); // expr result => 150
    /// ```
    template <size_t index>
    inline constexpr xtd::expressions::placeholder<index - 1> arg {};
    /// @}
  }
}

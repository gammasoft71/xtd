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
    /// The following example shows how to use xtd::expressions::expression::arg.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   // auto placeholder1 = [](auto&& _) {return _;};
    ///   auto arg1 = _;
    ///   println("arg1 result => {}", arg1(10));
    ///   auto arg2 = _1;
    ///   println("arg2 result => {}", arg2(10));
    ///   auto arg3 = arg<1> {};
    ///   println("arg3 result => {}", arg3(10));
    ///   auto arg4 = expression::arg<1>();
    ///   println("arg4 result => {}", arg4(10));
    ///   println();
    ///   // auto expr1 = [](auto&& _1, auto&& _2, auto&& _3) {return _1 + _2 + _3;};
    ///   auto expr1 = _1 + arg<2> + expression::arg<3>();
    ///   println("expr1 result => {}", expr1(10, 20, 30));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // arg1 result => 10
    /// // arg2 result => 10
    /// // arg3 result => 10
    /// // arg4 result => 10
    /// //
    /// // expr1 result => 60
    /// ```
    template <size_t index>
    inline constexpr xtd::expressions::placeholder<index - 1> arg {};
    /// @}
  }
}

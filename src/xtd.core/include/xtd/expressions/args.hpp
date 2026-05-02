/// @file
/// @brief Contains xtd::expressions::_ and xtd::expressions::_1 ... xtd::expressions::_10 variables.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "arg.hpp"
#include "placeholders.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief Generates a set of positional placeholders that can be decomposed using structured bindings to build readable and composable expression templates.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/args>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::expression::args.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   //auto expr1 = [](auto&& operand_one, auto&& operand_two) {return operand_one + operand_two;};
    ///   auto [operand_one, operand_two] = args<2>();
    ///   auto expr1 = operand_one + operand_two;
    ///   println("expr1 result => {}", expr1(10, 20));
    ///   auto expr2 = _1 + _2;
    ///   println("expr2 result => {}", expr2(10, 20));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // expr1 result => 30
    /// // expr2 result => 30
    /// ```
    template <size_t count>
    constexpr auto args() {
      return xtd::expressions::placeholders<count> {};
    }

    /// @name Public Variables
    
    /// @{
    /// @brief The xtd::expressions::_ placeholder instance is used by expression that have only one argument.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/args>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::_ is an alias on xtd::expressions::arg<1>
    /// @par Examples
    /// ```cpp
    /// auto expr = _ + _;
    /// println("expr result => {}", expr(10); // expr result => 20
    /// ```
    inline constexpr auto _ = xtd::expressions::arg<1>;

    /// @brief The xtd::expressions::_1 placeholder instance is first argument used by expression.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/args>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::_1 is an alias on xtd::expressions::arg<1>
    /// @remarks xtd::expressions contains the first ten entries from xtd::expressions::placeholder. If you need an eleventh entry or more, you can define them yourself as follows:
    /// ```cpp
    /// inline constexpr auto _11 = xtd::expressions::arg<11>;
    /// inline constexpr auto _12 = xtd::expressions::arg<12>;
    /// //...
    /// inline constexpr auto _100 = xtd::expressions::arg<100>;
    /// //...
    /// ```
    /// @par Examples
    /// ```cpp
    /// auto expr = _1 + _1;
    /// println("expr result => {}", expr(10)); // expr result => 20
    /// ```
    inline constexpr auto _1 = xtd::expressions::arg<1>;
    /// @brief The xtd::expressions::_2 placeholder instance is second argument used by expression.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/args>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::_2 is an alias on xtd::expressions::arg<1>
    /// @remarks xtd::expressions contains the first ten entries from xtd::expressions::placeholder. If you need an eleventh entry or more, you can define them yourself as follows:
    /// ```cpp
    /// inline constexpr auto _11 = xtd::expressions::arg<11>;
    /// inline constexpr auto _12 = xtd::expressions::arg<12>;
    /// //...
    /// inline constexpr auto _100 = xtd::expressions::arg<100>;
    /// //...
    /// ```
    /// @par Examples
    /// ```cpp
    /// auto expr = _1 + _2;
    /// println("expr result => {}", expr(10, 20)); // expr result => 30
    /// ```
    inline constexpr auto _2 = xtd::expressions::arg<2>;
    /// @brief The xtd::expressions::_3 placeholder instance is third argument used by expression.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/args>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::_3 is an alias on xtd::expressions::arg<3>
    /// @remarks xtd::expressions contains the first ten entries from xtd::expressions::placeholder. If you need an eleventh entry or more, you can define them yourself as follows:
    /// ```cpp
    /// inline constexpr auto _11 = xtd::expressions::arg<11>;
    /// inline constexpr auto _12 = xtd::expressions::arg<12>;
    /// //...
    /// inline constexpr auto _100 = xtd::expressions::arg<100>;
    /// //...
    /// ```
    /// @par Examples
    /// ```cpp
    /// auto expr = _1 + _2 + _3;
    /// println("expr result => {}", expr(10, 20, 30)); // expr result => 60
    /// ```
    inline constexpr auto _3 = xtd::expressions::arg<3>;
    /// @brief The xtd::expressions::_4 placeholder instance is fourth argument used by expression.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/args>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::_4 is an alias on xtd::expressions::arg<4>
    /// @remarks xtd::expressions contains the first ten entries from xtd::expressions::placeholder. If you need an eleventh entry or more, you can define them yourself as follows:
    /// ```cpp
    /// inline constexpr auto _11 = xtd::expressions::arg<11>;
    /// inline constexpr auto _12 = xtd::expressions::arg<12>;
    /// //...
    /// inline constexpr auto _100 = xtd::expressions::arg<100>;
    /// //...
    /// ```
    /// @par Examples
    /// ```cpp
    /// auto expr = _1 + _2 + _3 + _4;
    /// println("expr result => {}", expr(10, 20, 30, 40)); // expr result => 100
    /// ```
    inline constexpr auto _4 = xtd::expressions::arg<4>;
    /// @brief The xtd::expressions::_5 placeholder instance is fifth argument used by expression.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/args>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::_5 is an alias on xtd::expressions::arg<5>
    /// @remarks xtd::expressions contains the first ten entries from xtd::expressions::placeholder. If you need an eleventh entry or more, you can define them yourself as follows:
    /// ```cpp
    /// inline constexpr auto _11 = xtd::expressions::arg<11>;
    /// inline constexpr auto _12 = xtd::expressions::arg<12>;
    /// //...
    /// inline constexpr auto _100 = xtd::expressions::arg<100>;
    /// //...
    /// ```
    /// @par Examples
    /// ```cpp
    /// auto expr = _1 + _2 + _3 + _4 + _5;
    /// println("expr result => {}", expr(10, 20, 30, 40, 50)); // expr result => 150
    /// ```
    inline constexpr auto _5 = xtd::expressions::arg<5>;
    /// @brief The xtd::expressions::_6 placeholder instance is sixth argument used by expression.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/args>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::_6 is an alias on xtd::expressions::arg<6>
    /// @remarks xtd::expressions contains the first ten entries from xtd::expressions::placeholder. If you need an eleventh entry or more, you can define them yourself as follows:
    /// ```cpp
    /// inline constexpr auto _11 = xtd::expressions::arg<11>;
    /// inline constexpr auto _12 = xtd::expressions::arg<12>;
    /// //...
    /// inline constexpr auto _100 = xtd::expressions::arg<100>;
    /// //...
    /// ```
    /// @par Examples
    /// ```cpp
    /// auto expr = _1 + _2 + _3 + _4 + _5 + _6;
    /// println("expr result => {}", expr(10, 20, 30, 40, 50, 60)); // expr result => 210
    /// ```
    inline constexpr auto _6 = xtd::expressions::arg<6>;
    /// @brief The xtd::expressions::_7 placeholder instance is seventh argument used by expression.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/args>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::_7 is an alias on xtd::expressions::arg<7>
    /// @remarks xtd::expressions contains the first ten entries from xtd::expressions::placeholder. If you need an eleventh entry or more, you can define them yourself as follows:
    /// ```cpp
    /// inline constexpr auto _11 = xtd::expressions::arg<11>;
    /// inline constexpr auto _12 = xtd::expressions::arg<12>;
    /// //...
    /// inline constexpr auto _100 = xtd::expressions::arg<100>;
    /// //...
    /// ```
    /// @par Examples
    /// ```cpp
    /// auto expr = _1 + _2 + _3 + _4 + _5 + _6 + _7;
    /// println("expr result => {}", expr(10, 20, 30, 40, 50, 60, 70)); // expr result => 280
    /// ```
    inline constexpr auto _7 = xtd::expressions::arg<7>;
    /// @brief The xtd::expressions::_8 placeholder instance is eighth argument used by expression.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/args>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::_8 is an alias on xtd::expressions::arg<8>
    /// @remarks xtd::expressions contains the first ten entries from xtd::expressions::placeholder. If you need an eleventh entry or more, you can define them yourself as follows:
    /// ```cpp
    /// inline constexpr auto _11 = xtd::expressions::arg<11>;
    /// inline constexpr auto _12 = xtd::expressions::arg<12>;
    /// //...
    /// inline constexpr auto _100 = xtd::expressions::arg<100>;
    /// //...
    /// ```
    /// @par Examples
    /// ```cpp
    /// auto expr = _1 + _2 + _3 + _4 + _5 + _6 + _7 + _8;
    /// println("expr result => {}", expr(10, 20, 30, 40, 50, 60, 70, 80)); // expr result => 360
    /// ```
    inline constexpr auto _8 = xtd::expressions::arg<8>;
    /// @brief The xtd::expressions::_9 placeholder instance is ninth argument used by expression.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/args>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::_9 is an alias on xtd::expressions::arg<9>
    /// @remarks xtd::expressions contains the first ten entries from xtd::expressions::placeholder. If you need an eleventh entry or more, you can define them yourself as follows:
    /// ```cpp
    /// inline constexpr auto _11 = xtd::expressions::arg<11>;
    /// inline constexpr auto _12 = xtd::expressions::arg<12>;
    /// //...
    /// inline constexpr auto _100 = xtd::expressions::arg<100>;
    /// //...
    /// ```
    /// @par Examples
    /// ```cpp
    /// auto expr = _1 + _2 + _3 + _4 + _5 + _6 + _7 + _8 + _9;
    /// println("expr result => {}", expr(10, 20, 30, 40, 50, 60, 70, 80, 90)); // expr result => 450
    /// ```
    inline constexpr auto _9 = xtd::expressions::arg<9>;
    /// @brief The xtd::expressions::_10 placeholder instance is tenth argument used by expression.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/args>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::_10 is an alias on xtd::expressions::arg<10>
    /// @remarks xtd::expressions contains the first ten entries from xtd::expressions::placeholder. If you need an eleventh entry or more, you can define them yourself as follows:
    /// ```cpp
    /// inline constexpr auto _11 = xtd::expressions::arg<11>;
    /// inline constexpr auto _12 = xtd::expressions::arg<12>;
    /// //...
    /// inline constexpr auto _100 = xtd::expressions::arg<100>;
    /// //...
    /// ```
    /// @par Examples
    /// ```cpp
    /// auto expr = _1 + _2 + _3 + _4 + _5 + _6 + _7 + _8 + _9 + _10;
    /// println("expr result => {}", expr(10, 20, 30, 40, 50, 60, 70, 80, 90, 100)); // expr result => 550
    /// ```
    inline constexpr auto _10 = xtd::expressions::arg<10>;
    /// @}
  }
}

/// @file
/// @brief Contains xtd::expressions::placeholder struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "operator_precedence.hpp"
#include "placeholder_base.hpp"
#include <concepts>
#include <ostream>
#include <tuple>
#include <type_traits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::placeholder object is placeholder for all expressions.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    template <size_t index>
    struct placeholder : placeholder_base {
      static constexpr operator_precedence precedence = operator_precedence::placeholder;

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
    inline auto operator <<(std::ostream& os, const placeholder<index>&) -> std::ostream& {return os << "_" << (index + 1);}
    /// @endcond

    /// @name Public Variables
    
    /// @{
    /// @brief The xtd::expressions::arg instance is the `index` argument used by expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The index start from 1 to N.
    /// @par Examples
    /// ```cpp
    /// auto expr = arg<1> + arg<2>;
    /// auto println("expr result => {}", expr(12 + 23)); // expr result => 35
    /// ```
    template <size_t index>
    inline constexpr xtd::expressions::placeholder<index - 1> arg {};
    
    /// @brief The xtd::expressions::_1 placeholder instance is first argument used by expression.
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
    /// ```
    /// @note Extremely deep or exponentially growing expressions may lead to very large compile-time types and excessive compilation times.
    /// @note This typically occurs with recursive expression composition patterns such as: `expr = expr * expr + constant;`
    /// @note In such cases, prefer standard C++ lambda expressions or break the expression into smaller parts.
    inline constexpr auto _1 = xtd::expressions::arg<1>;
    /// @brief The xtd::expressions::_2 placeholder instance is second argument used by expression.
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
    /// ```
    /// @note Extremely deep or exponentially growing expressions may lead to very large compile-time types and excessive compilation times.
    /// @note This typically occurs with recursive expression composition patterns such as: `expr = expr * expr + constant;`
    /// @note In such cases, prefer standard C++ lambda expressions or break the expression into smaller parts.
    inline constexpr auto _2 = xtd::expressions::arg<2>;
    /// @brief The xtd::expressions::_3 placeholder instance is third argument used by expression.
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
    /// ```
    /// @note Extremely deep or exponentially growing expressions may lead to very large compile-time types and excessive compilation times.
    /// @note This typically occurs with recursive expression composition patterns such as: `expr = expr * expr + constant;`
    /// @note In such cases, prefer standard C++ lambda expressions or break the expression into smaller parts.
    inline constexpr auto _3 = xtd::expressions::arg<3>;
    /// @brief The xtd::expressions::_4 placeholder instance is fourth argument used by expression.
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
    /// ```
    /// @note Extremely deep or exponentially growing expressions may lead to very large compile-time types and excessive compilation times.
    /// @note This typically occurs with recursive expression composition patterns such as: `expr = expr * expr + constant;`
    /// @note In such cases, prefer standard C++ lambda expressions or break the expression into smaller parts.
    inline constexpr auto _4 = xtd::expressions::arg<4>;
    /// @brief The xtd::expressions::_5 placeholder instance is fifth argument used by expression.
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
    /// ```
    /// @note Extremely deep or exponentially growing expressions may lead to very large compile-time types and excessive compilation times.
    /// @note This typically occurs with recursive expression composition patterns such as: `expr = expr * expr + constant;`
    /// @note In such cases, prefer standard C++ lambda expressions or break the expression into smaller parts.
    inline constexpr auto _5 = xtd::expressions::arg<5>;
    /// @brief The xtd::expressions::_6 placeholder instance is sixth argument used by expression.
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
    /// ```
    /// @note Extremely deep or exponentially growing expressions may lead to very large compile-time types and excessive compilation times.
    /// @note This typically occurs with recursive expression composition patterns such as: `expr = expr * expr + constant;`
    /// @note In such cases, prefer standard C++ lambda expressions or break the expression into smaller parts.
    inline constexpr auto _6 = xtd::expressions::arg<6>;
    /// @brief The xtd::expressions::_7 placeholder instance is seventh argument used by expression.
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
    /// ```
    /// @note Extremely deep or exponentially growing expressions may lead to very large compile-time types and excessive compilation times.
    /// @note This typically occurs with recursive expression composition patterns such as: `expr = expr * expr + constant;`
    /// @note In such cases, prefer standard C++ lambda expressions or break the expression into smaller parts.
    inline constexpr auto _7 = xtd::expressions::arg<7>;
    /// @brief The xtd::expressions::_8 placeholder instance is eighth argument used by expression.
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
    /// ```
    /// @note Extremely deep or exponentially growing expressions may lead to very large compile-time types and excessive compilation times.
    /// @note This typically occurs with recursive expression composition patterns such as: `expr = expr * expr + constant;`
    /// @note In such cases, prefer standard C++ lambda expressions or break the expression into smaller parts.
    inline constexpr auto _8 = xtd::expressions::arg<8>;
    /// @brief The xtd::expressions::_9 placeholder instance is ninth argument used by expression.
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
    /// ```
    /// @note Extremely deep or exponentially growing expressions may lead to very large compile-time types and excessive compilation times.
    /// @note This typically occurs with recursive expression composition patterns such as: `expr = expr * expr + constant;`
    /// @note In such cases, prefer standard C++ lambda expressions or break the expression into smaller parts.
    inline constexpr auto _9 = xtd::expressions::arg<9>;
    /// @brief The xtd::expressions::_10 placeholder instance is tenth argument used by expression.
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
    /// ```
    /// @note Extremely deep or exponentially growing expressions may lead to very large compile-time types and excessive compilation times.
    /// @note This typically occurs with recursive expression composition patterns such as: `expr = expr * expr + constant;`
    /// @note In such cases, prefer standard C++ lambda expressions or break the expression into smaller parts.
    inline constexpr auto _10 = xtd::expressions::arg<10>;

    /// @brief The xtd::expressions::_ placeholder instance is used by expression that have only one argument.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::_ is an alias on xtd::expressions::arg<1>
    inline constexpr auto _ = xtd::expressions::arg<1>;
    /// @}
  }
}

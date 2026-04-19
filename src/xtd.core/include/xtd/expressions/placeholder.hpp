/// @file
/// @brief Contains xtd::expressions::placeholder struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "placeholder_base.hpp"
#include <tuple>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::placeholder object is placeholder for all expressions.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    template <size_t index_t>
    struct placeholder : placeholder_base {
      /// @name Public Operators
      
      /// @{
      /// @brief Gets the placeholder value.
      /// @return The placeholder value.
      template <typename... args_t>
      constexpr decltype(auto) operator()(args_t&&... args) const {
        return std::get<index_t>(std::forward_as_tuple(std::forward<args_t>(args)...));
      }
      /// @}
    };

    /// @name Public Variables
    
    /// @{
    /// @brief The xtd::expressions::_1 placeholder instance is first argument used by expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks xtd::expressions contains the first ten entries from xtd::expressions::placeholder. If you need an eleventh entry or more, you can define them yourself as follows:
    /// ```cpp
    /// inline constexpr xtd::expressions::placeholder<10> _11{};
    /// inline constexpr xtd::expressions::placeholder<11> _12{};
    /// //...
    /// inline constexpr xtd::expressions::placeholder<99> _100{};
    /// ```
    /// @warning The more arguments there are and the more complex the expression is, the longer it will take the compiler to compile the expression.
    /// @warning In this case, we strongly encourage you to use a standard C++ lambda expression or to use another expression library.
    inline constexpr placeholder<0> _1{};
    /// @brief The xtd::expressions::_2 placeholder instance is second argument used by expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks xtd::expressions contains the first ten entries from xtd::expressions::placeholder. If you need an eleventh entry or more, you can define them yourself as follows:
    /// ```cpp
    /// inline constexpr xtd::expressions::placeholder<10> _11{};
    /// inline constexpr xtd::expressions::placeholder<11> _12{};
    /// //...
    /// inline constexpr xtd::expressions::placeholder<99> _100{};
    /// ```
    /// @warning The more arguments there are and the more complex the expression is, the longer it will take the compiler to compile the expression.
    /// @warning In this case, we strongly encourage you to use a standard C++ lambda expression or to use another expression library.
    inline constexpr placeholder<1> _2{};
    /// @brief The xtd::expressions::_3 placeholder instance is third argument used by expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks xtd::expressions contains the first ten entries from xtd::expressions::placeholder. If you need an eleventh entry or more, you can define them yourself as follows:
    /// ```cpp
    /// inline constexpr xtd::expressions::placeholder<10> _11{};
    /// inline constexpr xtd::expressions::placeholder<11> _12{};
    /// //...
    /// inline constexpr xtd::expressions::placeholder<99> _100{};
    /// ```
    /// @warning The more arguments there are and the more complex the expression is, the longer it will take the compiler to compile the expression.
    /// @warning In this case, we strongly encourage you to use a standard C++ lambda expression or to use another expression library.
    inline constexpr placeholder<2> _3{};
    /// @brief The xtd::expressions::_4 placeholder instance is fourth argument used by expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks xtd::expressions contains the first ten entries from xtd::expressions::placeholder. If you need an eleventh entry or more, you can define them yourself as follows:
    /// ```cpp
    /// inline constexpr xtd::expressions::placeholder<10> _11{};
    /// inline constexpr xtd::expressions::placeholder<11> _12{};
    /// //...
    /// inline constexpr xtd::expressions::placeholder<99> _100{};
    /// ```
    /// @warning The more arguments there are and the more complex the expression is, the longer it will take the compiler to compile the expression.
    /// @warning In this case, we strongly encourage you to use a standard C++ lambda expression or to use another expression library.
    inline constexpr placeholder<3> _4{};
    /// @brief The xtd::expressions::_5 placeholder instance is fifth argument used by expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks xtd::expressions contains the first ten entries from xtd::expressions::placeholder. If you need an eleventh entry or more, you can define them yourself as follows:
    /// ```cpp
    /// inline constexpr xtd::expressions::placeholder<10> _11{};
    /// inline constexpr xtd::expressions::placeholder<11> _12{};
    /// //...
    /// inline constexpr xtd::expressions::placeholder<99> _100{};
    /// ```
    /// @warning The more arguments there are and the more complex the expression is, the longer it will take the compiler to compile the expression.
    /// @warning In this case, we strongly encourage you to use a standard C++ lambda expression or to use another expression library.
    inline constexpr placeholder<4> _5{};
    /// @brief The xtd::expressions::_6 placeholder instance is sixth argument used by expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks xtd::expressions contains the first ten entries from xtd::expressions::placeholder. If you need an eleventh entry or more, you can define them yourself as follows:
    /// ```cpp
    /// inline constexpr xtd::expressions::placeholder<10> _11{};
    /// inline constexpr xtd::expressions::placeholder<11> _12{};
    /// //...
    /// inline constexpr xtd::expressions::placeholder<99> _100{};
    /// ```
    /// @warning The more arguments there are and the more complex the expression is, the longer it will take the compiler to compile the expression.
    /// @warning In this case, we strongly encourage you to use a standard C++ lambda expression or to use another expression library.
    inline constexpr placeholder<5> _6{};
    /// @brief The xtd::expressions::_7 placeholder instance is seventh argument used by expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks xtd::expressions contains the first ten entries from xtd::expressions::placeholder. If you need an eleventh entry or more, you can define them yourself as follows:
    /// ```cpp
    /// inline constexpr xtd::expressions::placeholder<10> _11{};
    /// inline constexpr xtd::expressions::placeholder<11> _12{};
    /// //...
    /// inline constexpr xtd::expressions::placeholder<99> _100{};
    /// ```
    /// @warning The more arguments there are and the more complex the expression is, the longer it will take the compiler to compile the expression.
    /// @warning In this case, we strongly encourage you to use a standard C++ lambda expression or to use another expression library.
    inline constexpr placeholder<6> _7{};
    /// @brief The xtd::expressions::_8 placeholder instance is eighth argument used by expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks xtd::expressions contains the first ten entries from xtd::expressions::placeholder. If you need an eleventh entry or more, you can define them yourself as follows:
    /// ```cpp
    /// inline constexpr xtd::expressions::placeholder<10> _11{};
    /// inline constexpr xtd::expressions::placeholder<11> _12{};
    /// //...
    /// inline constexpr xtd::expressions::placeholder<99> _100{};
    /// ```
    /// @warning The more arguments there are and the more complex the expression is, the longer it will take the compiler to compile the expression.
    /// @warning In this case, we strongly encourage you to use a standard C++ lambda expression or to use another expression library.
    inline constexpr placeholder<7> _8{};
    /// @brief The xtd::expressions::_9 placeholder instance is ninth argument used by expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks xtd::expressions contains the first ten entries from xtd::expressions::placeholder. If you need an eleventh entry or more, you can define them yourself as follows:
    /// ```cpp
    /// inline constexpr xtd::expressions::placeholder<10> _11{};
    /// inline constexpr xtd::expressions::placeholder<11> _12{};
    /// //...
    /// inline constexpr xtd::expressions::placeholder<99> _100{};
    /// ```
    /// @warning The more arguments there are and the more complex the expression is, the longer it will take the compiler to compile the expression.
    /// @warning In this case, we strongly encourage you to use a standard C++ lambda expression or to use another expression library.
    inline constexpr placeholder<8> _9{};
    /// @brief The xtd::expressions::_10 placeholder instance is tenth argument used by expression.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks xtd::expressions contains the first ten entries from xtd::expressions::placeholder. If you need an eleventh entry or more, you can define them yourself as follows:
    /// ```cpp
    /// inline constexpr xtd::expressions::placeholder<10> _11{};
    /// inline constexpr xtd::expressions::placeholder<11> _12{};
    /// //...
    /// inline constexpr xtd::expressions::placeholder<99> _100{};
    /// ```
    /// @warning The more arguments there are and the more complex the expression is, the longer it will take the compiler to compile the expression.
    /// @warning In this case, we strongly encourage you to use a standard C++ lambda expression or to use another expression library.
    inline constexpr placeholder<9> _10{};

    /// @brief The xtd::expressions::_ placeholder instance is used by expression that have only one argument.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::_ is an alias on xtd::expressions::_1
    inline constexpr auto& _ = _1;
    /// @}
  }
}

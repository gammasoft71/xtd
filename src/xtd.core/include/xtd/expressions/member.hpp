/// @file
/// @brief Contains xtd::expressions::member bind opertor.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "as_expression.hpp"
#include "expression_operand.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::member_type contains the member type.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::member_type struct is used by xtd::expressions::member.
    template <typename member_t>
    struct member_type {
      member_t member;
    };
    
    /// @brief The xtd::expressions::member is use to bind object member.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::member mzthod is used by xtd::expressions::operator ^().
    template <typename member_t>
    constexpr auto member(member_t member) {
      return member_type<member_t>{member};
    }
    
    /// @name Public Operators
    
    /// @{
    /// @brief Bind member operator.
    /// @param expression The expression that associate to the  binded member.
    /// @param member The binded mehtod to execute.
    /// @return The result of the binded member.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @par Examples
    /// The following example shows how to use xtd::expressions::not_equal_to_expression.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   struct foo {
    ///     int value;
    ///   };
    ///
    ///   auto mem1 = _^member(&foo::value);
    ///   println("mem1 result => {}", mem1(foo {42}));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // mem1 result => 42
    /// ```
    template <typename expression_t, typename member_t>
    constexpr auto operator ^(expression_t expression, member_type<member_t> member) {
      return [=](auto&&... args) {
        auto&& obj = expression(std::forward<decltype(args)>(args)...);
        if constexpr (std::is_pointer_v<std::decay_t<decltype(obj)>>) return (obj->*member.member);
        else return (obj.*member.member);
      };
    }
    /// @}
  }
}

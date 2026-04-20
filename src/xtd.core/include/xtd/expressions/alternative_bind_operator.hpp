/// @file
/// @brief Contains xtd::expressions::member bind operator.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @name Public Operators
    
    /// @{
    /// @brief Bind operator.
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
    ///   struct foo {
    ///     int value;
    ///   };
    ///
    ///   auto mem1 = _^member(&foo::value);
    ///   println("mem1 result => {}", mem1(foo {42}));
    ///   auto fct1 = _^method(&string::to_upper);
    ///   println("fct1 result => {}", fct1("Hello"_s));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // mem1 result => 42
    /// // fct1 result => HELLO
    /// ```
    template <typename left_t, typename right_t>
    constexpr auto operator ^(left_t&& left, right_t&& right) {
      return std::forward<left_t>(left) | std::forward<right_t>(right);
    }
    /// @}
  }
}

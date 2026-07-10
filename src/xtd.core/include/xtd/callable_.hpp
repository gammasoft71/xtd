/// @file
/// @brief Contains xtd::callable concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/callable> or <xtd/callable.hpp> instead."


/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the callable (function, method, xtd::delegate, xtd::event, std::functional) concept.
  /// @par Definition
  /// ```cpp
  /// template<class function_t, class result_t = void, class... args_t>
  /// concept callable = std::invocable<function_t, args_t...> && (std::is_void_v<result_t> || std::convertible_to<std::invoke_result_t<function_t, args_t...>, result_t>);
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/callable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::arithmeticable concept
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// template<class value_t>
  /// auto sort_with(const array<value_t>& items, callable<int, value_t, value_t> auto fct) -> array<value_t> {
  ///   auto result = items;
  ///   result.sort(fct);
  ///   return result;
  /// }
  ///
  /// int main() {
  ///   auto items = array {8.0, 2.0, 5.0, 9.0, 4.0, 1.0, 6.0, 7.0, 10.0, 3.0};
  ///   println("items = {}", sort_with(items, [](auto a, auto b) {return a - b;}));
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // items = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
  /// ```
  template<class function_t, class result_t = void, class... args_t>
  struct callable;
}

/// @file
/// @brief Contains xtd::expressions::constant struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "constant_expression.hpp"
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::constant is the constant wrapper.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/constant>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks The xtd::expressions::constant struct is used by xtd::expressions::as_expression methods.
    template <typename type_t>
    struct constant : constant_expression {
      /// @name Public Fields
      
      /// @{
      /// @brief The operator precedence. That contains one of xtd::expressions::operator_precedence values.
      static constexpr operator_precedence precedence = operator_precedence::constant;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::constant object with specified constant value.
      /// @param value The constant value.
      constexpr constant(type_t value) : value_ {std::move(value)} {}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Gets the constant value.
      /// @return The constant value.
      template <typename... args_t>
      constexpr auto operator()(args_t&&...) const {return value_;}
      /// @}

      /// @cond
      friend auto operator <<(std::ostream& os, constant c) -> std::ostream& {return os << c.value_;}
      /// @endcond
      
    private:
      [[no_unique_address]] type_t value_;
    };
  }
}

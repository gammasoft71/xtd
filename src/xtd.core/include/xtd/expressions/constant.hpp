/// @file
/// @brief Contains xtd::expressions::constant struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::constant is the constant wrapper.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The xtd::expressions::constant struct is used by xtd::expressions::as_expression methods.
    template <typename type_t>
    struct constant {
      static constexpr operator_precedence precedence = operator_precedence::constante;
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new xtd::expressions::constant object with specified constant value.
      /// @param value The constant value.
      constexpr constant(auto&& value) : value_ {value} {}
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
      type_t value_;
    };
  }
}

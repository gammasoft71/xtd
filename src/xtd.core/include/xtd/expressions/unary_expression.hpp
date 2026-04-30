/// @file
/// @brief Contains xtd::expressions::unary_expression struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "expression.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::unary_expression is the base class for xtd::expressions::placeholder.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/unary_expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    struct unary_expression : expression {
    protected:
      /// @name Protected Constructors
      
      /// @{
      unary_expression() = default;
      /// @}
    };
  }
}


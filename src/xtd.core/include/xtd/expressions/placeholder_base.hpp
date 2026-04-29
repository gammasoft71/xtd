/// @file
/// @brief Contains xtd::expressions::placeholder_base struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "expression.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::placeholder_base is the base class for xtd::expressions::placeholder.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/placeholder_base>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    struct placeholder_base : expression {
    protected:
      /// @name Protected Constructors
      
      /// @{
      placeholder_base() = default;
      /// @}
    };
  }
}


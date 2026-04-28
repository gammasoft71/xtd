/// @file
/// @brief Contains xtd::expressions::expression_stream struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "operator_precedence.hpp"
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::expression_stream is the streamable class for expression objects.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/expression_stream>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    template <typename expression_t>
    struct expression_stream {
      /// @brief The expression to stream
      const expression_t& expression;
      /// @brief The parent operator precedence. That contains one of xtd::expressions::operator_precedence values.
      operator_precedence parent_precedence;
    };

    /// @cond
    template <typename expression_t>
    auto operator<<(std::ostream& os, const expression_stream<expression_t>& ps) -> std::ostream& {
      if (ps.parent_precedence < expression_t::precedence) os << "(" << ps.expression << ")";
      else os << ps.expression;
      return os;
    }
    /// @endcond
  }
}


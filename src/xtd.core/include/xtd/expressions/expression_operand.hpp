/// @file
/// @brief Contains xtd::expressions::expression_operand concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "expression.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::expression_operand object is expression operand concept.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    template <typename left_t, typename right_t>
    concept expression_operand =
    expression<left_t> || expression<right_t>;
  }
}

/// @file
/// @brief Contains xtd::expressions::expression concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "expression_base.hpp"
#include "placeholder_base.hpp"
#include <concepts>
#include <type_traits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::expression_operand object is expression concept.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    template <typename type_t>
    concept expression =
    std::is_base_of_v<expression_base, std::decay_t<type_t>> ||
    std::is_base_of_v<placeholder_base, std::decay_t<type_t>>;
  }
}

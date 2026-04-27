/// @file
/// @brief Contains xtd::expressions::expression_base struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "operator_precedence.hpp"
#include "../type_of.hpp"
#include <concepts>
#include <ostream>
#include <type_traits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief The xtd::expressions::expression_base is the base class for expression objects.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    struct expression_base {
      template<typename expression_t>
      static auto print_with_parens(std::ostream& os, const expression_t& expr, operator_precedence parent_precedence) -> void {
        if (parent_precedence < expression_t::precedence) os << "(" << expr << ")";
        else os << expr;
      }
    };
    
    /// @cond
    template<typename type_t>
    requires std::is_base_of_v<expression_base, std::decay_t<type_t>>
    auto operator <<(std::ostream& os, const type_t& e) -> std::ostream& {return os << type_of(e);}
    /// @endcond
  }
}


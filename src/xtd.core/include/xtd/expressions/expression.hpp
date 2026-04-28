/// @file
/// @brief Contains xtd::expressions::expression struct.
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
    /// @brief The xtd::expressions::expression is the base class for expression objects.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    struct expression {
    protected:
      /// @name Protected Constructors
      
      /// @{
      expression() = default;
      /// @}
    };
    
    /// @cond
    template<typename type_t>
    requires std::is_base_of_v<expression, std::decay_t<type_t>>
    auto operator <<(std::ostream& os, const type_t& e) -> std::ostream& {return os << type_of(e);}
    /// @endcond
  }
}


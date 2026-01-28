/// @file
/// @brief Contains xtd::helpers::strictly_ordered concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "greater_than_comparable.hpp"
#include "less_than_comparable.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::helpers namespace contains helpers for xtd objects, sush as exception static class.
  namespace helpers {
    /// @brief Concept strictly ordered.
    /// @par Definition
    /// ```cpp
    /// template<typename value_t>
    /// concept less_than_comparable;
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/helpers/less_than_comparable>
    /// ```
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core helpers concepts
    template<typename value_t>
    concept strictly_ordered = less_than_comparable<value_t> && greater_than_comparable<value_t>;
  }
}

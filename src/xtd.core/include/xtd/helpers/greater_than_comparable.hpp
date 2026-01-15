/// @file
/// @brief Contains xtd::helpers::greater_than_comparable concept.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <type_traits>
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::helpers namespace contains helpers for xtd objects, sush as exception static class.
  namespace helpers {
    /// @brief Concept greather than comparable.
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
    concept greater_than_comparable = requires(const value_t& a, const value_t& b) {{ a > b } -> std::convertible_to<bool>;};
  }
}

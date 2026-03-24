/// @file
/// @brief Contains xtd::helpers::less_than_comparable concept docuemntation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/less_than_comparable> or <xtd/less_than_comparable.hpp> instead."

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the less than comparable concept.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::less_than_comparable = requires(const type_t& a, const type_t& b) {{ a < b } -> std::convertible_to<bool>;};
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/less_than_comparable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core helpers concepts
  template<typename type_t>
  struct less_than_comparable;
  };
}

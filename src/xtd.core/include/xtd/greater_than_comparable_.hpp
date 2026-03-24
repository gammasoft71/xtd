/// @file
/// @brief Contains xtd::helpers::greater_than_comparable concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#error "Do not include this file: Internal use only. Include <xtd/greater_than_comparable> or <xtd/greater_than_comparable.hpp> instead."

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the greater than comparable concept.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::greater_than_comparable = requires(const type_t& a, const type_t& b) {{ a > b } -> std::convertible_to<bool>;};
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/greater_than_comparable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core helpers concepts
  template<typename type_t>
  struct greater_than_comparable;
}

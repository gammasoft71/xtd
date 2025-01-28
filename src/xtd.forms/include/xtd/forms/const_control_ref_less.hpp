/// @file
/// @brief Contains xtd::forms::const_control_ref typedef.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "const_control_ref.hpp"
#include <xtd/object>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents less comparator for const const_control_ref.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/const_control_ref_less>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    struct const_control_ref_less {
      /// @name Operators
      
      /// @{
      /// @brief Compare two specified const_control_ref.
      /// @param value1 The first value to compare.
      /// @param value2 The second value to compare.
      /// @return `true` if value1 < value2; otherwise `false`.
      bool operator()(const const_control_ref& value1, const const_control_ref& value2) const {
        return &value1.get() < &value2.get();
      }
      /// @}
    };
  }
}

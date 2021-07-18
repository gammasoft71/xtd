/// @file
/// @brief Contains xtd::forms::control_ref typedef.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/object.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    /// @endcond
    
    /// @brief Represents a control reference.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    using control_ref = std::reference_wrapper<control>;
    
    /// @brief Represents a const control reference.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    using const_control_ref = std::reference_wrapper<const control>;

    /// @brief Represents less comparator for control_ref.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    struct control_ref_less : public object {
      /// @brief Compare two specified control_ref.
      /// @param value1 The first value to compare.
      /// @param value2 The second value to compare.
      /// @return true if value1 < value2; otherwise false.
      bool operator()(const control_ref& value1, const control_ref& value2) const {
        return &value1.get() < &value2.get();
      }
    };

    /// @brief Represents less comparator for const const_control_ref.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    struct const_control_ref_less {
      /// @brief Compare two specified const_control_ref.
      /// @param value1 The first value to compare.
      /// @param value2 The second value to compare.
      /// @return true if value1 < value2; otherwise false.
      bool operator()(const const_control_ref& value1, const const_control_ref& value2) const {
        return &value1.get() < &value2.get();
      }
    };
  }
}

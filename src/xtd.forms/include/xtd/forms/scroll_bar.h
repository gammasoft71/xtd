#pragma once
#include "control.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows scroll bar.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms common_controls
    /// @par Example
    /// The following code example demonstrate the use of scroll bar control.
    /// @include scroll_bar.cpp
    // class forms_export_ scroll_bar : public control {
    class scroll_bar : public control {
    public:      
      
    protected:
      scroll_bar() = default;
    };
  }
}

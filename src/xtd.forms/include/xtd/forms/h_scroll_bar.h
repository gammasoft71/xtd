/// @file
/// @brief Contains xtd::forms::h_scroll_bar control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "scroll_bar.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows horizontal scroll bar.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrate the use of h_scroll_bar control.
    /// @include h_scroll_bar.cpp
    class forms_export_ h_scroll_bar : public scroll_bar {
    public:
      /// @brief Initialize a new instance of h_scroll_bar class.
      h_scroll_bar();
      xtd::drawing::size default_size() const override {return {80, 17};}
      
    protected:
      xtd::forms::create_params create_params() const override;
    };
  }
}

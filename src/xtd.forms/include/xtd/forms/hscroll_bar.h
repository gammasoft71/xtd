/// @file
/// @brief Contains xtd::forms::hscroll_bar control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "scroll_bar.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows hscroll_bar.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrate the use of hscroll_bar control.
    /// @include hscroll_bar.cpp
    /// @par Windows
    /// @image html hscroll_bar_w.png
    /// <br>
    /// @image html hscroll_bar_wd.png
    /// @par macOS
    /// @image html hscroll_bar_m.png
    /// <br>
    /// @image html hscroll_bar_md.png
    /// @par Gnome
    /// @image html hscroll_bar_g.png
    /// <br>
    /// @image html hscroll_bar_gd.png
    class forms_export_ hscroll_bar : public scroll_bar {
    public:
      /// @brief Initializee a new instance of hscroll_bar class.
      hscroll_bar();
      xtd::drawing::size default_size() const override {return {80, 17};}
      
    protected:
      xtd::forms::create_params create_params() const override;
    };
  }
}

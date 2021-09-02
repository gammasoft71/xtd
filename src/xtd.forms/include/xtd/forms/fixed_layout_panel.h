/// @file
/// @brief Contains xtd::forms::fixed_layout_panel container.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "panel.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Used to group collections of fixed alligned controls.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    /// @remarks Exactly the same as xtd::forms::panel container.
    /// @par Examples
    /// The following code example demonstrate the use of fixed_layout_panel container.
    /// @include fixed_layout_panel.cpp
    /// @par Windows
    /// @image html fixed_layout_panel_w.png
    /// <br>
    /// @image html fixed_layout_panel_wd.png
    /// @par macOS
    /// @image html fixed_layout_panel_m.png
    /// <br>
    /// @image html fixed_layout_panel_md.png
    /// @par Gnome
    /// @image html fixed_layout_panel_g.png
    /// <br>
    /// @image html fixed_layout_panel_gd.png
    class fixed_layout_panel : public panel {
    public:
      /// @brief Initialises a new instance of fixed layout panel class.
      fixed_layout_panel() = default;
      
    protected:
      void on_layout(const xtd::event_args& e) override;
    };
  }
}

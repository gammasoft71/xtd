/// @file
/// @brief Contains xtd::forms::vertical_layout_panel container.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <map>
#include "vertical_control_layout_style_collection.h"
#include "panel.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Used to group collections of verticaly alligned controls.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    /// @par Examples
    /// The following code example demonstrate the use of vertical_layout_panel container.
    /// @include vertical_layout_panel.cpp
    /// @par Windows
    /// @image html vertical_layout_panel_w.png
    /// <br>
    /// @image html vertical_layout_panel_wd.png
    /// @par macOS
    /// @image html vertical_layout_panel_m.png
    /// <br>
    /// @image html vertical_layout_panel_md.png
    /// @par Gnome
    /// @image html vertical_layout_panel_g.png
    /// <br>
    /// @image html vertical_layout_panel_gd.png
    class vertical_layout_panel : public panel {
    public:
      /// @brief Initialises a new instance of vertical layout panel class.
      vertical_layout_panel() = default;
      
      const vertical_control_layout_style_collection& control_layout_styles() const {return control_layout_styles_;}
      vertical_control_layout_style_collection& control_layout_styles() {return control_layout_styles_;}

    protected:
      void on_control_added(const xtd::forms::control_event_args& e) override;
      void on_control_removed(const xtd::forms::control_event_args& e) override;
      void on_layout(const xtd::event_args& e) override;

    private:
      vertical_control_layout_style_collection control_layout_styles_;
    };
  }
}

/// @file
/// @brief Contains xtd::forms::tab_page container.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "panel.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a single tab page in a tab_control.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    /// @par Examples
    /// The following code example demonstrate the use of tab_page container.
    /// @include tab_control.cpp
    /// @par Windows
    /// @image html tab_control_w.png
    /// <br>
    /// @image html tab_control_wd.png
    /// @par macOS
    /// @image html tab_control_m.png
    /// <br>
    /// @image html tab_control_md.png
    /// @par Gnome
    /// @image html tab_control_g.png
    /// <br>
    /// @image html tab_control_gd.png
    /// @par Examples
    /// The following code example demonstrate the use of tab_control and colored tab_page containers.
    /// @include colored_tab_pages.cpp
    /// @par Windows
    /// @image html colored_tab_pages_w.png
    /// <br>
    /// @image html colored_tab_pages_wd.png
    /// @par macOS
    /// @image html colored_tab_pages_m.png
    /// <br>
    /// @image html colored_tab_pages_md.png
    /// @par Gnome
    /// @image html colored_tab_pages_g.png
    /// <br>
    /// @image html colored_tab_pages_gd.png
    class forms_export_ tab_page : public panel {
    public:
      tab_page();

      using panel::auto_scroll;
      scrollable_control& auto_scroll(bool auto_scroll) override;
      
      using panel::text;
      control& text(const std::string& text) override;

      void destroy_handle() override;

    protected:
      forms::create_params create_params() const override;
    };
  }
}

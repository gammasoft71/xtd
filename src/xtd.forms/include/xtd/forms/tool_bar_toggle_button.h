/// @file
/// @brief Contains xtd::forms::tool_bar_toggle_button container.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "tool_bar_button.h"
#include "../forms_export.h"
#include <xtd/event.h>
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a toolbar toggle button.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms  menus_and_toolbars
    class forms_export_ tool_bar_toggle_button : public tool_bar_button {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialises a new instance of xtd::forms::tool_bar_toggle_button class.
      tool_bar_toggle_button() {
        style(xtd::forms::tool_bar_button_style::toggle_button);
      }
      /// @}

    private:
      using tool_bar_button::style;
    };
  }
}

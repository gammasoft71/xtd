/// @file
/// @brief Contains xtd::forms::native::busy_dialog API.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <string>
#include <vector>
#include <xtd/static>
#include <xtd/string>
#include <xtd/drawing/color>
#include <xtd/drawing/icon>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class busy_dialog;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains busy dialog native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ busy_dialog final static_ {
        friend xtd::forms::busy_dialog;
      protected:
        /// @name Protected Static Methods
        
        /// @{
        /// @brief Creates and shows busy dialog.
        /// @param hwnd Parent window handle.
        /// @param icon An icon value that specifies the icon to display.
        /// @param text A string that specifies the title bar caption to display.
        /// @param description A string that specifies the text to display.
        /// @param back_color A color that represents the background color of the busy box.
        /// @param fore_color A color that represents the background color of the busy box.
        /// @param opacity A float that represents the opacity of the busy box. (0: full opacity and 1.0 no opacity). The lower the value, the more transparent.
        /// @return The created and shown busy dialog window handle.
        /// @warning Internal use only
        static intptr create(intptr hwnd, const xtd::drawing::icon& icon, const xtd::string& text, const xtd::string& description, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color, double opacity);
        /// @brief Destroys busy dialog.
        /// @param dialog Busy dialog window handle to destroy.
        /// @warning Internal use only
        static void destroy(intptr dialog);
        /// @}
      };
    }
  }
}

/// @file
/// @brief Contains xtd::forms::native::color_dialog API.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <vector>
#include <xtd/optional.h>
#include <xtd/delegate.h>
#include <xtd/static.h>
#include <xtd/drawing/color.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class color_dialog;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains color dialog native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ color_dialog final static_ {
        friend xtd::forms::color_dialog;
      protected:
        /// @name Protected Static Methods
        
        /// @{
        /// @brief Shows dialog.
        /// @param hwnd Parent window handle.
        /// @param title The file dialog box title. The default value is an empty string ("").
        /// @param color A xtd::drawing::color that specifies the color to display.
        /// @param custom_colors A colors array that contains user custom colors.
        /// @param options A bitwise combination of the color dialog flags.
        /// @return true if the user clicks OK in the dialog box; otherwise, false.
        /// @remarks If result is true, the color parameter contains the new chosen color.
        /// @remarks If the title is an empty string, the system uses a default title, which is "Color".
        /// @warning Internal use only
        static bool run_dialog(intptr hwnd, const xtd::ustring& title, xtd::drawing::color& color, std::vector<xtd::drawing::color>& custom_colors, size_t options);
        /// @brief Shows async dialog as sheet.
        /// @param on_dialog_closed a dialog close delegate to call when the dialog is closed.
        /// @param hwnd Parent window handle.
        /// @param title The file dialog box title. The default value is an empty string ("").
        /// @param color A xtd::drawing::color that specifies the color to display.
        /// @param custom_colors A colors array that contains user custom colors.
        /// @param options A bitwise combination of the color dialog flags.
        /// @remarks When dialog closed and if result is true, the color parameter contains the new chosen color.
        /// @remarks If the title is an empty string, the system uses a default title, which is "Color".
        /// @warning Internal use only
        static void run_sheet(xtd::delegate<void(bool)> on_dialog_closed, intptr hwnd, const xtd::ustring& title, xtd::drawing::color& color, std::vector<xtd::drawing::color>& custom_colors, size_t options);
        /// @}
      };
    }
  }
}

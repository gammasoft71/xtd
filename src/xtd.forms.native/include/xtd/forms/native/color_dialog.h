/// @file
/// @brief Contains xtd::forms::native::color_dialog API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <optional>
#include <vector>
#include <xtd/delegate.h>
#include <xtd/static.h>
#include <xtd/drawing/color.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains color dialog native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ color_dialog final static_ {
      public:
        /// @brief Shows dialog.
        /// @param hwnd Parent window handle.
        /// @param color A xtd::drawing::color that specifies the color to display.
        /// @param custom_colors A collors array that contains user custom colors.
        /// @param options A bitwise combination of the color dialog flags.
        /// @return true if the user clicks OK in the dialog box; otherwise, false.
        /// @remarks If result is true, the color parameter contains the new chosen color.
        /// @warning Internal use only
        static bool run_dialog(intptr_t hwnd, xtd::drawing::color& color, std::vector<xtd::drawing::color>& custom_colors, size_t options);
        /// @brief Shows async dialog as sheet.
        /// @param on_dialog_closed a dialog close delegate to call when the dialog is closed.
        /// @param color A xtd::drawing::color that specifies the color to display.
        /// @param custom_colors A collors array that contains user custom colors.
        /// @param options A bitwise combination of the color dialog flags.
        /// @remarks When dialog closed and if result is true, the color parameter contains the new chosen color.
        /// @warning Internal use only
        static void run_sheet(xtd::delegate<void(bool)> on_dialog_closed, intptr_t hwnd, xtd::drawing::color& color, std::vector<xtd::drawing::color>& custom_colors, size_t options);
      };
    }
  }
}

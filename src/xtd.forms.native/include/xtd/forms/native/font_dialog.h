/// @file
/// @brief Contains xtd::forms::native::font_dialog API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <xtd/delegate.h>
#include <xtd/static.h>
#include <xtd/drawing/color.h>
#include <xtd/drawing/font.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains font dialog native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ font_dialog final static_ {
      public:
        /// @brief Shows dialog.
        /// @param hwnd Parent window handle.
        /// @param font The selected font.
        /// @param color The selected color.
        /// @param min_size The minimum point size a user can select.
        /// @param max_size The maximum point size a user can select.
        /// @param show_color true if the dialog box displays the color choice; otherwise, false.
        /// @return true if the user clicks OK in the dialog box; otherwise, false.
        /// @remarks If result is true, the font parameter contains the new font, and the color rparamter contains the now coolor.
        /// @warning Internal use only
        static bool run_dialog(intptr_t hwnd, drawing::font& font, drawing::color& color, size_t options, size_t min_size, size_t max_size, bool show_color);
        /// @brief Shows async dialog as sheet.
        /// @param hwnd Parent window handle.
        /// @param font The selected font.
        /// @param color The selected color.
        /// @param min_size The minimum point size a user can select.
        /// @param max_size The maximum point size a user can select.
        /// @param show_color true if the dialog box displays the color choice; otherwise, false.
        /// @return true if the user clicks OK in the dialog box; otherwise, false.
        /// @remarks When dialog closed and if result is true, the font parameter contains the new font, and the color rparamter contains the now coolor.
        /// @warning Internal use only
        static void run_sheet(xtd::delegate<void(bool)> on_dialog_closed, intptr_t hwnd, drawing::font& font, drawing::color& color, size_t options, size_t min_size, size_t max_size, bool show_color);
      };
    }
  }
}

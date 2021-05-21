/// @file
/// @brief Contains xtd::forms::native::message_box API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <string>
#include <xtd/delegate.h>
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class message_dialog;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains message box native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ message_box final static_ {
        friend xtd::forms::message_dialog;
      protected:
        /// @brief Shows dialog.
        /// @param hwnd Parent window handle.
        /// @param text The text to display in the message box.
        /// @param caption The text to display in the title bar of the message box.
        /// @param options A bitwise of message box styles.
        /// @param display_help_button true to show the Help button; otherwise, false.
        /// @return A dialog box ids.
        /// @warning Internal use only
        static int32_t show(intptr_t hwnd, const std::string& text, const std::string& caption, uint32_t options, bool display_help_button);
        /// @brief Shows async dialog as sheet.
        /// @param on_dialog_closed a dialog close delegate to call when the dialog is closed.
        /// @param hwnd Parent window handle.
        /// @param text The text to display in the message box.
        /// @param caption The text to display in the title bar of the message box.
        /// @param options A bitwise of message box styles.
        /// @param display_help_button true to show the Help button; otherwise, false.
        /// @warning Internal use only
        static void show_sheet(xtd::delegate<void(int32_t)> on_dialog_closed, intptr_t hwnd, const std::string& text, const std::string& caption, uint32_t options, bool display_help_button);
      };
    }
  }
}

/// @file
/// @brief Contains xtd::forms::native::folder_browser_dialog API.
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
#include <xtd/environment.h>
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class folder_browser_dialog;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains folder browser dialog native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ folder_browser_dialog final static_ {
        friend xtd::forms::folder_browser_dialog;
      protected:
        /// @brief Shows dialog.
        /// @param hwnd Parent window handle.
        /// @param description The description to display.
        /// @param root_folder One of the environment::special_folder values.
        /// @param selected_path The path of the folder first selected in the dialog box or the last folder selected by the user.
        /// @param options A bittwise folder browser dialog flags value.
        /// @return true if the user clicks OK in the dialog box; otherwise, false.
        /// @remarks If result is true, the selected_path parameter contains the new selected path.
        /// @warning Internal use only
        static bool run_dialog(intptr_t hwnd, const std::string& description, environment::special_folder root_folder, std::string& selected_path, size_t options);
        /// @brief Shows async dialog as sheet.
        /// @param hwnd Parent window handle.
        /// @param description The description to display.
        /// @param root_folder One of the environment::special_folder values.
        /// @param selected_path The path of the folder first selected in the dialog box or the last folder selected by the user.
        /// @param options A bittwise folder browser dialog flags value.
        /// @return true if the user clicks OK in the dialog box; otherwise, false.
        /// @remarks When dialog closed and if result is true, the selected_path parameter contains the new selected path.
        /// @warning Internal use only
        static void run_sheet(xtd::delegate<void(bool)> on_dialog_closed, intptr_t hwnd, const std::string& description, environment::special_folder root_folder, std::string& selected_path, size_t options);
      };
    }
  }
}

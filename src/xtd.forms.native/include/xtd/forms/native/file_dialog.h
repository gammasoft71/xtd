/// @file
/// @brief Contains xtd::forms::native::file_dialog API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <string>
#include <vector>
#include <xtd/delegate.h>
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains file dialog native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ file_dialog final static_ {
      public:
        /// @brief Shows open file dialog.
        /// @param hwnd Parent window handle.
        /// @param default_ext The default file name extension. The returned string does not include the period.
        /// @param file_name The file name selected in the file dialog box.
        /// @param file_names An array of type string, containing the file names of all selected files in the dialog box.
        /// @param filter The file filtering options available in the dialog box.
        /// @param filter_index A value containing the index of the filter currently selected in the file dialog box.
        /// @param initial_directory The initial directory displayed by the file dialog box.
        /// @param options A bittwise file dialog flags value.
        /// @param support_multi_dotted_extensions true if the dialog box supports multiple file name extensions; otherwise, false. The default is false.
        /// @param title The file dialog box title.
        /// @return true if the user clicks OK in the dialog box; otherwise, false.
        /// @remarks If result is true, the file_name parameter contains the new chosen file name and if opotioon cantains OFN_ALLOWMULTISELECT flags, the file_names parameter contains the new chosen file names.
        /// @warning Internal use only
        static bool run_open_dialog(intptr_t hwnd, const std::string& default_ext, std::string& file_name, std::vector<std::string>& file_names, const std::string& filter, size_t filter_index, const std::string& initial_directory, size_t options, bool support_multi_dotted_extensions, const std::string& title);
        /// @brief Shows async open file dialog as sheet.
        /// @param on_dialog_closed a dialog close delegate to call when the dialog is closed.
        /// @param hwnd Parent window handle.
        /// @param default_ext The default file name extension. The returned string does not include the period.
        /// @param file_name The file name selected in the file dialog box.
        /// @param file_names An array of type string, containing the file names of all selected files in the dialog box.
        /// @param filter The file filtering options available in the dialog box.
        /// @param filter_index A value containing the index of the filter currently selected in the file dialog box.
        /// @param initial_directory The initial directory displayed by the file dialog box.
        /// @param options A bittwise file dialog flags value.
        /// @param support_multi_dotted_extensions true if the dialog box supports multiple file name extensions; otherwise, false. The default is false.
        /// @param title The file dialog box title.
        /// @return true if the user clicks OK in the dialog box; otherwise, false.
        /// @remarks When dialog closed and if result is true, the file_name parameter contains the new chosen file name and if opotioon cantains OFN_ALLOWMULTISELECT flags, the file_names parameter contains the new chosen file names.
        /// @warning Internal use only
        static void run_open_sheet(xtd::delegate<void(bool)> on_dialog_closed, intptr_t hwnd, const std::string& default_ext, std::string& file_name, std::vector<std::string>& file_names, const std::string& filter, size_t filter_index, const std::string& initial_directory, size_t options, bool support_multi_dotted_extensions, const std::string& title);
        /// @brief Shows save file dialog.
        /// @param hwnd Parent window handle.
        /// @param default_ext The default file name extension. The returned string does not include the period.
        /// @param file_name The file name selected in the file dialog box.
        /// @param file_names An array of type string, containing the file names of all selected files in the dialog box.
        /// @param filter The file filtering options available in the dialog box.
        /// @param filter_index A value containing the index of the filter currently selected in the file dialog box.
        /// @param initial_directory The initial directory displayed by the file dialog box.
        /// @param options A bittwise file dialog flags value.
        /// @param support_multi_dotted_extensions true if the dialog box supports multiple file name extensions; otherwise, false. The default is false.
        /// @param title The file dialog box title.
        /// @return true if the user clicks OK in the dialog box; otherwise, false.
        /// @remarks If result is true, the file_name parameter contains the new chosen file name and if opotioon cantains OFN_ALLOWMULTISELECT flags, the file_names parameter contains the new chosen file names.
        /// @warning Internal use only
        static bool run_save_dialog(intptr_t hwnd, const std::string& default_ext, std::string& file_name, std::vector<std::string>& file_names, const std::string& filter, size_t filter_index, const std::string& initial_directory, size_t options, bool support_multi_dotted_extensions, const std::string& title);
        /// @brief Shows async save file dialog as sheet.
        /// @param on_dialog_closed a dialog close delegate to call when the dialog is closed.
        /// @param hwnd Parent window handle.
        /// @param default_ext The default file name extension. The returned string does not include the period.
        /// @param file_name The file name selected in the file dialog box.
        /// @param file_names An array of type string, containing the file names of all selected files in the dialog box.
        /// @param filter The file filtering options available in the dialog box.
        /// @param filter_index A value containing the index of the filter currently selected in the file dialog box.
        /// @param initial_directory The initial directory displayed by the file dialog box.
        /// @param options A bittwise file dialog flags value.
        /// @param support_multi_dotted_extensions true if the dialog box supports multiple file name extensions; otherwise, false. The default is false.
        /// @param title The file dialog box title.
        /// @return true if the user clicks OK in the dialog box; otherwise, false.
        /// @remarks When dialog closed and if result is true, the file_name parameter contains the new chosen file name and if opotioon cantains OFN_ALLOWMULTISELECT flags, the file_names parameter contains the new chosen file names.
        /// @warning Internal use only
        static void run_save_sheet(xtd::delegate<void(bool)> on_dialog_closed, intptr_t hwnd, const std::string& default_ext, std::string& file_name, std::vector<std::string>& file_names, const std::string& filter, size_t filter_index, const std::string& initial_directory, size_t options, bool support_multi_dotted_extensions, const std::string& title);
      };
    }
  }
}

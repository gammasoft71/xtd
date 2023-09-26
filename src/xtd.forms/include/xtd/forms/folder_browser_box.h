/// @file
/// @brief Contains xtd::forms::folder_browser_box control.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export"
#include "dialog_result"
#include "iwin32_window"
#include <xtd/environment>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays a folder browser dialog. This class cannot be inherited.
    /// @par Header
    /// @code #include <xtd/forms/folder_browser_box> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                           | macOS                                             | Gnome                                             |
    /// | ----- | ------------------------------------------------- | ------------------------------------------------- | ------------------------------------------------- |
    /// | Light |  @image html dialog_folder_browser_dialog_w.png   |  @image html dialog_folder_browser_dialog_m.png   |  @image html dialog_folder_browser_dialog_g.png   |
    /// | Dark  |  @image html dialog_folder_browser_dialog_wd.png  |  @image html dialog_folder_browser_dialog_md.png  |  @image html dialog_folder_browser_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of xtd::forms::folder_browser_box dialog.
    /// @include folder_browser_box.cpp
    class forms_export_ folder_browser_box final static_ {
    public:
      /// @name Methods
      
      /// @{
      /// @brief Displays a folder browser dialog box in front of a specified window.
      /// @param selected_path A xtd::ustring that represents the path selected by the user.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param description An xtd::ustring that specifies the descriptive text displayed above the tree view control in the dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the selected_path parameter will contain the selected path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& selected_path, const xtd::forms::iwin32_window& owner);
      /// @brief Displays a folder browser dialog box in front of a specified window.
      /// @param selected_path A xtd::ustring that represents the path selected by the user.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param description An xtd::ustring that specifies the descriptive text displayed above the tree view control in the dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the selected_path parameter will contain the selected path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& selected_path, const xtd::forms::iwin32_window& owner, const xtd::ustring& description);
      /// @brief Displays a folder browser dialog box in front of a specified window.
      /// @param selected_path A xtd::ustring that represents the path selected by the user.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param description An xtd::ustring that specifies the descriptive text displayed above the tree view control in the dialog box.
      /// @param root_folder One of xtd::environment::special_folder values that specifies the root folder where the browsing starts from.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the selected_path parameter will contain the selected path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& selected_path, const xtd::forms::iwin32_window& owner, const xtd::ustring& description, xtd::environment::special_folder root_folder);
      /// @brief Displays a folder browser dialog box in front of a specified window.
      /// @param selected_path A xtd::ustring that represents the path selected by the user.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param description An xtd::ustring that specifies the descriptive text displayed above the tree view control in the dialog box.
      /// @param root_folder One of xtd::environment::special_folder values that specifies the root folder where the browsing starts from.
      /// @param show_new_folder_button A value indicating whether the New Folder button appears in the folder browser dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the selected_path parameter will contain the selected path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& selected_path, const xtd::forms::iwin32_window& owner, const xtd::ustring& description, xtd::environment::special_folder root_folder, bool show_new_folder_button);
      /// @brief Displays a folder browser dialog box in front of a specified window.
      /// @param selected_path A xtd::ustring that represents the path selected by the user.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param description An xtd::ustring that specifies the descriptive text displayed above the tree view control in the dialog box.
      /// @param root_folder One of xtd::environment::special_folder values that specifies the root folder where the browsing starts from.
      /// @param show_new_folder_button A value indicating whether the New Folder button appears in the folder browser dialog box.
      /// @param auto_upgrade_enable A value that indicates whether the dialog will be automatically upgraded to enable new features.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the selected_path parameter will contain the selected path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& selected_path, const xtd::forms::iwin32_window& owner, const xtd::ustring& description, xtd::environment::special_folder root_folder, bool show_new_folder_button, bool auto_upgrade_enable);
      /// @brief Displays a folder browser dialog box.
      /// @param selected_path A xtd::ustring that represents the path selected by the user.
      /// @param description An xtd::ustring that specifies the descriptive text displayed above the tree view control in the dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the selected_path parameter will contain the selected path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& selected_path);
      /// @brief Displays a folder browser dialog box.
      /// @param selected_path A xtd::ustring that represents the path selected by the user.
      /// @param description An xtd::ustring that specifies the descriptive text displayed above the tree view control in the dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the selected_path parameter will contain the selected path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& selected_path, const xtd::ustring& description);
      /// @brief Displays a folder browser dialog box.
      /// @param selected_path A xtd::ustring that represents the path selected by the user.
      /// @param description An xtd::ustring that specifies the descriptive text displayed above the tree view control in the dialog box.
      /// @param root_folder One of xtd::environment::special_folder values that specifies the root folder where the browsing starts from.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the selected_path parameter will contain the selected path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& selected_path, const xtd::ustring& description, xtd::environment::special_folder root_folder);
      /// @brief Displays a folder browser dialog box.
      /// @param selected_path A xtd::ustring that represents the path selected by the user.
      /// @param description An xtd::ustring that specifies the descriptive text displayed above the tree view control in the dialog box.
      /// @param root_folder One of xtd::environment::special_folder values that specifies the root folder where the browsing starts from.
      /// @param show_new_folder_button A value indicating whether the New Folder button appears in the folder browser dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the selected_path parameter will contain the selected path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& selected_path, const xtd::ustring& description, xtd::environment::special_folder root_folder, bool show_new_folder_button);
      /// @brief Displays a folder browser dialog box.
      /// @param selected_path A xtd::ustring that represents the path selected by the user.
      /// @param description An xtd::ustring that specifies the descriptive text displayed above the tree view control in the dialog box.
      /// @param root_folder One of xtd::environment::special_folder values that specifies the root folder where the browsing starts from.
      /// @param show_new_folder_button A value indicating whether the New Folder button appears in the folder browser dialog box.
      /// @param auto_upgrade_enable A value that indicates whether the dialog will be automatically upgraded to enable new features.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the selected_path parameter will contain the selected path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& selected_path, const xtd::ustring& description, xtd::environment::special_folder root_folder, bool show_new_folder_button, bool auto_upgrade_enable);
      /// @}
      
    private:
      static xtd::forms::dialog_result show_folder_browser_box(xtd::ustring& selected_path, const xtd::ustring& description = "", xtd::environment::special_folder root_folder = xtd::environment::special_folder::desktop, bool show_new_folder_button = true, bool auto_upgrade_enable = true, const iwin32_window* owner = nullptr);
    };
  }
}

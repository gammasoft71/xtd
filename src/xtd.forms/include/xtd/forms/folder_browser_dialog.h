/// @file
/// @brief Contains xtd::forms::folder_browser_dialog dialog.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "common_dialog.h"
#include <xtd/environment>
#include <xtd/forms/browser_info_flags>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Prompts the user to select a folder. This class cannot be inherited.
    /// @par Header
    /// @code #include <xtd/forms/folder_browser_dialog> @endcode
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
    /// The following code example demonstrates the use of folder_browser_dialog dialog.
    /// @include folder_browser_dialog.cpp
    class forms_export_ folder_browser_dialog final : public common_dialog {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the folder_browser_dialog class.
      /// @remarks The parameterless constructor initializes properties to their default values.
      /// @remarks When a new folder_browser_dialog is created, the root_folder property is set to xtd::environment::special_folder::desktop, the description property is set to an empty string (""), the selected_path property is set to an empty string, and the show_new_folder_button property is set to true.
      /// @remarks Typically, after creating a new folder_browser_dialog, you set the root_folder to the location from which to start browsing. Optionally, you can set the selected_path to the path of a subfolder of root_folder that will initially be selected. You can also optionally set the description property to provide additional instructions to the user. Finally, call the show_dialog or show_sheet or show_sheet_dialog method to display the dialog box to the user. When the dialog box is closed and the dialog result from show_dialog is dialog_result::ok, the selected_path will be a string containing the path to the selected folder.
      /// @remarks folder_browser_dialog is a modal dialog box; therefore, when shown, it blocks the rest of the application until the user has chosen a folder. When a dialog box is displayed modally, no input (keyboard or mouse click) can occur except to objects on the dialog box. The program must hide or close the dialog box (usually in response to some user action) before input to the calling program can occur.
      folder_browser_dialog();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets a value that indicates whether the dialog will be automatically upgraded to enable new features.
      /// @return true if the the dialog will be automatically upgraded to enable new features; otherwise, false. The default value is true.
      bool auto_upgrade_enable() const noexcept;
      /// @brief Sets a value that indicates whether the dialog will be automatically upgraded to enable new features.
      /// @param value true if the the dialog will be automatically upgraded to enable new features; otherwise, false. The default value is true.
      /// @return Current folder_browser_dialog.
      folder_browser_dialog& auto_upgrade_enable(bool value);
      
      /// @brief Gets the descriptive text displayed above the tree view control in the dialog box.
      /// @return The description to display. The default is an empty string ("").
      /// @remarks The description property can be used to specify additional information to the user, like instructions.
      const xtd::ustring& description() const noexcept;
      /// @brief Sets the descriptive text displayed above the tree view control in the dialog box.
      /// @param value The description to display. The default is an empty string ("").
      /// @return Current folder_browser_dialog.
      /// @remarks The description property can be used to specify additional information to the user, like instructions.
      folder_browser_dialog& description(const xtd::ustring& value);
      
      /// @brief Gets the root folder where the browsing starts from.
      /// @return One of the environment::special_folder values. The default is environment::special_folder::desktop.
      /// @remarks Only the specified folder and any subfolders that are beneath it will appear in the dialog box and be selectable. The selected_path property, along with root_folder, determines what the selected folder will be when the dialog box is displayed, as long as SelectedPath is an absolute path that is a subfolder of root_folder (or more accurately, points to a subfolder of the shell namespace represented by root_folder).
      environment::special_folder root_folder() const noexcept;
      /// @brief Sets the root folder where the browsing starts from.
      /// @param value One of the environment::special_folder values. The default is environment::special_folder::desktop.
      /// @return Current folder_browser_dialog.
      /// @remarks Only the specified folder and any subfolders that are beneath it will appear in the dialog box and be selectable. The selected_path property, along with root_folder, determines what the selected folder will be when the dialog box is displayed, as long as SelectedPath is an absolute path that is a subfolder of root_folder (or more accurately, points to a subfolder of the shell namespace represented by root_folder).
      folder_browser_dialog& root_folder(environment::special_folder value);
      /// @brief Gets the path selected by the user.
      /// @return The path of the folder first selected in the dialog box or the last folder selected by the user. The default is an empty string ("").
      /// @remarks If the selected_ath property is set before showing the dialog box, the folder with this path will be the selected folder, as long as selected_path is set to an absolute path that is a subfolder of root_folder (or more accurately, points to a subfolder of the shell namespace represented by root_folder).
      /// @remarks If the show_dialog returns OK, meaning the user clicked the OK button, the selected_path property will return a string containing the path to the selected folder. If show_dialog returns Cancel, meaning the user canceled out of the dialog box, this property will have the same value that it had prior to displaying the dialog box. If the user selects a folder that does not have a physical path (for example, My Computer), the OK button on the dialog box will be disabled.
      const xtd::ustring& selected_path() const noexcept;
      /// @brief Sets the path selected by the user.
      /// @param value The path of the folder first selected in the dialog box or the last folder selected by the user. The default is an empty string ("").
      /// @return Current folder_browser_dialog.
      /// @remarks If the selected_ath property is set before showing the dialog box, the folder with this path will be the selected folder, as long as selected_path is set to an absolute path that is a subfolder of root_folder (or more accurately, points to a subfolder of the shell namespace represented by root_folder).
      /// @remarks If the show_dialog returns OK, meaning the user clicked the OK button, the selected_path property will return a string containing the path to the selected folder. If show_dialog returns Cancel, meaning the user canceled out of the dialog box, this property will have the same value that it had prior to displaying the dialog box. If the user selects a folder that does not have a physical path (for example, My Computer), the OK button on the dialog box will be disabled.
      folder_browser_dialog& selected_path(const xtd::ustring& value);
      
      /// @brief Gets a value indicating whether the New Folder button appears in the folder browser dialog box.
      /// @return true if the New Folder button is shown in the dialog box; otherwise, false. The default is true.
      /// @remarks When show_new_folder_button is true, the New Folder button is visible, giving the user a chance to create a folder. When the user clicks the New Folder button, a new folder is created and the user is prompted to specify the folder name. The selected node in the tree becomes the parent of the new folder. The actual caption of the New Folder button can vary depending upon the operating system
      bool show_new_folder_button() const noexcept;
      /// @brief Sets a value indicating whether the New Folder button appears in the folder browser dialog box.
      /// @param value true if the New Folder button is shown in the dialog box; otherwise, false. The default is true.
      /// @remarks When show_new_folder_button is true, the New Folder button is visible, giving the user a chance to create a folder. When the user clicks the New Folder button, a new folder is created and the user is prompted to specify the folder name. The selected node in the tree becomes the parent of the new folder. The actual caption of the New Folder button can vary depending upon the operating system
      folder_browser_dialog& show_new_folder_button(bool value);
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Resets all options to their default values, the last selected color to black, and the custom colors to their default values.
      void reset() noexcept override;
      /// @}
      
    protected:
      /// @name Protected methods
      
      /// @{
      /// @brief When overridden in a derived class, specifies a common dialog box.
      /// @param owner A value that represents the window handle of the owner window for the common dialog box.
      /// @return true if the dialog box was successfully run; otherwise, false.
      bool run_dialog(intptr owner) override;
      
      /// @brief When overridden in a derived class, specifies a common dialog box.
      /// @param owner A value that represents the window handle of the owner window for the common dialog box.
      void run_sheet(intptr owner) override;
      /// @}
      
    private:
      bool get_option(size_t flag) const noexcept;
      void set_option(size_t flag, bool value);
      
      std::shared_ptr<data> data_;
    };
  }
}

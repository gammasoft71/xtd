/// @file
/// @brief Contains xtd::forms::file_dialog dialog.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "common_dialog.h"
#include <vector>
#include <xtd/forms/open_file_name_flags.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class open_file_dialog;
    class save_file_dialog;
    /// @endcond

    /// @brief Displays a dialog box from which the user can select a file.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks file_dialog is an abstract class that contains common behavior for the open_file_dialog and save_file_dialog classes. It is not intended to be used directly but contains common behavior for those two classes. You cannot create an instance of file_dialog. Although the class is declared public, you cannot inherit from it, as it contains private abstract methods. To create a dialog box to select or save a file, use open_file_dialog or save_file_dialog.
    /// @remarks file_dialog is a modal dialog box; therefore, when shown, it blocks the rest of the application until the user has chosen a file. When a dialog box is displayed modally, no input (keyboard or mouse click) can occur except to objects on the dialog box. The program must hide or close the dialog box (usually in response to some user action) before input to the calling program can occur.
    /// @warning When you use classes derived from file_dialog, such as open_file_dialog and save_file_dialog, avoid using string literals containing absolute paths. Instead, dynamically obtain the path using one or more of the techniques described in the following table.
    /// @remarks If you want to enable users to select a folder instead of a file, use the folder_browser_dialog.
    /// @remarks Depending upon the type of application, how data associated with the application is stored, and the reason for accessing the file system, there are many possible ways in which you can create a directory path. The following table shows the techniques for creating paths dynamically.
    /// | Path or program category                                                          | Class and members to use                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
    /// |-----------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
    /// | Standard Windows paths, such as Program Files, MyDocuments, the Desktop and so on | The xtd::environment class is the most complete source for these, either through its static methods, such as system_directory, or through the get_folder_path method, using one of the environment::special_folder enumerated values.                                                                                                                                                                                                                                                        |
    /// | Paths related to the current application                                          | The application class has static members to obtain certain paths, such as startup_path, executable_path, local_user_app_data_path, and common_app_data_path.<br><br>The get_temp_path method of the xtd::io::path returns the path of the temporary folder.<br><br>The get_current_directory method of the xtd::io::directory class returns the application's current executing directory.<br><br>The root_directory property of the drive_info class represents the specified drive's root directory. |
    /// | Paths stored as application settings                                              | Access the corresponding applications settings property of the wrapper class derived from application_settings_base. For more information, see application settings for Windows Forms.                                                                                                                                                                                                                                                                                                      |
    /// | Registry storage                                                                  | Some applications store directory information in the registry. The Application class has the common_ app_data_path and local_user_app_data_path properties that resolve to a registry_key value.                                                                                                                                                                                                                                                                                                   |
    /// | ClickOnce applications                                                            | For click_once applications, use application class members such as user_app_data_path, which will return a pointer to the click_once data directory. For more information, see accessing local and remote data in click_once applications.                                                                                                                                                                                                                                                      |
    /// | International applications                                                        | For international applications, retrieve the relative path portion from a string resource in your application by using the xtd::resources::resource_reader class. For more information about globalization and localization                                                                                                                                                                                        |
    /// @remarks Notice that a full path may be built up using one or more of the described techniques. For example, the get_folder_path method might be used to obtain the path to the MyDocuments folder, then an application setting may be used to add a relative subdirectory portion.
    /// @remarks The xtd::io::path class contains static members to assist in manipulating absolute and relative path strings, whereas the System.IO.File and xtd::io::directory classes have static members that actually manipulate files and directories, respectively.
    /// @par Important
    /// If the user of your application changes the folder in the file_dialog, then the current working directory for your application is set to the location specified in the file_dialog. To prevent this, set the restore_directory property to true.
    class forms_export_ file_dialog : public common_dialog {
    public:
      /// @brief Initializes a new instance of the common_dialog class.
      file_dialog() = default;
      
      /// @brief Gets a value indicating whether the dialog box automatically adds an extension to a file name if the user omits the extension.
      /// @return true if the dialog box adds an extension to a file name if the user omits the extension; otherwise, false. The default value is true.
      virtual bool add_extension() const {return get_option(OFN_ADDEXTENSION);}
      /// @brief Sets a value indicating whether the dialog box automatically adds an extension to a file name if the user omits the extension.
      /// @param value true if the dialog box adds an extension to a file name if the user omits the extension; otherwise, false. The default value is true.
      /// @return Current file_dialog.
      virtual file_dialog& add_extension(bool value) {
        set_option(OFN_ADDEXTENSION, value);
        return *this;
      }

      /// @brief Gets a value indicating whether this file_dialog instance should automatically upgrade appearance and behavior when running on Windows Vista.
      /// @return true if this file_dialog instance should automatically upgrade appearance and behavior when running on Windows Vista; otherwise, false. The default is true.
      /// @remarks If this property is false, the file_dialog class will have a Windows XP-style appearance and behavior on Windows Vista.
      /// @remarks On Windows XP, this property does not have any effect.
      virtual bool auto_upgrade_enabled() const {return auto_upgrade_enabled_;}
      /// @brief Sets a value indicating whether this file_dialog instance should automatically upgrade appearance and behavior when running on Windows Vista.
      /// @param value true if this file_dialog instance should automatically upgrade appearance and behavior when running on Windows Vista; otherwise, false. The default is true.
      /// @return Current file_dialog.
      /// @remarks If this property is false, the file_dialog class will have a Windows XP-style appearance and behavior on Windows Vista.
      /// @remarks On Windows XP, this property does not have any effect.
      virtual file_dialog& auto_upgrade_enabled(bool value) {
        auto_upgrade_enabled_ = value;
        return *this;
      }

      /// @brief Gets a value indicating whether the dialog box displays a warning if the user specifies a file name that does not exist.
      /// @return true if the dialog box displays a warning if the user specifies a file name that does not exist; otherwise, false. The default value is false.
      /// @remarks The default value is true for an inheriting open_file_dialog and false for an inheriting save_file_dialog.
      virtual bool check_file_exists() const {return get_option(OFN_FILEMUSTEXIST);}
      /// @brief Sets a value indicating whether the dialog box displays a warning if the user specifies a file name that does not exist.
      /// @param value true if the dialog box displays a warning if the user specifies a file name that does not exist; otherwise, false. The default value is false.
      /// @return Current file_dialog.
      /// @remarks The default value is true for an inheriting open_file_dialog and false for an inheriting save_file_dialog.
      virtual file_dialog& check_file_exists(bool value) {
        set_option(OFN_FILEMUSTEXIST, value);
        return *this;
      }
      
      /// @brief Gets a value indicating whether the dialog box displays a warning if the user specifies a path that does not exist.
      /// @return true if the dialog box displays a warning when the user specifies a path that does not exist; otherwise, false. The default value is true.
      virtual bool check_path_exists() const {return get_option(OFN_PATHMUSTEXIST);}
      /// @brief Sets a value indicating whether the dialog box displays a warning if the user specifies a path that does not exist.
      /// @param value true if the dialog box displays a warning when the user specifies a path that does not exist; otherwise, false. The default value is true.
      /// @return Current file_dialog.
      virtual file_dialog& check_path_exists(bool value) {
        set_option(OFN_PATHMUSTEXIST, value);
        return *this;
      }
      
      /// @brief Gets the default file name extension.
      /// @return The default file name extension. The returned string does not include the period. The default value is an empty string ("").
      /// @remarks When the user of your application specifies a file name without an extension, the file_dialog appends an extension to the file name. The extension that is used is determined by the filter and default_ext properties. If a filter is selected in the file_dialog and the filter specifies an extension, then that extension is used. If the filter selected uses a wildcard in place of the extension, then the extension specified in the default_ext property is used.
      virtual const xtd::ustring& default_ext() const {return default_ext_;}
      /// @brief Sets the default file name extension.
      /// @param value The default file name extension. The returned string does not include the period. The default value is an empty string ("").
      /// @remarks When the user of your application specifies a file name without an extension, the file_dialog appends an extension to the file name. The extension that is used is determined by the filter and default_ext properties. If a filter is selected in the file_dialog and the filter specifies an extension, then that extension is used. If the filter selected uses a wildcard in place of the extension, then the extension specified in the default_ext property is used.
      /// @return Current file_dialog.
      virtual file_dialog& default_ext(const xtd::ustring& value) {
        default_ext_ = value;
        return *this;
      }

      /// @brief Gets a value indicating whether the dialog box returns the location of the file referenced by the shortcut or whether it returns the location of the shortcut (.lnk).
      /// @return true if the dialog box returns the location of the file referenced by the shortcut; otherwise, false. The default value is true.
      virtual bool dereference_link() const {return !get_option(OFN_NODEREFERENCELINKS);}
      /// @brief Sets a value indicating whether the dialog box returns the location of the file referenced by the shortcut or whether it returns the location of the shortcut (.lnk).
      /// @param value true if the dialog box returns the location of the file referenced by the shortcut; otherwise, false. The default value is true.
      /// @return Current file_dialog.
      virtual file_dialog& dereference_link(bool value) {
        set_option(OFN_NODEREFERENCELINKS, !value);
        return *this;
      }
      
      /// @brief Gets a string containing the file name selected in the file dialog box.
      /// @return The file name selected in the file dialog box. The default value is an empty string ("").
      /// @remarks The file name includes both the file path and the extension. If no files are selected, this method returns an empty string ("").
      /// @remarks When used from the save_file_dialog class, this property represents the file being saved; when used from the open_file_dialog class, it represents the file being opened.
      /// @remarks This property can only be the name of one selected file. If you want to return an array containing the names of all selected files in a multiple-selection dialog box, use file_names.
      virtual const xtd::ustring& file_name() const {return file_name_;}
      /// @brief Sets a string containing the file name selected in the file dialog box.
      /// @param value The file name selected in the file dialog box. The default value is an empty string ("").
      /// @return Current file_dialog.
      /// @remarks The file name includes both the file path and the extension. If no files are selected, this method returns an empty string ("").
      /// @remarks When used from the save_file_dialog class, this property represents the file being saved; when used from the open_file_dialog class, it represents the file being opened.
      /// @remarks This property can only be the name of one selected file. If you want to return an array containing the names of all selected files in a multiple-selection dialog box, use file_names.
      virtual file_dialog& file_name(const xtd::ustring& value) {
        file_name_ = value;
        return *this;
      }

      /// @brief Gets the file names of all selected files in the dialog box.
      /// @return An array of type string, containing the file names of all selected files in the dialog box.
      /// @remarks Each file name includes both the file path and the extension. If no files are selected, this method returns an empty array.
      virtual const std::vector<xtd::ustring> file_names() const {return file_names_;}

      /// @brief Gets the current file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box.
      /// @return The file filtering options available in the dialog box.
      /// @remarks For each filtering option, the filter string contains a description of the filter, followed by the vertical bar (|) and the filter pattern. The strings for different filtering options are separated by the vertical bar.
      /// @remarks The following is an example of a filter string:
      /// @verbatim Text files (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @remarks You can add several filter patterns to a filter by separating the file types with semicolons, for example:
      /// @verbatim Image Files(*.BMP;*.JPG;*.GIF)|*.BMP;*.JPG;*.GIF|All files (*.*)|*.* @endverbatim
      /// @remarks Use the filter_index property to set which filtering option is shown first to the user.
      virtual const xtd::ustring& filter() const {return filter_;}
      /// @brief Sets the current file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box.
      /// @param value The file filtering options available in the dialog box.
      /// @return Current file_dialog.
      /// @remarks For each filtering option, the filter string contains a description of the filter, followed by the vertical bar (|) and the filter pattern. The strings for different filtering options are separated by the vertical bar.
      /// @remarks The following is an example of a filter string:
      /// @verbatim Text files (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @remarks You can add several filter patterns to a filter by separating the file types with semicolons, for example:
      /// @verbatim Image Files(*.BMP;*.JPG;*.GIF)|*.BMP;*.JPG;*.GIF|All files (*.*)|*.* @endverbatim
      /// @remarks Use the filter_index property to set which filtering option is shown first to the user.
      virtual file_dialog& filter(const xtd::ustring& value) {
        filter_ = value;
        return *this;
      }

      /// @brief Gets the index of the filter currently selected in the file dialog box.
      /// @return A value containing the index of the filter currently selected in the file dialog box. The default value is 1.
      /// @remarks Use the filter_index property to set which filtering option is shown first to the user. You can also use the value of filter_index after showing the file dialog to perform special file operations depending upon the filter chosen.
      /// @note The index value of the first filter entry is 1.
      virtual size_t filter_index() const {return filter_index_;}
      /// @brief Sets the index of the filter currently selected in the file dialog box.
      /// @param value A value containing the index of the filter currently selected in the file dialog box. The default value is 1.
      /// @return Current file_dialog.
      /// @remarks Use the filter_index property to set which filtering option is shown first to the user. You can also use the value of filter_index after showing the file dialog to perform special file operations depending upon the filter chosen.
      /// @note The index value of the first filter entry is 1.
      virtual file_dialog& filter_index(size_t value) {
        filter_index_ = value;
        return *this;
      }

      /// @brief Gets the initial directory displayed by the file dialog box.
      /// @return The initial directory displayed by the file dialog box. The default is an empty string ("").
      /// @remarks The InitialDirectory property is typically set using one of the following sources:
      /// * A path that was previously used in the program, perhaps retained from the last directory or file operation.
      /// * A path read from a persistent source, such as an application setting, a Registry or a string resource in the application.
      /// * Standard Windows, macOs or linux system and user paths, such as Program Files, MyDocuments, MyMusic, and so on (which you can obtain using the xtd::environment::get_folder_path method)
      /// * A path related to the current application, such as its startup directory (which you can obtain using properties on the xtd::forms::application object).
      virtual const xtd::ustring& initial_directory() const {return initial_directory_;}
      /// @brief Sets the initial directory displayed by the file dialog box.
      /// @param value The initial directory displayed by the file dialog box. The default is an empty string ("").
      /// @return Current file_dialog.
      /// @remarks The InitialDirectory property is typically set using one of the following sources:
      /// * A path that was previously used in the program, perhaps retained from the last directory or file operation.
      /// * A path read from a persistent source, such as an application setting, a Registry or a string resource in the application.
      /// * Standard Windows, macOs or linux system and user paths, such as Program Files, MyDocuments, MyMusic, and so on (which you can obtain using the xtd::environment::get_folder_path method)
      /// * A path related to the current application, such as its startup directory (which you can obtain using properties on the xtd::forms::application object).
      virtual file_dialog& initial_directory(const xtd::ustring& value) {
        initial_directory_ = value;
        return *this;
      }
      
      /// @brief Gets values to initialize the file_dialog.
      /// @return A bitwise combination of internal values that initializes the file_dialog.
      /// @return The options property corresponds to the flags used to initialize a color dialog box using Win32. Use the properties of the file_dialog class to get and set the options.
      size_t options() const {return options_;}

      /// @brief Gets a value indicating whether the dialog box restores the directory to the previously selected directory before closing.
      /// @return true if the dialog box restores the current directory to the previously selected directory if the user changed the directory while searching for files; otherwise, false. The default value is false.
      virtual bool restore_directory() const {return get_option(OFN_NOCHANGEDIR);}
      /// @brief Sets a value indicating whether the dialog box restores the directory to the previously selected directory before closing.
      /// @param value true if the dialog box restores the current directory to the previously selected directory if the user changed the directory while searching for files; otherwise, false. The default value is false.
      /// @return Current file_dialog.
      virtual file_dialog& restore_directory(bool value) {
        set_option(OFN_NOCHANGEDIR, value);
        return *this;
      }
      
      /// @brief Gets a value indicating whether the Help button is displayed in the file dialog box.
      /// @return true if the dialog box includes a help button; otherwise, false. The default value is false.
      /// @remarks A help_requested event is raised when the user clicks the Help button.
      virtual bool show_help() const {return !get_option(OFN_SHOWHELP);}
      /// @brief Sets a value indicating whether the Help button is displayed in the file dialog box.
      /// @param value true if the dialog box includes a help button; otherwise, false. The default value is false.
      /// @return Current file_dialog.
      /// @remarks A help_requested event is raised when the user clicks the Help button.
      virtual file_dialog& show_help(bool value) {
        set_option(OFN_SHOWHELP, value);
        return *this;
      }
      
      /// @brief Gets a value indicating whether hidden files are displayed in the file dialog box.
      /// @return true if the dialog box includes hidden files; otherwise, false. The default value is false.
      virtual bool show_hidden_files() const {return !get_option(OFN_FORCESHOWHIDDEN);}
      /// @brief Sets a value indicating whether hidden files are displayed in the file dialog box.
      /// @param value true if the dialog box includes hidden files; otherwise, false. The default value is false.
      /// @return Current file_dialog.
      virtual file_dialog& show_hidden_files(bool value) {
        set_option(OFN_FORCESHOWHIDDEN, value);
        return *this;
      }
      
      /// @brief Gets a value indicating whether preview file is displayed in the file dialog box.
      /// @return true if the dialog box includes preview file; otherwise, false. The default value is false.
      virtual bool show_preview() const {return !get_option(OFN_SHOWPREVIEW);}
      /// @brief Sets a value indicating whether preview file is displayed in the file dialog box.
      /// @param value true if the dialog box includes preview file; otherwise, false. The default value is false.
      /// @return Current file_dialog.
      virtual file_dialog& show_preview(bool value) {
        set_option(OFN_SHOWPREVIEW, value);
        return *this;
      }

      /// @brief Gets whether the dialog box supports displaying and saving files that have multiple file name extensions.Gets or sets whether the dialog box supports displaying and saving files that have multiple file name extensions.
      /// @return true if the dialog box supports multiple file name extensions; otherwise, false. The default is false.
      /// @remarks Sometimes users must open and save files that use multiple file name extensions. For example, the application manifest files used by the click_once deployment technology end in the complex file name extension ".exe.manifest". Setting this property to true enables you to set the FFilter property to a multi-dotted extension.
      /// @remarks If support_multi_dotted_extensions is false, and you assign a multi-dotted extension to Filter, derived controls such as save_file_dialog will only use the last extension in the string. For example, ".manifest" will be used instead of ".exe.manifest".
      virtual bool support_multi_dotted_extensions() const {return support_multi_dotted_extensions_;}
      /// @brief Sets whether the dialog box supports displaying and saving files that have multiple file name extensions.Gets or sets whether the dialog box supports displaying and saving files that have multiple file name extensions.
      /// @param value true if the dialog box supports multiple file name extensions; otherwise, false. The default is false.
      /// @return Current file_dialog.
      /// @remarks Sometimes users must open and save files that use multiple file name extensions. For example, the application manifest files used by the click_once deployment technology end in the complex file name extension ".exe.manifest". Setting this property to true enables you to set the FFilter property to a multi-dotted extension.
      /// @remarks If support_multi_dotted_extensions is false, and you assign a multi-dotted extension to Filter, derived controls such as save_file_dialog will only use the last extension in the string. For example, ".manifest" will be used instead of ".exe.manifest".
      virtual file_dialog& support_multi_dotted_extensions(bool value) {
        support_multi_dotted_extensions_ = value;
        return *this;
      }
      
      /// @brief Gets the file dialog box title.
      /// @return The file dialog box title. The default value is an empty string ("").
      /// @remarks The string is placed in the title bar of the dialog box. If the title is an empty string, the system uses a default title, which is either "Save As" or "Open".
      virtual const xtd::ustring& title() const {return title_;}
      /// @brief Sets the file dialog box title.
      /// @param value The file dialog box title. The default value is an empty string ("").
      /// @return Current file_dialog.
      /// @remarks The string is placed in the title bar of the dialog box. If the title is an empty string, the system uses a default title, which is either "Save As" or "Open".
      virtual file_dialog& title(const xtd::ustring& value) {
        title_ = value;
        return *this;
      }
      
      /// @brief Gets a value indicating whether the dialog box accepts only valid file names.
      /// @return true if the dialog box accepts only valid file names; otherwise, false. The default value is true.
      /// @remarks If the edit control contains anything but spaces when the user clicks OK, the dialog box returns the file name, whether it is valid or not. No default extension is added to the text.
      virtual bool validate_names() const {return !get_option(OFN_NOVALIDATE);}
      /// @brief Gets a value indicating whether the dialog box accepts only valid file names.
      /// @param value true if the dialog box accepts only valid file names; otherwise, false. The default value is true.
      /// @return Current file_dialog.
      /// @remarks If the edit control contains anything but spaces when the user clicks OK, the dialog box returns the file name, whether it is valid or not. No default extension is added to the text.
      virtual file_dialog& validate_names(bool value) {
        set_option(OFN_NOVALIDATE, !value);
        return *this;
      }

      /// @brief Resets all properties to their default values.
      /// @remarks When overriding reset() in a derived class, be sure to call the base class's reset() method.
      void reset() override;

      /// @brief Provides a string version of this object.
      /// @return A string version of this object.
      xtd::ustring to_string() const noexcept override {
        return ustring::format("{}: title: {}, filename: {}", ustring::full_class_name(*this), title_, file_name_);
      }

      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::forms::file_dialog& dialog) noexcept {
        return os << dialog.to_string();
      }
      /// @endcond

    protected:      
      /// @brief Runs file dialog box.
      /// @param hwnd_owner A value that represents the window handle of the owner window for the common dialog box.
      /// @return true if the file could be opened; otherwise, false.
      /// @remarks This method provides an implementation of run_dialog, and is invoked when the user of a file dialog invokes show_dialog.
      bool run_dialog(intptr_t hwnd_owner) override;
      /// @brief Runs file dialog box in sheet mode.
      /// @param hwnd_owner A value that represents the window handle of the owner window for the common dialog box.
      void run_sheet(intptr_t hwnd_owner) override;

      /// @cond
      bool get_option(size_t flag) const {return (options_ & flag) == flag;}
      void set_option(size_t flag, bool value) {options_ = value ? options_ | flag : options_ & ~flag;}

      bool auto_upgrade_enabled_ = true;
      xtd::ustring default_ext_ = "";
      xtd::ustring file_name_ = "";
      std::vector<xtd::ustring> file_names_;
      xtd::ustring filter_ = "";
      size_t filter_index_ = 1;
      xtd::ustring initial_directory_ = "";
      size_t options_ = OFN_HIDEREADONLY | OFN_PATHMUSTEXIST | OFN_ADDEXTENSION;
      bool support_multi_dotted_extensions_ = true;
      xtd::ustring title_ = "";
      /// @endcond
      
    private:
      friend class open_file_dialog;
      friend class save_file_dialog;
      virtual bool run_file_dialog(intptr_t hwnd_owner) = 0;
      virtual void run_file_sheet(intptr_t hwnd_owner) = 0;
    };
  }
}

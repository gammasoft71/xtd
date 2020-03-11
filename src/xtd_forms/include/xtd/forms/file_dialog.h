#pragma once
#include "common_dialog.h"
#include <vector>
#include <xtd/forms/file_dialog_flags.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
  /// @cond
    class open_file_dialog;
    class save_file_dialog;
  /// @endcond

    /// @brief Displays a dialog box from which the user can select a file.
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
    class file_dialog : public common_dialog {
    public:
      /// @brief Initializes a new instance of the common_dialog class.
      file_dialog() = default;
      
      /// @brief Gets a value indicating whether the dialog box automatically adds an extension to a file name if the user omits the extension.
      /// @return true if the dialog box adds an extension to a file name if the user omits the extension; otherwise, false. The default value is true.
      virtual bool add_extension() const {return get_option(OFN_ADDEXTENSION);}
      /// @brief Sets a value indicating whether the dialog box automatically adds an extension to a file name if the user omits the extension.
      /// @param value true if the dialog box adds an extension to a file name if the user omits the extension; otherwise, false. The default value is true.
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
      /// @remarks The default value is true for an inheriting open_file_dialog and false for an inheriting save_file_dialog.
      virtual file_dialog& check_file_exists(bool value) {
        set_option(OFN_FILEMUSTEXIST, value);
        return *this;
      }
      
      virtual bool check_path_exists() const {return get_option(OFN_PATHMUSTEXIST);}
      virtual file_dialog& check_path_exists(bool value) {
        set_option(OFN_PATHMUSTEXIST, value);
        return *this;
      }
      
      virtual const std::string& default_ext() const {return default_ext_;}
      virtual file_dialog& default_ext(const std::string& value) {
        default_ext_ = value;
        return *this;
      }

      virtual bool dereference_link() const {return !get_option(OFN_NODEREFERENCELINKS);}
      virtual file_dialog& dereference_link(bool value) {
        set_option(OFN_NODEREFERENCELINKS, !value);
        return *this;
      }
      
      virtual const std::string& file_name() const {return file_name_;}
      virtual file_dialog& file_name(const std::string& value) {
        file_name_ = value;
        return *this;
      }

      virtual const std::vector<std::string> file_names() const {return file_names_;}

      virtual const std::string& filter() const {return filter_;}
      virtual file_dialog& filter(const std::string& value) {
        filter_ = value;
        return *this;
      }

      virtual size_t filter_index() const {return filter_index_;}
      virtual file_dialog& filter_index(size_t value) {
        filter_index_ = value;
        return *this;
      }

      virtual const std::string& initial_directory() const {return initial_directory_;}
      virtual file_dialog& initial_directory(const std::string& value) {
        initial_directory_ = value;
        return *this;
      }
      
      virtual bool multiselect() const {return get_option(OFN_ALLOWMULTISELECT);}
      virtual file_dialog& multiselect(bool value) {
        set_option(OFN_ALLOWMULTISELECT, value);
        return *this;
      }
      
      /// @return Gets values to initialize the file_dialog.
      /// @return A bitwise combination of internal values that initializes the file_dialog.
      /// @return The options property corresponds to the flags used to initialize a color dialog box using Win32. Use the properties of the file_dialog class to get and set the options.
      size_t options() const {return this->options_;}

      virtual bool restore_directory() const {return get_option(OFN_NOCHANGEDIR);}
      virtual file_dialog& restore_directory(bool value) {
        set_option(OFN_NOCHANGEDIR, value);
        return *this;
      }
      
      virtual bool show_help() const {return !get_option(OFN_SHOWHELP);}
      virtual file_dialog& show_help(bool value) {
        set_option(OFN_SHOWHELP, value);
        return *this;
      }
      
      virtual bool show_hidden_files() const {return !get_option(OFN_FORCESHOWHIDDEN);}
      virtual file_dialog& show_hidden_files(bool value) {
        set_option(OFN_FORCESHOWHIDDEN, value);
        return *this;
      }
      
      virtual bool show_preview() const {return !get_option(OFN_SHOWPREVIEW);}
      virtual file_dialog& show_preview(bool value) {
        set_option(OFN_SHOWPREVIEW, value);
        return *this;
      }

      virtual bool support_multi_dotted_extensions() const {return support_multi_dotted_extensions_;}
      virtual file_dialog& support_multi_dotted_extensions(bool value) {
        support_multi_dotted_extensions_ = value;
        return *this;
      }
      
      virtual const std::string& title() const {return title_;}
      virtual file_dialog& title(const std::string& value) {
        title_ = value;
        return *this;
      }
      
      virtual bool validate_names() const {return !get_option(OFN_NOVALIDATE);}
      virtual file_dialog& validate_names(bool value) {
        set_option(OFN_NOVALIDATE, !value);
        return *this;
      }

      /// @brief Resets all properties to their default values.
      /// @remarks When overriding reset() in a derived class, be sure to call the base class's reset() method.
      void reset() override;
      
      bool run_dialog (intptr_t hwnd_owner) override;
      
      std::string to_string() const {
        return strings::format("{}: title: {}, filename: {}", strings::full_class_name(*this), title_, file_name_);
      }

      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::forms::file_dialog& dialog) noexcept {
        return os << dialog.to_string();
      }
      /// @endcond

    protected:
      /// @cond
      bool get_option(size_t flag) const {return (this->options_ & flag) == flag;}
      void set_option(size_t flag, bool value) {this->options_ = value ? this->options_ | flag : this->options_ & ~flag;}

      bool auto_upgrade_enabled_ = true;
      std::string default_ext_ = "";
      std::string file_name_ = "";
      std::vector<std::string> file_names_;
      std::string filter_ = "";
      size_t filter_index_ = 1;
      std::string initial_directory_ = "";
      size_t options_ = OFN_HIDEREADONLY | OFN_PATHMUSTEXIST | OFN_ADDEXTENSION;
      bool support_multi_dotted_extensions_ = true;
      std::string title_ = "";
      /// @endcond
      
    private:
      friend class open_file_dialog;
      friend class save_file_dialog;
      virtual bool run_file_dialog(intptr_t hwnd_owner) = 0;
    };
  }
}

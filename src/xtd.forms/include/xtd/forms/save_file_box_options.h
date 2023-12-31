/// @file
/// @brief Contains xtd::forms::save_file_box_options control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies options on a xtd::forms::save_file_box.
    /// @par Header
    /// @code #include <xtd/forms/save_file_box_options> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by the xtd::forms::save_file_box class.
    enum class save_file_box_options {
      /// @brief No options.
      none = 0b0,
      /// @brief Whether the dialog box displays a warning if the user specifies a file name that does not exist.
      check_file_exists = 0b1,
      /// @brief Whether the dialog box returns the location of the file referenced by the shortcut (.lnk).
      dereference_link = 0b10,
      /// @brief Whether the dialog box accepts only valid file names.
      validate_names = 0b100,
      /// @brief Whether the dialog box restores the directory to the previously selected directory before closing.
      restore_directory = 0b1000,
      /// @brief Whether this xtd::forms::file_dialog instance should automatically upgrade appearance and behavior when running on Windows Vista.
      enable_auto_upgrade = 0b10000,
      /// @brief Whether hidden files are displayed in the file dialog box.
      show_hidden_files = 0b100000,
      /// @brief Whether the Help button is displayed in the file dialog box.
      show_help = 0b1000000,
      /// @brief Whether preview file is displayed in the file dialog box.
      show_preview = 0b10000000,
      /// @brief Whether the dialog box supports displaying and saving files that have multiple file name extensions.
      support_multi_dotted_extensions = 0b100000000,
      /// @brief All flags except none.
      all = check_file_exists | dereference_link | validate_names | restore_directory | enable_auto_upgrade | show_hidden_files | show_help | show_preview | support_multi_dotted_extensions
    };
  }
}

/// @cond
flags_attribute_(xtd::forms, save_file_box_options);

template<> struct xtd::enum_register<xtd::forms::save_file_box_options> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::save_file_box_options> {{xtd::forms::save_file_box_options::none, "none"}, {xtd::forms::save_file_box_options::check_file_exists, "check_file_exists"}, {xtd::forms::save_file_box_options::dereference_link, "dereference_link"}, {xtd::forms::save_file_box_options::validate_names, "validate_names"}, {xtd::forms::save_file_box_options::restore_directory, "restore_directory"}, {xtd::forms::save_file_box_options::enable_auto_upgrade, "enable_auto_upgrade"}, {xtd::forms::save_file_box_options::show_hidden_files, "show_hidden_files"}, {xtd::forms::save_file_box_options::show_help, "show_help"}, {xtd::forms::save_file_box_options::show_preview, "show_preview"}, {xtd::forms::save_file_box_options::support_multi_dotted_extensions, "support_multi_dotted_extensions"}, {xtd::forms::save_file_box_options::all, "all"}};}
};
/// @endcond

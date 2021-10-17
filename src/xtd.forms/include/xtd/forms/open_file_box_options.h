/// @file
/// @brief Contains xtd::forms::open_file_box_options control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies options on a xtd::forms::open_file_box.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by the xtd::forms::open_file_dialog class.
    enum class open_file_box_options {
      /// @brief Single line text box.
      none = 0x0000,
      /// @brief Whether the dialog box displays a warning if the user specifies a file name that does not exist.
      check_file_exists = 1 << 0,
      /// @brief Whether the dialog box returns the location of the file referenced by the shortcut (.lnk).
      dereference_link = 1 << 1,
      /// @brief Whether the dialog box accepts only valid file names.
      validate_names = 1 << 2,
      /// @brief Whether the dialog box restores the directory to the previously selected directory before closing.
      restore_directory = 1 << 3,
      /// @brief Whether this file_dialog instance should automatically upgrade appearance and behavior when running on Windows Vista.
      enable_auto_upgrade = 1 << 4,
      /// @brief Whether hidden files are displayed in the file dialog box.
      show_hidden_files = 1 << 5,
      /// @brief Whether the Help button is displayed in the file dialog box.
      show_help = 1 << 6,
      /// @brief Whether preview file is displayed in the file dialog box.
      show_preview = 1 << 7,
      /// @brief Whether the dialog box supports displaying and saving files that have multiple file name extensions.
      support_multi_dotted_extensions = 1 << 8,
      /// @brief All flags except none.
      all = check_file_exists | dereference_link | validate_names | restore_directory | enable_auto_upgrade | show_hidden_files | show_help | show_preview | support_multi_dotted_extensions
    };

    /// @cond
    inline open_file_box_options& operator +=(open_file_box_options& lhs, open_file_box_options rhs) noexcept { lhs = static_cast<open_file_box_options>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); return lhs; }
    inline open_file_box_options& operator -=(open_file_box_options& lhs, open_file_box_options rhs) noexcept { lhs = static_cast<open_file_box_options>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); return lhs; }
    inline open_file_box_options& operator &=(open_file_box_options& lhs, open_file_box_options rhs) noexcept { lhs = static_cast<open_file_box_options>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); return lhs; }
    inline open_file_box_options& operator |=(open_file_box_options& lhs, open_file_box_options rhs) noexcept { lhs = static_cast<open_file_box_options>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); return lhs; }
    inline open_file_box_options& operator ^=(open_file_box_options& lhs, open_file_box_options rhs) noexcept { lhs = static_cast<open_file_box_options>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); return lhs; }
    inline open_file_box_options operator +(open_file_box_options lhs, open_file_box_options rhs) noexcept { return static_cast<open_file_box_options>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); }
    inline open_file_box_options operator -(open_file_box_options lhs, open_file_box_options rhs) noexcept { return static_cast<open_file_box_options>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); }
    inline open_file_box_options operator ~(open_file_box_options rhs) noexcept { return static_cast<open_file_box_options>(~static_cast<long long>(rhs)); }
    inline bool operator &(open_file_box_options lhs, open_file_box_options rhs) noexcept { return static_cast<bool>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); }
    inline open_file_box_options operator |(open_file_box_options lhs, open_file_box_options rhs) noexcept { return static_cast<open_file_box_options>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); }
    inline open_file_box_options operator ^(open_file_box_options lhs, open_file_box_options rhs) noexcept { return static_cast<open_file_box_options>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); }
    inline std::ostream& operator<<(std::ostream& os, open_file_box_options value) { return os << to_string(value, { {open_file_box_options::none, "none"}, {open_file_box_options::check_file_exists, "check_file_exists"}, {open_file_box_options::validate_names, "validate_names"}, {open_file_box_options::restore_directory, "restore_directory"}, {open_file_box_options::enable_auto_upgrade, "enable_auto_upgrade"}, {open_file_box_options::show_hidden_files, "show_hidden_files"}, {open_file_box_options::show_help, "show_help"}, {open_file_box_options::show_preview, "show_preview"}, {open_file_box_options::support_multi_dotted_extensions, "support_multi_dotted_extensions"} }); }
    inline std::wostream& operator<<(std::wostream& os, open_file_box_options value) { return os << to_string(value, { {open_file_box_options::none, L"none"}, {open_file_box_options::check_file_exists, L"check_file_exists"}, {open_file_box_options::validate_names, L"validate_names"}, {open_file_box_options::restore_directory, L"restore_directory"}, {open_file_box_options::enable_auto_upgrade, L"enable_auto_upgrade"}, {open_file_box_options::show_hidden_files, L"show_hidden_files"}, {open_file_box_options::show_help, L"show_help"}, {open_file_box_options::show_preview, L"show_preview"}, {open_file_box_options::support_multi_dotted_extensions, L"support_multi_dotted_extensions"} }); }
    /// @endcond
  }
}
/// @file
/// @brief Contains xtd::forms::open_file_dialog dialog.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/io/file.h>
#include "file_dialog.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Displays a standard dialog box that prompts the user to open a file. This class cannot be inherited.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
    ///   <tr>
    ///     <th style="width:100px"></th>
    ///     <th><b>Windows</b></th>
    ///     <th><b>macOS</b></th>
    ///     <th><b>Gnome</b></th>
    ///   </tr>
    ///   <tr>
    ///     <th>Light</th>
    ///     <td>@image html dialog_open_file_dialog_w.png</td>
    ///     <td>@image html dialog_open_file_dialog_m.png</td>
    ///     <td>@image html dialog_open_file_dialog_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <th>Dark</th>
    ///     <td>@image html dialog_open_file_dialog_wd.png</td>
    ///     <td>@image html dialog_open_file_dialog_md.png</td>
    ///     <td>@image html dialog_open_file_dialog_gd.png</td>
    ///   </tr>
    /// </table>
    /// @par Examples
    /// The following code example demonstrates the use of open_file_dialog dialog.
    /// @include open_file_dialog.cpp
    class forms_export_ open_file_dialog final : public file_dialog {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the open_file_dialog class.
      open_file_dialog() = default;
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Opens the file with read only permission selected by the user.
      /// @return The read only file selected by the user.
      std::ifstream open_file() const noexcept;
      
      /// @brief Gets a value indicating whether the dialog box allows multiple files to be selected.
      /// @return true if the dialog box allows multiple files to be selected together or concurrently; otherwise, false. The default value is false.
      /// @remarks Use the file_names property to access the full list of selected file names.
      virtual bool multiselect() const noexcept;
      /// @brief Sets a value indicating whether the dialog box allows multiple files to be selected.
      /// @param value true if the dialog box allows multiple files to be selected together or concurrently; otherwise, false. The default value is false.
      /// @return Current open_file_dialog.
      /// @remarks Use the file_names property to access the full list of selected file names.
      virtual open_file_dialog& multiselect(bool value);
      /// @}
      
    private:
      bool run_file_dialog(intptr hwnd_owner) override;
      void run_file_sheet(intptr owner) override;
    };
  }
}

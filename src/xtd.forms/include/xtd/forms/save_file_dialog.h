/// @file
/// @brief Contains xtd::forms::save_file_dialog dialog.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/io/file.h>
#include "file_dialog.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Prompts the user to select a location for saving a file. This class cannot be inherited.
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
    ///     <td>@image html dialog_save_file_dialog_w.png</td>
    ///     <td>@image html dialog_save_file_dialog_m.png</td>
    ///     <td>@image html dialog_save_file_dialog_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <th>Dark</th>
    ///     <td>@image html dialog_save_file_dialog_wd.png</td>
    ///     <td>@image html dialog_save_file_dialog_md.png</td>
    ///     <td>@image html dialog_save_file_dialog_gd.png</td>
    ///   </tr>
    /// </table>
    /// @par Examples
    /// The following code example demonstrates the use of save_file_dialog dialog.
    /// @include save_file_dialog.cpp
    class forms_export_ save_file_dialog final : public file_dialog {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the save_file_dialog class.
      save_file_dialog() = default;
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Opens the file with read/write permission selected by the user.
      /// @return The read/write file selected by the user.
      std::fstream open_file() const noexcept;
      /// @}
      
    private:
      bool run_file_dialog(intptr hwnd_owner) override;
      void run_file_sheet(intptr owner) override;
    };
  }
}

/// @file
/// @brief Contains xtd::forms::save_file_dialog dialog.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "file_dialog.h"
#include <xtd/io/file>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Prompts the user to select a location for saving a file. This class cannot be inherited.
    /// @par Header
    /// @code #include <xtd/forms/save_file_dialog> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                      | macOS                                        | Gnome                                        |
    /// | ----- | -------------------------------------------- | -------------------------------------------- | -------------------------------------------- |
    /// | Light |  @image html dialog_save_file_dialog_w.png   |  @image html dialog_save_file_dialog_m.png   |  @image html dialog_save_file_dialog_g.png   |
    /// | Dark  |  @image html dialog_save_file_dialog_wd.png  |  @image html dialog_save_file_dialog_md.png  |  @image html dialog_save_file_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of save_file_dialog dialog.
    /// @include save_file_dialog.cpp
    class forms_export_ save_file_dialog final : public file_dialog {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the save_file_dialog class.
      save_file_dialog() = default;
      /// @}
      
      /// @name Public Properties
      
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

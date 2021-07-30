/// @file
/// @brief Contains xtd::forms::save_file_dialog dialog.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/io/file.h>
#include "file_dialog.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Prompts the user to select a location for saving a file. This class cannot be inherited.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Examples
    /// The following code example demonstrate the use of save_file_dialog dialog.
    /// @include save_file_dialog.cpp
    /// @par Windows
    /// @image html save_file_dialog_w.png
    /// <br>
    /// @image html save_file_dialog_wd.png
    /// @par macOS
    /// @image html save_file_dialog_m.png
    /// <br>
    /// @image html save_file_dialog_md.png
    /// @par Gnome
    /// @image html save_file_dialog_g.png
    /// <br>
    /// @image html save_file_dialog_gd.png
    class forms_export_ save_file_dialog final : public file_dialog {
    public:
      /// @brief Initializes a new instance of the save_file_dialog class.
      save_file_dialog() = default;
      
      /// @brief Opens the file with read/write permission selected by the user.
      /// @return The read/write file selected by the user.
      std::fstream open_file() const {return io::file::open(xtd::ustring(file_name_), std::ios::binary | std::ios::in | std::ios::out);}

    private:
      bool run_file_dialog(intptr_t hwnd_owner) override;
      void run_file_sheet(intptr_t owner) override;
    };
  }
}

/// @file
/// @brief Contains xtd::forms::open_file_dialog dialog.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/io/file.h>
#include "file_dialog.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Displays a standard dialog box that prompts the user to open a file. This class cannot be inherited.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Examples
    /// The following code example demonstrate the use of open_file_dialog dialog.
    /// @include open_file_dialog.cpp
    /// @par Windows
    /// @image html open_file_dialog_w.png
    /// <br>
    /// @image html open_file_dialog_wd.png
    /// @par macOS
    /// @image html open_file_dialog_m.png
    /// <br>
    /// @image html open_file_dialog_md.png
    /// @par Gnome
    /// @image html open_file_dialog_g.png
    /// <br>
    /// @image html open_file_dialog_gd.png
    class forms_export_ open_file_dialog final : public file_dialog {
    public:
      /// @brief Initializes a new instance of the open_file_dialog class.
      open_file_dialog() = default;
      
      /// @brief Opens the file with read only permission selected by the user.
      /// @return The read only file selected by the user.
      std::ifstream open_file() const {return io::file::open_read(file_name_);}
      
    private:
      bool run_file_dialog(intptr_t hwnd_owner) override;
      void run_file_sheet(intptr_t owner) override;
    };
  }
}

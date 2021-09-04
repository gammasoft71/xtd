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
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Examples
    /// The following code example demonstrate the use of open_file_dialog dialog.
    /// @include open_file_dialog.cpp
    class forms_export_ open_file_dialog final : public file_dialog {
    public:
      /// @brief Initializes a new instance of the open_file_dialog class.
      open_file_dialog() = default;
      
      /// @brief Opens the file with read only permission selected by the user.
      /// @return The read only file selected by the user.
      std::ifstream open_file() const {return io::file::open_read(xtd::ustring(file_name_));}
 
      /// @brief Gets a value indicating whether the dialog box allows multiple files to be selected.
      /// @return true if the dialog box allows multiple files to be selected together or concurrently; otherwise, false. The default value is false.
      /// @remarks Use the file_names property to access the full list of selected file names.
      virtual bool multiselect() const {return get_option(OFN_ALLOWMULTISELECT);}
      /// @brief Sets a value indicating whether the dialog box allows multiple files to be selected.
      /// @param value true if the dialog box allows multiple files to be selected together or concurrently; otherwise, false. The default value is false.
      /// @return Current open_file_dialog.
      /// @remarks Use the file_names property to access the full list of selected file names.
      virtual open_file_dialog& multiselect(bool value) {
        set_option(OFN_ALLOWMULTISELECT, value);
        return *this;
      }

    private:
      bool run_file_dialog(intptr_t hwnd_owner) override;
      void run_file_sheet(intptr_t owner) override;
    };
  }
}

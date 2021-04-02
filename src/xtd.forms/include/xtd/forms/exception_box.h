/// @file
/// @brief Contains xtd::forms::exception_box dialog.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "exception_dialog.h"
#include "iwin32_window.h"
#include <xtd/static.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    /// @endcond

    /// @brief Represents a common dialog box that displays exception box.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Examples
    /// The following code example demonstrate the use of exception_box dialog.
    /// @include exception_box.cpp
    /// @par Windows
    /// @image html exception_box_w.png
    /// <br>
    /// @image html exception_box_wd.png
    /// @par macOS
    /// @image html exception_box_m.png
    /// <br>
    /// @image html exception_box_md.png
    /// @par Gnome
    /// @image html exception_box_g.png
    /// <br>
    /// @image html exception_box_gd.png
    class exception_box final static_ {
    public:
      static dialog_result show(const iwin32_window& owner) {return show_exception_box(&owner);}
      static dialog_result show(const iwin32_window& owner, const std::string& caption) {return show_exception_box(&owner, nullptr, caption);}
      static dialog_result show(const iwin32_window& owner, const std::exception& exception) {return show_exception_box(&owner, &exception);}
      static dialog_result show(const iwin32_window& owner, const std::exception& exception, const std::string& caption) {return show_exception_box(&owner, &exception, caption);}
      
      static dialog_result show() {return show_exception_box(nullptr);}
      static dialog_result show(const std::string& caption) {return show_exception_box(nullptr, nullptr, caption);}
      static dialog_result show(const std::exception& exception) {return show_exception_box(nullptr, &exception);}
      static dialog_result show(const std::exception& exception, const std::string& caption) {return show_exception_box(nullptr, &exception, caption);}
      
    private:
      static dialog_result show_exception_box(const iwin32_window* owner, const std::exception* exception = nullptr, const std::string& caption = "") {
        exception_dialog dialog;
        if (exception) dialog.exception(*exception);
        dialog.text(caption);
        return owner ? dialog.show_sheet_dialog(*owner) : dialog.show_dialog();
      }
    };
  }
}

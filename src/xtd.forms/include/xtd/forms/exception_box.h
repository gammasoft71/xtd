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
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Examples
    /// The following code example demonstrate the use of exception_box dialog.
    /// @include exception_box.cpp
    class exception_box final static_ {
    public:
      /// @brief Displays a exception box in front of the specified window. The exception box displays an unknown exception.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      static dialog_result show(const iwin32_window& owner) {return show_exception_box(&owner);}
      /// @brief Displays a exception box in front of the specified window. The exception box displays a specified caption and unknown exception.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param caption A string that specifies the title bar caption to display.
      static dialog_result show(const iwin32_window& owner, const xtd::ustring& caption) {return show_exception_box(&owner, nullptr, caption);}
      /// @brief Displays a exception box in front of the specified window. The exception box displays a specified exception.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param exception An exception to display.
      static dialog_result show(const iwin32_window& owner, const std::exception& exception) {return show_exception_box(&owner, &exception);}
      /// @brief Displays a exception box in front of the specified window. The exception box displays a specified exception and caption.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param exception An exception to display.
      /// @param caption A string that specifies the title bar caption to display.
      static dialog_result show(const iwin32_window& owner, const std::exception& exception, const xtd::ustring& caption) {return show_exception_box(&owner, &exception, caption);}
      
      /// @brief Displays a exception box. The exception box displays an unknown exception.
      static dialog_result show() {return show_exception_box(nullptr);}
      /// @brief Displays a exception box. The exception box displays a specified caption and unknown exception.
      /// @param caption A string that specifies the title bar caption to display.
      static dialog_result show(const xtd::ustring& caption) {return show_exception_box(nullptr, nullptr, caption);}
      /// @brief Displays a exception box. The exception box displays a specified exception.
      /// @param exception An exception to display.
      static dialog_result show(const std::exception& exception) {return show_exception_box(nullptr, &exception);}
      /// @brief Displays a exception box. The exception box displays a specified exception and caption.
      /// @param exception An exception to display.
      /// @param caption A string that specifies the title bar caption to display.
      static dialog_result show(const std::exception& exception, const xtd::ustring& caption) {return show_exception_box(nullptr, &exception, caption);}
      
    private:
      static dialog_result show_exception_box(const iwin32_window* owner, const std::exception* exception = nullptr, const xtd::ustring& caption = "") {
        exception_dialog dialog;
        if (exception) dialog.exception(*exception);
        dialog.text(caption);
        return owner ? dialog.show_sheet_dialog(*owner) : dialog.show_dialog();
      }
    };
  }
}

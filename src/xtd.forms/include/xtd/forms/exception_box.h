/// @file
/// @brief Contains xtd::forms::exception_box dialog.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.h"
#include "dialog_result.h"
#include "iwin32_window.h"
#include <xtd/static>
#include <xtd/ustring>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    /// @endcond
    
    /// @brief Represents a common dialog box that displays exception box.
    /// @par Header
    /// @code #include <xtd/forms/exception_box> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                      | macOS                                        | Gnome                                        |
    /// | ----- | -------------------------------------------- | -------------------------------------------- | -------------------------------------------- |
    /// | Light |  @image html dialog_exception_dialog_w.png   |  @image html dialog_exception_dialog_m.png   |  @image html dialog_exception_dialog_g.png   |
    /// | Dark  |  @image html dialog_exception_dialog_wd.png  |  @image html dialog_exception_dialog_md.png  |  @image html dialog_exception_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of exception_box dialog.
    /// @include exception_box.cpp
    class forms_export_ exception_box final static_ {
    public:
      /// @name Methods
      
      /// @{
      /// @brief Displays a exception box in front of the specified window. The exception box displays an unknown exception.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      static dialog_result show(const iwin32_window& owner);
      /// @brief Displays a exception box in front of the specified window. The exception box displays a specified caption and unknown exception.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param caption A string that specifies the title bar caption to display.
      static dialog_result show(const iwin32_window& owner, const xtd::ustring& caption);
      /// @brief Displays a exception box in front of the specified window. The exception box displays a specified exception.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param exception An exception to display.
      static dialog_result show(const iwin32_window& owner, const std::exception& exception);
      /// @brief Displays a exception box in front of the specified window. The exception box displays a specified exception and caption.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param exception An exception to display.
      /// @param caption A string that specifies the title bar caption to display.
      static dialog_result show(const iwin32_window& owner, const std::exception& exception, const xtd::ustring& caption);
      
      /// @brief Displays a exception box. The exception box displays an unknown exception.
      static dialog_result show();
      /// @brief Displays a exception box. The exception box displays a specified caption and unknown exception.
      /// @param caption A string that specifies the title bar caption to display.
      static dialog_result show(const xtd::ustring& caption);
      /// @brief Displays a exception box. The exception box displays a specified exception.
      /// @param exception An exception to display.
      static dialog_result show(const std::exception& exception);
      /// @brief Displays a exception box. The exception box displays a specified exception and caption.
      /// @param exception An exception to display.
      /// @param caption A string that specifies the title bar caption to display.
      static dialog_result show(const std::exception& exception, const xtd::ustring& caption);
      /// @}
      
    private:
      static dialog_result show_exception_box(const iwin32_window* owner, const std::exception* exception = nullptr, const xtd::ustring& caption = "");
    };
  }
}

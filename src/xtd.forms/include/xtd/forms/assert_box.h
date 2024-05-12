/// @file
/// @brief Contains xtd::forms::assert_box dialog.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.h"
#include "dialog_result.h"
#include "iwin32_window.h"
#include <xtd/diagnostics/stack_frame>
#include <xtd/static>
#include <xtd/ustring>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    /// @endcond
    
    /// @brief Represents a common dialog box that displays assert box.
    /// @par Header
    /// @code #include <xtd/forms/assert_box> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                   | macOS                                     | Gnome                                     |
    /// | ----- | ----------------------------------------- | ----------------------------------------- | ----------------------------------------- |
    /// | Light |  @image html dialog_assert_dialog_w.png   |  @image html dialog_assert_dialog_m.png   |  @image html dialog_assert_dialog_g.png   |
    /// | Dark  |  @image html dialog_assert_dialog_wd.png  |  @image html dialog_assert_dialog_md.png  |  @image html dialog_assert_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of assert_box dialog.
    /// @include assert_box.cpp
    class forms_export_ assert_box final static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Displays a assert box in front of the specified window. The assert box displays an unknown assert.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      static dialog_result show(const iwin32_window& owner);
      /// @brief Displays a assert box in front of the specified window. The assert box displays a specified caption and unknown assert.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param message A string that specifies the message to display.
      static dialog_result show(const iwin32_window& owner, const xtd::ustring& message);
      /// @brief Displays a assert box in front of the specified window. The assert box displays a specified assert.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param stack_frame An stack_frame to display.
      static dialog_result show(const iwin32_window& owner, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Displays a assert box in front of the specified window. The assert box displays a specified assert and caption.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param message A string that specifies the message to display.
      /// @param stack_frame An stack_frame to display.
      static dialog_result show(const iwin32_window& owner, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Displays a assert box. The assert box displays an unknown assert.
      static dialog_result show();
      /// @brief Displays a assert box. The assert box displays a specified caption and unknown assert.
      /// @param message A string that specifies the message to display.
      static dialog_result show(const xtd::ustring& message);
      /// @brief Displays a assert box. The assert box displays a specified assert.
      /// @param stack_frame An stack_frame to display.
      static dialog_result show(const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Displays a assert box. The assert box displays a specified assert and caption.
      /// @param message A string that specifies the message to display.
      /// @param stack_frame An stack_frame to display.
      static dialog_result show(const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      /// @}
      
    private:
      static dialog_result show_assert_box(const iwin32_window* owner, const xtd::ustring& message = xtd::ustring::empty_string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty());
    };
  }
}

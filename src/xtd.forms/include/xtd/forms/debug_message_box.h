/// @file
/// @brief Contains xtd::forms::debug_message_box dialog.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "application.h"
#include "message_dialog.h"
#include "message_box_icon.h"
#include "message_box_options.h"
#include "message_box_buttons.h"
#include "message_box_default_button.h"
#include <xtd/diagnostics/debug>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Displays a dialog box and write debug.
    /// @par Header
    /// @code #include <xtd/forms/debug_message_box> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs debug
    /// @par Appearance
    /// |       | Windows                                       | macOS                                         | Gnome                                         |
    /// | ----- | --------------------------------------------- | --------------------------------------------- | --------------------------------------------- |
    /// | Light |  @image html dialog_debug_message_box_w.png   |  @image html dialog_debug_message_box_m.png   |  @image html dialog_debug_message_box_g.png   |
    /// | Dark  |  @image html dialog_debug_message_box_wd.png  |  @image html dialog_debug_message_box_md.png  |  @image html dialog_debug_message_box_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of debug_message_box dialog.
    /// @include debug_message_box.cpp
    class debug_message_box static_ {
    public:
      /// @name static methods
      
      /// @{
      /// @brief Displays a message box and write debug with specified text.
      /// @param text The text to display in the message box.
      static xtd::forms::dialog_result show(const xtd::ustring& text) {return show_message_dialog(nullptr, text, xtd::forms::application::product_name(), xtd::forms::message_box_buttons::ok, xtd::forms::message_box_icon::error);}
      
      /// @brief Displays a message box in front of the specified window and write debug with specified text.
      /// @param owner An implementation of iwin32_window that will own the modal dialog box.
      /// @param text The text to display in the message box.
      static xtd::forms::dialog_result show(const xtd::forms::iwin32_window& owner, const xtd::ustring& text) {return show_message_dialog(&owner, text, xtd::forms::application::product_name(), xtd::forms::message_box_buttons::ok, xtd::forms::message_box_icon::error);}
      /// @}
      
    private:
      static xtd::forms::dialog_result show_message_dialog(const xtd::forms::iwin32_window* owner, const xtd::ustring& text = "", const xtd::ustring& caption = "", xtd::forms::message_box_buttons buttons = xtd::forms::message_box_buttons::ok, xtd::forms::message_box_icon icon = xtd::forms::message_box_icon::none, xtd::forms::message_box_default_button default_button = xtd::forms::message_box_default_button::button1, xtd::forms::message_box_options options = static_cast<xtd::forms::message_box_options>(0), bool display_help_button = false) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        xtd::diagnostics::debug::write_line(text);
        message_dialog dialog;
        dialog.buttons(buttons);
        dialog.default_button(default_button);
        dialog.display_help_button(display_help_button);
        dialog.icon(icon);
        dialog.message(text);
        dialog.options(options);
        dialog.text(caption);
        return owner ? dialog.show_sheet_dialog(*owner) : dialog.show_dialog();
        #else
        return xtd::forms::dialog_result::none;
        #endif
      }
    };
  }
}

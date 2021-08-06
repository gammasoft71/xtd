/// @file
/// @brief Contains xtd::forms::debug_message_box dialog.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "application.h"
#include "message_box.h"


/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Displays a dialog box and write trace.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs debug
    class trace_message_box static_ {
    public:
      /// @brief Displays a message box and write trace with specified text.
      /// @param text The text to display in the message box.
      static xtd::forms::dialog_result show(const xtd::ustring& text) {return show_message_dialog(nullptr, text, xtd::forms::application::product_name(), xtd::forms::message_box_buttons::ok, xtd::forms::message_box_icon::error);}
      
      /// @brief Displays a message box in front of the specified window and write trace with specified text.
      /// @param owner An implementation of iwin32_window that will own the modal dialog box.
      /// @param text The text to display in the message box.
      static dialog_result show(const iwin32_window& owner, const xtd::ustring& text) {return show_message_dialog(&owner, text, xtd::forms::application::product_name(), xtd::forms::message_box_buttons::ok, xtd::forms::message_box_icon::error);}
      
    private:
      static xtd::forms::dialog_result show_message_dialog(const xtd::forms::iwin32_window* owner, const xtd::ustring& text = "", const xtd::ustring& caption = "", xtd::forms::message_box_buttons buttons = xtd::forms::message_box_buttons::ok, xtd::forms::message_box_icon icon = xtd::forms::message_box_icon::none, xtd::forms::message_box_default_button default_button = xtd::forms::message_box_default_button::button1, xtd::forms::message_box_options options = static_cast<xtd::forms::message_box_options>(0), bool display_help_button = false) {
#if defined(TRACE)
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

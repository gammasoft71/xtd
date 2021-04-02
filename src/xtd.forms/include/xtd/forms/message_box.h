/// @file
/// @brief Contains xtd::forms::message_box dialog.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "message_dialog.h"
#include "iwin32_window.h"
#include "message_box_buttons.h"
#include "message_box_default_button.h"
#include "message_box_icon.h"
#include "message_box_options.h"
#include <xtd/static.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    /// @endcond

    /// @brief Displays a message window, also known as a dialog box, which presents a message to the user. It is a modal window, blocking other actions in the application until the user closes it. A message_box can contain text, buttons, and symbols that inform and instruct the user.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Examples
    /// The following code example demonstrate the use of message_box dialog.
    /// @include message_box.cpp
    /// @par Windows
    /// @image html message_box_w.png
    /// <br>
    /// @image html message_box_wd.png
    /// @par macOS
    /// @image html message_box_m.png
    /// <br>
    /// @image html message_box_md.png
    /// @par Gnome
    /// @image html message_box_g.png
    /// <br>
    /// @image html message_box_gd.png
    class message_box final static_ {
    public:
      static dialog_result show(const iwin32_window& owner) {return show_message_dialog(&owner);}
      static dialog_result show(const iwin32_window& owner, const std::string& text) {return show_message_dialog(&owner, text);}
      static dialog_result show(const iwin32_window& owner, const std::string& text, const std::string& caption) {return show_message_dialog(&owner, text, caption);}
      static dialog_result show(const iwin32_window& owner, const std::string& text, const std::string& caption, message_box_buttons buttons) {return show_message_dialog(&owner, text, caption, buttons);}
      static dialog_result show(const iwin32_window& owner, const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon) {return show_message_dialog(&owner, text, caption, buttons, icon);}
      static dialog_result show(const iwin32_window& owner, const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button) {return show_message_dialog(&owner, text, caption, buttons, icon, default_button);}
      static dialog_result show(const iwin32_window& owner, const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options) {return show_message_dialog(&owner, text, caption, buttons, icon, default_button, options);}
      static dialog_result show(const iwin32_window& owner, const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options, bool display_help_button) {return show_message_dialog(&owner, text, caption, buttons, icon, default_button, options, display_help_button);}
      
      static dialog_result show() {return show_message_dialog(nullptr);}
      static dialog_result show(const std::string& text) {return show_message_dialog(nullptr, text);}
      static dialog_result show(const std::string& text, const std::string& caption) {return show_message_dialog(nullptr, text, caption);}
      static dialog_result show(const std::string& text, const std::string& caption, message_box_buttons buttons) {return show_message_dialog(nullptr, text, caption, buttons);}
      static dialog_result show(const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon) {return show_message_dialog(nullptr, text, caption, buttons, icon);}
      static dialog_result show(const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button) {return show_message_dialog(nullptr, text, caption, buttons, icon, default_button);}
      static dialog_result show(const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options) {return show_message_dialog(nullptr, text, caption, buttons, icon, default_button, options);}
      static dialog_result show(const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options, bool display_help_button) {return show_message_dialog(nullptr, text, caption, buttons, icon, default_button, options, display_help_button);}
      
    private:
      static dialog_result show_message_dialog(const iwin32_window* owner, const std::string& text = "", const std::string& caption = "", message_box_buttons buttons = message_box_buttons::ok, message_box_icon icon = message_box_icon::none, message_box_default_button default_button = message_box_default_button::button1, message_box_options options = static_cast<message_box_options>(0), bool display_help_button = false) {
        message_dialog dialog;
        dialog.buttons(buttons);
        dialog.default_button(default_button);
        dialog.display_help_button(display_help_button);
        dialog.icon(icon);
        dialog.message(text);
        dialog.options(options);
        dialog.text(caption);
        return owner ? dialog.show_sheet_dialog(*owner) : dialog.show_dialog();
      }
    };
  }
}

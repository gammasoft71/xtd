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
      /// @brief Displays a message box in front of the specified window.
      /// @param owner An implementation of iwin32_window that will own the modal dialog box.
      static dialog_result show(const iwin32_window& owner) {return show_message_dialog(&owner);}
      /// @brief Displays a message box in front of the specified window with specified text.
      /// @param owner An implementation of iwin32_window that will own the modal dialog box.
      /// @param text The text to display in the message box.
      static dialog_result show(const iwin32_window& owner, const xtd::ustring& text) {return show_message_dialog(&owner, text);}
      /// @brief Displays a message box in front of the specified window with specified text and caption.
      /// @param owner An implementation of iwin32_window that will own the modal dialog box.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      static dialog_result show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption) {return show_message_dialog(&owner, text, caption);}
      /// @brief Displays a message box in front of the specified window with the specified text, caption, and buttons.
      /// @param owner An implementation of iwin32_window that will own the modal dialog box.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the message_box_buttons values that specifies which buttons to display in the message box.
      static dialog_result show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, message_box_buttons buttons) {return show_message_dialog(&owner, text, caption, buttons);}
      /// @brief Displays a message box in front of the specified window with the specified text, caption, buttons, and icon.
      /// @param owner An implementation of iwin32_window that will own the modal dialog box.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the message_box_buttons values that specifies which buttons to display in the message box.
      /// @param icon One of the message_box_icon values that specifies which icon to display in the message box.
      static dialog_result show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, message_box_buttons buttons, message_box_icon icon) {return show_message_dialog(&owner, text, caption, buttons, icon);}
      /// @brief Displays a message box in front of the specified window with the specified text, caption, buttons, icon, and default button.
      /// @param owner An implementation of iwin32_window that will own the modal dialog box.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the message_box_buttons values that specifies which buttons to display in the message box.
      /// @param icon One of the message_box_icon values that specifies which icon to display in the message box.
      /// @param default_button One of the message_box_default_button values that specifies the default button for the message box.
      static dialog_result show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button) {return show_message_dialog(&owner, text, caption, buttons, icon, default_button);}
      /// @brief Displays a message box in front of the specified window with the specified text, caption, buttons, icon, default button, and options.
      /// @param owner An implementation of iwin32_window that will own the modal dialog box.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the message_box_buttons values that specifies which buttons to display in the message box.
      /// @param icon One of the message_box_icon values that specifies which icon to display in the message box.
      /// @param default_button One of the message_box_default_button values that specifies the default button for the message box.
      /// @param options One of the message_box_options values that specifies which display and association options will be used for the message box. You may pass in 0 if you wish to use the defaults.
      static dialog_result show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options) {return show_message_dialog(&owner, text, caption, buttons, icon, default_button, options);}
      /// @brief Displays a message box in front of the specified window with the specified text, caption, buttons, icon, default button, options, and Help button.
      /// @param owner An implementation of iwin32_window that will own the modal dialog box.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the message_box_buttons values that specifies which buttons to display in the message box.
      /// @param icon One of the message_box_icon values that specifies which icon to display in the message box.
      /// @param default_button One of the message_box_default_button values that specifies the default button for the message box.
      /// @param options One of the message_box_options values that specifies which display and association options will be used for the message box. You may pass in 0 if you wish to use the defaults.
      /// @param display_help_button true to show the Help button; otherwise, false. The default is false.
      static dialog_result show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options, bool display_help_button) {return show_message_dialog(&owner, text, caption, buttons, icon, default_button, options, display_help_button);}
      
      /// @brief Displays a message box.
      static dialog_result show() {return show_message_dialog(nullptr);}
      /// @brief Displays a message box with specified text.
      /// @param text The text to display in the message box.
      static dialog_result show(const xtd::ustring& text) {return show_message_dialog(nullptr, text);}
      /// @brief Displays a message box with specified text and caption.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      static dialog_result show(const xtd::ustring& text, const xtd::ustring& caption) {return show_message_dialog(nullptr, text, caption);}
      /// @brief Displays a message box with the specified text, caption, and buttons.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the message_box_buttons values that specifies which buttons to display in the message box.
      static dialog_result show(const xtd::ustring& text, const xtd::ustring& caption, message_box_buttons buttons) {return show_message_dialog(nullptr, text, caption, buttons);}
      /// @brief Displays a message box with the specified text, caption, buttons, and icon.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the message_box_buttons values that specifies which buttons to display in the message box.
      /// @param icon One of the message_box_icon values that specifies which icon to display in the message box.
      static dialog_result show(const xtd::ustring& text, const xtd::ustring& caption, message_box_buttons buttons, message_box_icon icon) {return show_message_dialog(nullptr, text, caption, buttons, icon);}
      /// @brief Displays a message box with the specified text, caption, buttons, icon, and default button.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the message_box_buttons values that specifies which buttons to display in the message box.
      /// @param icon One of the message_box_icon values that specifies which icon to display in the message box.
      /// @param default_button One of the message_box_default_button values that specifies the default button for the message box.
      static dialog_result show(const xtd::ustring& text, const xtd::ustring& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button) {return show_message_dialog(nullptr, text, caption, buttons, icon, default_button);}
      /// @brief Displays a message box with the specified text, caption, buttons, icon, default button, and options.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the message_box_buttons values that specifies which buttons to display in the message box.
      /// @param icon One of the message_box_icon values that specifies which icon to display in the message box.
      /// @param default_button One of the message_box_default_button values that specifies the default button for the message box.
      /// @param options One of the message_box_options values that specifies which display and association options will be used for the message box. You may pass in 0 if you wish to use the defaults.
      static dialog_result show(const xtd::ustring& text, const xtd::ustring& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options) {return show_message_dialog(nullptr, text, caption, buttons, icon, default_button, options);}
      /// @brief Displays a message box with the specified text, caption, buttons, icon, default button, options, and Help button.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the message_box_buttons values that specifies which buttons to display in the message box.
      /// @param icon One of the message_box_icon values that specifies which icon to display in the message box.
      /// @param default_button One of the message_box_default_button values that specifies the default button for the message box.
      /// @param options One of the message_box_options values that specifies which display and association options will be used for the message box. You may pass in 0 if you wish to use the defaults.
      /// @param display_help_button true to show the Help button; otherwise, false. The default is false.
      static dialog_result show(const xtd::ustring& text, const xtd::ustring& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options, bool display_help_button) {return show_message_dialog(nullptr, text, caption, buttons, icon, default_button, options, display_help_button);}
      
    private:
      static dialog_result show_message_dialog(const iwin32_window* owner, const xtd::ustring& text = "", const xtd::ustring& caption = "", message_box_buttons buttons = message_box_buttons::ok, message_box_icon icon = message_box_icon::none, message_box_default_button default_button = message_box_default_button::button1, message_box_options options = static_cast<message_box_options>(0), bool display_help_button = false) {
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

/// @file
/// @brief Contains xtd::forms::message_box dialog.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.h"
#include "dialog_result.h"
#include "iwin32_window.h"
#include "message_box_buttons.h"
#include "message_box_default_button.h"
#include "message_box_icon.h"
#include "message_box_options.h"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    /// @endcond
    
    /// @brief Displays a message window, also known as a dialog box, which presents a message to the user. It is a modal window, blocking other actions in the application until the user closes it. A message_box can contain text, buttons, and symbols that inform and instruct the user.
    /// @par Header
    /// @code #include <xtd/forms/message_box> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                 | macOS                                   | Gnome                                   |
    /// | ----- | --------------------------------------- | --------------------------------------- | --------------------------------------- |
    /// | Light |  @image html dialog_message_box_w.png   |  @image html dialog_message_box_m.png   |  @image html dialog_message_box_g.png   |
    /// | Dark  |  @image html dialog_message_box_wd.png  |  @image html dialog_message_box_md.png  |  @image html dialog_message_box_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of message_box dialog.
    /// @include message_box.cpp
    class forms_export_ message_box final static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Displays a message box in front of the specified window.
      /// @param owner An implementation of iwin32_window that will own the modal dialog box.
      /// @return One of the xtd::forms::dialog_result values.
      static dialog_result show(const iwin32_window& owner);
      /// @brief Displays a message box in front of the specified window with specified text.
      /// @param owner An implementation of iwin32_window that will own the modal dialog box.
      /// @param text The text to display in the message box.
      /// @return One of the xtd::forms::dialog_result values.
      static dialog_result show(const iwin32_window& owner, const xtd::ustring& text);
      /// @brief Displays a message box in front of the specified window with specified text and caption.
      /// @param owner An implementation of iwin32_window that will own the modal dialog box.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @return One of the xtd::forms::dialog_result values.
      static dialog_result show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption);
      /// @brief Displays a message box in front of the specified window with the specified text, caption, and buttons.
      /// @param owner An implementation of iwin32_window that will own the modal dialog box.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the message_box_buttons values that specifies which buttons to display in the message box.
      /// @return One of the xtd::forms::dialog_result values.
      static dialog_result show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, message_box_buttons buttons);
      /// @brief Displays a message box in front of the specified window with the specified text, caption, buttons, and icon.
      /// @param owner An implementation of iwin32_window that will own the modal dialog box.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the message_box_buttons values that specifies which buttons to display in the message box.
      /// @param icon One of the message_box_icon values that specifies which icon to display in the message box.
      /// @return One of the xtd::forms::dialog_result values.
      static dialog_result show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, message_box_buttons buttons, message_box_icon icon);
      /// @brief Displays a message box in front of the specified window with the specified text, caption, buttons, icon, and default button.
      /// @param owner An implementation of iwin32_window that will own the modal dialog box.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the message_box_buttons values that specifies which buttons to display in the message box.
      /// @param icon One of the message_box_icon values that specifies which icon to display in the message box.
      /// @param default_button One of the message_box_default_button values that specifies the default button for the message box.
      /// @return One of the xtd::forms::dialog_result values.
      static dialog_result show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button);
      /// @brief Displays a message box in front of the specified window with the specified text, caption, buttons, icon, default button, and options.
      /// @param owner An implementation of iwin32_window that will own the modal dialog box.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the message_box_buttons values that specifies which buttons to display in the message box.
      /// @param icon One of the message_box_icon values that specifies which icon to display in the message box.
      /// @param default_button One of the message_box_default_button values that specifies the default button for the message box.
      /// @param options One of the message_box_options values that specifies which display and association options will be used for the message box. You may pass in 0 if you wish to use the defaults.
      /// @return One of the xtd::forms::dialog_result values.
      static dialog_result show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options);
      /// @brief Displays a message box in front of the specified window with the specified text, caption, buttons, icon, default button, options, and Help button.
      /// @param owner An implementation of iwin32_window that will own the modal dialog box.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the message_box_buttons values that specifies which buttons to display in the message box.
      /// @param icon One of the message_box_icon values that specifies which icon to display in the message box.
      /// @param default_button One of the message_box_default_button values that specifies the default button for the message box.
      /// @param options One of the message_box_options values that specifies which display and association options will be used for the message box. You may pass in 0 if you wish to use the defaults.
      /// @param display_help_button true to show the Help button; otherwise, false. The default is false.
      /// @return One of the xtd::forms::dialog_result values.
      static dialog_result show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options, bool display_help_button);
      
      /// @brief Displays a message box.
      /// @return One of the xtd::forms::dialog_result values.
      static dialog_result show();
      /// @brief Displays a message box with specified text.
      /// @param text The text to display in the message box.
      /// @return One of the xtd::forms::dialog_result values.
      static dialog_result show(const xtd::ustring& text);
      /// @brief Displays a message box with specified text and caption.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @return One of the xtd::forms::dialog_result values.
      static dialog_result show(const xtd::ustring& text, const xtd::ustring& caption);
      /// @brief Displays a message box with the specified text, caption, and buttons.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the message_box_buttons values that specifies which buttons to display in the message box.
      /// @return One of the xtd::forms::dialog_result values.
      static dialog_result show(const xtd::ustring& text, const xtd::ustring& caption, message_box_buttons buttons);
      /// @brief Displays a message box with the specified text, caption, buttons, and icon.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the message_box_buttons values that specifies which buttons to display in the message box.
      /// @param icon One of the message_box_icon values that specifies which icon to display in the message box.
      /// @return One of the xtd::forms::dialog_result values.
      static dialog_result show(const xtd::ustring& text, const xtd::ustring& caption, message_box_buttons buttons, message_box_icon icon);
      /// @brief Displays a message box with the specified text, caption, buttons, icon, and default button.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the message_box_buttons values that specifies which buttons to display in the message box.
      /// @param icon One of the message_box_icon values that specifies which icon to display in the message box.
      /// @param default_button One of the message_box_default_button values that specifies the default button for the message box.
      /// @return One of the xtd::forms::dialog_result values.
      static dialog_result show(const xtd::ustring& text, const xtd::ustring& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button);
      /// @brief Displays a message box with the specified text, caption, buttons, icon, default button, and options.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the message_box_buttons values that specifies which buttons to display in the message box.
      /// @param icon One of the message_box_icon values that specifies which icon to display in the message box.
      /// @param default_button One of the message_box_default_button values that specifies the default button for the message box.
      /// @param options One of the message_box_options values that specifies which display and association options will be used for the message box. You may pass in 0 if you wish to use the defaults.
      /// @return One of the xtd::forms::dialog_result values.
      static dialog_result show(const xtd::ustring& text, const xtd::ustring& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options);
      /// @brief Displays a message box with the specified text, caption, buttons, icon, default button, options, and Help button.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the message_box_buttons values that specifies which buttons to display in the message box.
      /// @param icon One of the message_box_icon values that specifies which icon to display in the message box.
      /// @param default_button One of the message_box_default_button values that specifies the default button for the message box.
      /// @param options One of the message_box_options values that specifies which display and association options will be used for the message box. You may pass in 0 if you wish to use the defaults.
      /// @param display_help_button true to show the Help button; otherwise, false. The default is false.
      /// @return One of the xtd::forms::dialog_result values.
      static dialog_result show(const xtd::ustring& text, const xtd::ustring& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options, bool display_help_button);
      /// @}
      
    private:
      static dialog_result show_message_dialog(const iwin32_window* owner, const xtd::ustring& text = xtd::ustring::empty_string, const xtd::ustring& caption = xtd::ustring::empty_string, message_box_buttons buttons = message_box_buttons::ok, message_box_icon icon = message_box_icon::none, message_box_default_button default_button = message_box_default_button::button1, message_box_options options = static_cast<message_box_options>(0), bool display_help_button = false);
    };
  }
}

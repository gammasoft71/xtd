/// @file
/// @brief Contains xtd::forms::message_box dialog.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.hpp"
#include "dialog_result.hpp"
#include "iwin32_window.hpp"
#include "message_box_buttons.hpp"
#include "message_box_default_button.hpp"
#include "message_box_icon.hpp"
#include "message_box_options.hpp"
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
    /// ```cpp
    /// #include <xtd/forms/message_box>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                 | macOS                                   | Gnome                                   |
    /// | ----- | --------------------------------------- | --------------------------------------- | --------------------------------------- |
    /// | Light |  @image html dialog_message_box_w.png   |  @image html dialog_message_box_m.png   |  @image html dialog_message_box_g.png   |
    /// | Dark  |  @image html dialog_message_box_wd.png  |  @image html dialog_message_box_md.png  |  @image html dialog_message_box_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of message_box dialog.
    /// @include message_box.cpp
    class forms_export_ message_box final static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Displays a message box in front of the specified window.
      /// @param owner An implementation of xtd::forms::iwin32_window that will own the modal dialog box.
      /// @return One of the xtd::forms::dialog_result values.
      static auto show(const xtd::forms::iwin32_window& owner) -> xtd::forms::dialog_result;
      /// @brief Displays a message box in front of the specified window with specified text.
      /// @param owner An implementation of xtd::forms::iwin32_window that will own the modal dialog box.
      /// @param text The text to display in the message box.
      /// @return One of the xtd::forms::dialog_result values.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& text) -> xtd::forms::dialog_result;
      /// @brief Displays a message box in front of the specified window with specified text and caption.
      /// @param owner An implementation of xtd::forms::iwin32_window that will own the modal dialog box.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @return One of the xtd::forms::dialog_result values.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& text, const xtd::string& caption) -> xtd::forms::dialog_result;
      /// @brief Displays a message box in front of the specified window with the specified text, caption, and buttons.
      /// @param owner An implementation of xtd::forms::iwin32_window that will own the modal dialog box.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the xtd::forms::message_box_buttons values that specifies which buttons to display in the message box.
      /// @return One of the xtd::forms::dialog_result values.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& text, const xtd::string& caption, xtd::forms::message_box_buttons buttons) -> xtd::forms::dialog_result;
      /// @brief Displays a message box in front of the specified window with the specified text, caption, buttons, and icon.
      /// @param owner An implementation of xtd::forms::iwin32_window that will own the modal dialog box.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the xtd::forms::message_box_buttons values that specifies which buttons to display in the message box.
      /// @param icon One of the xtd::forms::message_box_icon values that specifies which icon to display in the message box.
      /// @return One of the xtd::forms::dialog_result values.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& text, const xtd::string& caption, xtd::forms::message_box_buttons buttons, xtd::forms::message_box_icon icon) -> xtd::forms::dialog_result;
      /// @brief Displays a message box in front of the specified window with the specified text, caption, buttons, icon, and default button.
      /// @param owner An implementation of xtd::forms::iwin32_window that will own the modal dialog box.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the xtd::forms::message_box_buttons values that specifies which buttons to display in the message box.
      /// @param icon One of the xtd::forms::message_box_icon values that specifies which icon to display in the message box.
      /// @param default_button One of the xtd::forms::message_box_default_button values that specifies the default button for the message box.
      /// @return One of the xtd::forms::dialog_result values.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& text, const xtd::string& caption, xtd::forms::message_box_buttons buttons, xtd::forms::message_box_icon icon, xtd::forms::message_box_default_button default_button) -> xtd::forms::dialog_result;
      /// @brief Displays a message box in front of the specified window with the specified text, caption, buttons, icon, default button, and options.
      /// @param owner An implementation of xtd::forms::iwin32_window that will own the modal dialog box.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the xtd::forms::message_box_buttons values that specifies which buttons to display in the message box.
      /// @param icon One of the xtd::forms::message_box_icon values that specifies which icon to display in the message box.
      /// @param default_button One of the xtd::forms::message_box_default_button values that specifies the default button for the message box.
      /// @param options One of the xtd::forms::message_box_options values that specifies which display and association options will be used for the message box. You may pass in 0 if you wish to use the defaults.
      /// @return One of the xtd::forms::dialog_result values.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& text, const xtd::string& caption, xtd::forms::message_box_buttons buttons, xtd::forms::message_box_icon icon, xtd::forms::message_box_default_button default_button, xtd::forms::message_box_options options) -> xtd::forms::dialog_result;
      /// @brief Displays a message box in front of the specified window with the specified text, caption, buttons, icon, default button, options, and Help button.
      /// @param owner An implementation of xtd::forms::iwin32_window that will own the modal dialog box.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the xtd::forms::message_box_buttons values that specifies which buttons to display in the message box.
      /// @param icon One of the xtd::forms::message_box_icon values that specifies which icon to display in the message box.
      /// @param default_button One of the xtd::forms::message_box_default_button values that specifies the default button for the message box.
      /// @param options One of the xtd::forms::message_box_options values that specifies which display and association options will be used for the message box. You may pass in 0 if you wish to use the defaults.
      /// @param display_help_button `true` to show the Help button; otherwise, `false`. The default is `false`.
      /// @return One of the xtd::forms::dialog_result values.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& text, const xtd::string& caption, xtd::forms::message_box_buttons buttons, xtd::forms::message_box_icon icon, xtd::forms::message_box_default_button default_button, xtd::forms::message_box_options options, bool display_help_button) -> xtd::forms::dialog_result;
      
      /// @brief Displays a message box.
      /// @return One of the xtd::forms::dialog_result values.
      static auto show() -> xtd::forms::dialog_result;
      /// @brief Displays a message box with specified text.
      /// @param text The text to display in the message box.
      /// @return One of the xtd::forms::dialog_result values.
      static auto show(const xtd::string& text) -> xtd::forms::dialog_result;
      /// @brief Displays a message box with specified text and caption.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @return One of the xtd::forms::dialog_result values.
      static auto show(const xtd::string& text, const xtd::string& caption) -> xtd::forms::dialog_result;
      /// @brief Displays a message box with the specified text, caption, and buttons.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the xtd::forms::message_box_buttons values that specifies which buttons to display in the message box.
      /// @return One of the xtd::forms::dialog_result values.
      static auto show(const xtd::string& text, const xtd::string& caption, xtd::forms::message_box_buttons buttons) -> xtd::forms::dialog_result;
      /// @brief Displays a message box with the specified text, caption, buttons, and icon.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the xtd::forms::message_box_buttons values that specifies which buttons to display in the message box.
      /// @param icon One of the xtd::forms::message_box_icon values that specifies which icon to display in the message box.
      /// @return One of the xtd::forms::dialog_result values.
      static auto show(const xtd::string& text, const xtd::string& caption, xtd::forms::message_box_buttons buttons, xtd::forms::message_box_icon icon) -> xtd::forms::dialog_result;
      /// @brief Displays a message box with the specified text, caption, buttons, icon, and default button.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the xtd::forms::message_box_buttons values that specifies which buttons to display in the message box.
      /// @param icon One of the xtd::forms::message_box_icon values that specifies which icon to display in the message box.
      /// @param default_button One of the xtd::forms::message_box_default_button values that specifies the default button for the message box.
      /// @return One of the xtd::forms::dialog_result values.
      static auto show(const xtd::string& text, const xtd::string& caption, xtd::forms::message_box_buttons buttons, xtd::forms::message_box_icon icon, xtd::forms::message_box_default_button default_button) -> xtd::forms::dialog_result;
      /// @brief Displays a message box with the specified text, caption, buttons, icon, default button, and options.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the xtd::forms::message_box_buttons values that specifies which buttons to display in the message box.
      /// @param icon One of the xtd::forms::message_box_icon values that specifies which icon to display in the message box.
      /// @param default_button One of the xtd::forms::message_box_default_button values that specifies the default button for the message box.
      /// @param options One of the xtd::forms::message_box_options values that specifies which display and association options will be used for the message box. You may pass in 0 if you wish to use the defaults.
      /// @return One of the xtd::forms::dialog_result values.
      static auto show(const xtd::string& text, const xtd::string& caption, xtd::forms::message_box_buttons buttons, xtd::forms::message_box_icon icon, xtd::forms::message_box_default_button default_button, xtd::forms::message_box_options options) -> xtd::forms::dialog_result;
      /// @brief Displays a message box with the specified text, caption, buttons, icon, default button, options, and Help button.
      /// @param text The text to display in the message box.
      /// @param caption The text to display in the title bar of the message box.
      /// @param buttons One of the xtd::forms::message_box_buttons values that specifies which buttons to display in the message box.
      /// @param icon One of the xtd::forms::message_box_icon values that specifies which icon to display in the message box.
      /// @param default_button One of the xtd::forms::message_box_default_button values that specifies the default button for the message box.
      /// @param options One of the xtd::forms::message_box_options values that specifies which display and association options will be used for the message box. You may pass in 0 if you wish to use the defaults.
      /// @param display_help_button `true` to show the Help button; otherwise, `false`. The default is `false`.
      /// @return One of the xtd::forms::dialog_result values.
      static auto show(const xtd::string& text, const xtd::string& caption, xtd::forms::message_box_buttons buttons, xtd::forms::message_box_icon icon, xtd::forms::message_box_default_button default_button, xtd::forms::message_box_options options, bool display_help_button) -> xtd::forms::dialog_result;
      /// @}
      
    private:
      [[nodiscard]] static auto show_message_dialog(const xtd::forms::iwin32_window* owner, const xtd::string& text = xtd::string::empty_string, const xtd::string& caption = xtd::string::empty_string, xtd::forms::message_box_buttons buttons = xtd::forms::message_box_buttons::ok, xtd::forms::message_box_icon icon = xtd::forms::message_box_icon::none, xtd::forms::message_box_default_button default_button = xtd::forms::message_box_default_button::button1, xtd::forms::message_box_options options = static_cast<xtd::forms::message_box_options>(0), bool display_help_button = false) -> xtd::forms::dialog_result;
    };
  }
}

/// @file
/// @brief Contains xtd::forms::trace_message_box dialog.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "application.hpp"
#include "message_box_buttons.hpp"
#include "message_box_default_button.hpp"
#include "message_box_icon.hpp"
#include "message_box_options.hpp"
#include "message_dialog.hpp"
#include <xtd/diagnostics/trace>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Displays a dialog box and write trace.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/trace_message_box>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs debug
    /// @par Appearance
    /// |       | Windows                                       | macOS                                         | Gnome                                         |
    /// | ----- | --------------------------------------------- | --------------------------------------------- | --------------------------------------------- |
    /// | Light |  @image html dialog_trace_message_box_w.png   |  @image html dialog_trace_message_box_m.png   |  @image html dialog_trace_message_box_g.png   |
    /// | Dark  |  @image html dialog_trace_message_box_wd.png  |  @image html dialog_trace_message_box_md.png  |  @image html dialog_trace_message_box_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of trace_message_box dialog.
    /// @include trace_message_box.cpp
    class trace_message_box static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Displays a message box and write trace with specified text.
      /// @param text The text to display in the message box.
      static xtd::forms::dialog_result show(const xtd::string& text) {return show_message_dialog(nullptr, text, xtd::forms::application::product_name(), xtd::forms::message_box_buttons::ok, xtd::forms::message_box_icon::error);}
      
      /// @brief Displays a message box in front of the specified window and write trace with specified text.
      /// @param owner An implementation of iwin32_window that will own the modal dialog box.
      /// @param text The text to display in the message box.
      static xtd::forms::dialog_result show(const xtd::forms::iwin32_window& owner, const xtd::string& text) {return show_message_dialog(&owner, text, xtd::forms::application::product_name(), xtd::forms::message_box_buttons::ok, xtd::forms::message_box_icon::error);}
      /// @}
      
    private:
      static xtd::forms::dialog_result show_message_dialog(const xtd::forms::iwin32_window* owner, const xtd::string& text = xtd::string::empty_string, const xtd::string& caption = xtd::string::empty_string, xtd::forms::message_box_buttons buttons = xtd::forms::message_box_buttons::ok, xtd::forms::message_box_icon icon = xtd::forms::message_box_icon::none, xtd::forms::message_box_default_button default_button = xtd::forms::message_box_default_button::button1, xtd::forms::message_box_options options = static_cast<xtd::forms::message_box_options>(0), bool display_help_button = false) {
        #if !defined(NTRACE)
        xtd::diagnostics::trace::write_line(text);
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

/// @file
/// @brief Contains xtd::forms::debug_message_dialog dialog.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "application.h"
#include "message_dialog.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Displays a message window, also known as a dialog box, which presents a message to the user. It is a modal window, blocking other actions in the application until the user closes it. A debug_message_dialog can contain text, buttons, and symbols that inform and instruct the user.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
    ///   <tr>
    ///     <th style="width:100px"></th>
    ///     <th><b>Windows</b></th>
    ///     <th><b>macOS</b></th>
    ///     <th><b>Gnome</b></th>
    ///   </tr>
    ///   <tr>
    ///     <th>Light</th>
    ///     <td>@image html dialog_debug_message_box_w.png</td>
    ///     <td>@image html dialog_debug_message_box_m.png</td>
    ///     <td>@image html dialog_debug_message_box_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <th>Dark</th>
    ///     <td>@image html dialog_debug_message_box_wd.png</td>
    ///     <td>@image html dialog_debug_message_box_md.png</td>
    ///     <td>@image html dialog_debug_message_box_gd.png</td>
    ///   </tr>
    /// </table>
    /// @par Examples
    /// The following code example demonstrates the use of debug_message_dialog dialog.
    /// @include debug_message_dialog.cpp
    class forms_export_ debug_message_dialog final : public component {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the debug_message_dialog class.
      debug_message_dialog() {
        dialog_.dialog_closed += [&](object& sender, const dialog_closed_event_args& e) {on_dialog_closed(e);};
        reset();
      }
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets async dialog_result result after dialog box is closing.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      xtd::forms::dialog_result dialog_result() const noexcept {return dialog_.dialog_result();}
      
      /// @brief Gets the text message.
      /// @return The text message.
      xtd::ustring message() const noexcept {return dialog_.message();}
      /// @brief Sets the text message.
      /// @param message The text message.
      /// @return Current debug_message_dialog instance.
      debug_message_dialog& message(const xtd::ustring& message) {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        dialog_.message(message);
#endif
        return *this;
      }
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Resets all properties to empty string.
      void reset() {
        dialog_.reset();
        dialog_.buttons(xtd::forms::message_dialog_buttons::ok);
        dialog_.icon(xtd::forms::message_dialog_icon::exclamation);
        dialog_.text(xtd::forms::application::product_name());
      }
      
      /// @brief Runs message dialog box.
      xtd::forms::dialog_result show_dialog() {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        xtd::diagnostics::debug::write_line(dialog_.message());
        return dialog_.show_dialog();
#else
        return xtd::forms::dialog_result::none;
#endif
      }
      /// @brief Runs message dialog box.
      xtd::forms::dialog_result show_dialog(const iwin32_window& owner) {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        xtd::diagnostics::debug::write_line(dialog_.message());
        return dialog_.show_dialog(owner);
#else
        return xtd::forms::dialog_result::none;
#endif
      }
      /// @brief Runs message dialog box.
      void show_sheet(const iwin32_window& owner) {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        xtd::diagnostics::debug::write_line(dialog_.message());
        dialog_.show_sheet(owner);
#endif
      }
      /// @brief Runs message dialog box.
      xtd::forms::dialog_result show_sheet_dialog(const iwin32_window& owner) {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        xtd::diagnostics::debug::write_line(dialog_.message());
        return dialog_.show_sheet_dialog(owner);
#else
        return xtd::forms::dialog_result::none;
#endif
      }
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when the user close a message dialog box with dialog close button or other dialog buttons.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      event<debug_message_dialog, dialog_closed_event_handler> dialog_closed;
      /// @}
      
    private:
      /// @brief Raises the debug_message_dialog::dialog_close event.
      /// @param e An message_dialog_close_event_args that provides the event data.
      /// @remarks This method is invoked when the message dialog box is closed.
      virtual void on_dialog_closed(const dialog_closed_event_args& e) {
        auto raise_event = dialog_closed;
        if (!raise_event.is_empty()) raise_event(*this, e);
      }
      
      message_dialog dialog_;
    };
  }
}

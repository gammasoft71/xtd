/// @file
/// @brief Contains xtd::forms::trace_message_dialog dialog.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "message_dialog.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Displays a message window and write debug, which presents a debug message to the user.
    /// @par Header
    /// @code #include <xtd/forms/trace_message_dialog> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs debug
    /// @par Appearance
    /// |       | Windows                                       | macOS                                         | Gnome                                         |
    /// | ----- | --------------------------------------------- | --------------------------------------------- | --------------------------------------------- |
    /// | Light |  @image html dialog_trace_message_box_w.png   |  @image html dialog_trace_message_box_m.png   |  @image html dialog_trace_message_box_g.png   |
    /// | Dark  |  @image html dialog_trace_message_box_wd.png  |  @image html dialog_trace_message_box_md.png  |  @image html dialog_trace_message_box_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of trace_message_dialog dialog.
    /// @include trace_message_dialog.cpp
    class forms_export_ trace_message_dialog final : public component {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the trace_message_dialog class.
      trace_message_dialog();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets async dialog_result result after dialog box is closing.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      xtd::forms::dialog_result dialog_result() const noexcept;
      
      /// @brief Gets the text message.
      /// @return The text message.
      xtd::ustring message() const noexcept;
      /// @brief Sets the text message.
      /// @param message The text message.
      /// @return Current trace_message_dialog instance.
      trace_message_dialog& message(const xtd::ustring& message) {
        #if defined(TRACE)
        dialog_.message(message);
        #endif
        return *this;
      }
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Resets all properties to empty string.
      void reset();
      
      /// @brief Runs message dialog box.
      xtd::forms::dialog_result show_dialog() {
        #if defined(TRACE)
        xtd::diagnostics::trace::write_line(dialog_.message());
        return dialog_.show_dialog();
        #else
        return xtd::forms::dialog_result::none;
        #endif
      }
      /// @brief Runs message dialog box.
      xtd::forms::dialog_result show_dialog(const iwin32_window& owner) {
        #if defined(TRACE)
        xtd::diagnostics::trace::write_line(dialog_.message());
        return dialog_.show_dialog(owner);
        #else
        return xtd::forms::dialog_result::none;
        #endif
      }
      /// @brief Runs message dialog box.
      void show_sheet(const iwin32_window& owner) {
        #if defined(TRACE)
        xtd::diagnostics::trace::write_line(dialog_.message());
        dialog_.show_sheet(owner);
        #endif
      }
      /// @brief Runs message dialog box.
      xtd::forms::dialog_result show_sheet_dialog(const iwin32_window& owner) {
        #if defined(TRACE)
        xtd::diagnostics::trace::write_line(dialog_.message());
        return dialog_.show_sheet_dialog(owner);
        #else
        return xtd::forms::dialog_result::none;
        #endif
      }
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the user close a message dialog box with dialog close button or other dialog buttons.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<trace_message_dialog, dialog_closed_event_handler> dialog_closed;
      /// @}
      
    private:
      /// @brief Raises the trace_message_dialog::dialog_close event.
      /// @param e An message_dialog_close_event_args that provides the event data.
      /// @remarks This method is invoked when the message dialog box is closed.
      virtual void on_dialog_closed(const dialog_closed_event_args& e);
      
      message_dialog dialog_;
    };
  }
}

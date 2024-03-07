/// @file
/// @brief Contains xtd::forms::message_dialog dialog.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "component.h"
#include "dialog_appearance.h"
#include "dialog_closed_event_handler.h"
#include "dialog_result.h"
#include "help_event_handler.h"
#include "iwin32_window.h"
#include "message_dialog_buttons.h"
#include "message_dialog_default_button.h"
#include "message_dialog_icon.h"
#include "message_dialog_options.h"

/// @cond
struct __xtd_forms_message_dialog_closed_caller__;
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Displays a message window, also known as a dialog box, which presents a message to the user. It is a modal window, blocking other actions in the application until the user closes it. A message_dialog can contain text, buttons, and symbols that inform and instruct the user.
    /// @par Header
    /// @code #include <xtd/forms/message_dialog> @endcode
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
    /// The following code example demonstrates the use of message_dialog dialog.
    /// @include message_dialog.cpp
    class forms_export_ message_dialog final : public component {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the message_dialog class.
      message_dialog();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets buttons to display in the message dialog.
      /// @return One of the xtd::forms::message_dialog_buttons values that specifies which buttons to display in the message dialog.
      xtd::forms::message_dialog_buttons buttons() const noexcept;
      /// @brief Sets buttons to display in the message dialog.
      /// @param buttons One of the xtd::forms::message_dialog_buttons values that specifies which buttons to display in the message dialog.
      /// @return Current message dialog.
      message_dialog& buttons(xtd::forms::message_dialog_buttons buttons);
      
      /// @brief Gets default button for the message dialog.
      /// @return One of the xtd::forms::message_dialog_default_button values that specifies the default button for the message dialog.
      xtd::forms::message_dialog_default_button default_button() const noexcept;
      /// @brief Sets default button for the message dialog.
      /// @param default_button One of the xtd::forms::message_dialog_default_button values that specifies the default button for the message dialog.
      /// @return Current message dialog.
      message_dialog& default_button(xtd::forms::message_dialog_default_button default_button);
      
      /// @brief Gets a value indicate if help button is shown.
      /// @return true to show the Help button; otherwise, false. The default is false.
      bool display_help_button() const noexcept;
      /// @brief Sets a value indicate if help button is shown.
      /// @param display_help_button true to show the Help button; otherwise, false. The default is false.
      /// @return Current message dialog.
      message_dialog& display_help_button(bool display_help_button);
      
      /// @brief Gets async dialog_result result after dialog box is closing.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      xtd::forms::dialog_result dialog_result() const noexcept;
      
      /// @brief Gets the dialog appearance.
      /// @return One of the xtd::forms::dialog_appearance values. The default value is xtd::forms::dialog_appearance::standard.
      xtd::forms::dialog_appearance dialog_appearance() const noexcept;
      /// @brief Sets the dialog appearance.
      /// @param dialog_appearance One of the xtd::forms::dialog_appearance values. The default value is xtd::forms::dialog_appearance::standard.
      /// @return Current message dialog.
      message_dialog& dialog_appearance(xtd::forms::dialog_appearance dialog_appearance);
      
      /// @brief Gets icon to display in the message dialog.
      /// @return One of the xtd::forms::message_dialog_icon values that specifies which icon to display in the message dialog.
      xtd::forms::message_dialog_icon icon() const noexcept;
      /// @brief Sets icon to display in the message dialog.
      /// @param icon One of the xtd::forms::message_dialog_icon values that specifies which icon to display in the message dialog.
      /// @return Current message dialog.
      message_dialog& icon(xtd::forms::message_dialog_icon icon);
      
      /// @brief Gets options will be used for the message box.
      /// @return One of the xtd::forms::message_dialog_options values that specifies which display and association options will be used for the message box. You may pass in 0 if you wish to use the defaults.
      xtd::forms::message_dialog_options options() const noexcept;
      /// @brief Sets options will be used for the message box.
      /// @param options One of the xtd::forms::message_dialog_options values that specifies which display and association options will be used for the message box. You may pass in 0 if you wish to use the defaults.
      /// @return Current message dialog.
      message_dialog& options(xtd::forms::message_dialog_options options);
      
      /// @brief Gets the text message.
      /// @return The text message.
      xtd::ustring message() const noexcept;
      /// @brief Sets the text message.
      /// @param message The text message.
      /// @return Current message_dialog instance.
      message_dialog& message(const xtd::ustring& message);
      
      /// @brief Gets the dialog caption text.
      /// @return The current dialog caption text.
      xtd::ustring text() const noexcept;
      /// @brief Sets the dialog caption text.
      /// @param text The new dialog caption text.
      /// @return Current message_dialog instance.
      message_dialog& text(const xtd::ustring& text);
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Resets all properties to empty string.
      void reset();
      
      /// @brief Runs message dialog box.
      xtd::forms::dialog_result show_dialog();
      /// @brief Runs message dialog box.
      xtd::forms::dialog_result show_dialog(const iwin32_window& owner);
      /// @brief Runs message dialog box.
      void show_sheet(const iwin32_window& owner);
      /// @brief Runs message dialog box.
      xtd::forms::dialog_result show_sheet_dialog(const iwin32_window& owner);
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the user clicks the Help button on a common dialog box.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      event<message_dialog, help_event_handler> help_request;
      
      /// @brief Occurs when the user close a message dialog box with dialog close button or other dialog buttons.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      event<message_dialog, dialog_closed_event_handler> dialog_closed;
      /// @}
      
    private:
      /// @cond
      friend struct ::__xtd_forms_message_dialog_closed_caller__;
      /// @endcond
      
      /// @brief Raises the message_dialog::dialog_close event.
      /// @param e An message_dialog_close_event_args that provides the event data.
      /// @remarks This method is invoked when the message dialog box is closed.
      virtual void on_dialog_closed(const dialog_closed_event_args& e);
      
      std::shared_ptr<data> data_;
    };
  }
}

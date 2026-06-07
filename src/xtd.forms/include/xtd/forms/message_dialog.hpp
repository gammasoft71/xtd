/// @file
/// @brief Contains xtd::forms::message_dialog dialog.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "component.hpp"
#include "dialog_appearance.hpp"
#include "dialog_closed_event_handler.hpp"
#include "dialog_result.hpp"
#include "help_event_handler.hpp"
#include "iwin32_window.hpp"
#include "message_dialog_buttons.hpp"
#include "message_dialog_default_button.hpp"
#include "message_dialog_icon.hpp"
#include "message_dialog_options.hpp"

/// @cond
struct __xtd_forms_message_dialog_closed_caller__;
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Displays a message window, also known as a dialog box, which presents a message to the user. It is a modal window, blocking other actions in the application until the user closes it. A message_dialog can contain text, buttons, and symbols that inform and instruct the user.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/message_dialog>
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
    /// The following code example demonstrates the use of message_dialog dialog.
    /// @include message_dialog.cpp
    class forms_export_ message_dialog final : public xtd::forms::component {
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
      [[nodiscard]] auto buttons() const noexcept -> xtd::forms::message_dialog_buttons;
      /// @brief Sets buttons to display in the message dialog.
      /// @param value One of the xtd::forms::message_dialog_buttons values that specifies which buttons to display in the message dialog.
      /// @return Current message dialog.
      auto buttons(xtd::forms::message_dialog_buttons value) -> message_dialog&;
      
      /// @brief Gets default button for the message dialog.
      /// @return One of the xtd::forms::message_dialog_default_button values that specifies the default button for the message dialog.
      [[nodiscard]] auto default_button() const noexcept -> xtd::forms::message_dialog_default_button;
      /// @brief Sets default button for the message dialog.
      /// @param value One of the xtd::forms::message_dialog_default_button values that specifies the default button for the message dialog.
      /// @return Current message dialog.
      auto default_button(xtd::forms::message_dialog_default_button value) -> message_dialog&;
      
      /// @brief Gets a value indicate if help button is shown.
      /// @return `true` to show the Help button; otherwise, `false`. The default is `false`.
      [[nodiscard]] auto display_help_button() const noexcept -> bool;
      /// @brief Sets a value indicate if help button is shown.
      /// @param value `true` to show the Help button; otherwise, `false`. The default is `false`.
      /// @return Current message dialog.
      auto display_help_button(bool value) -> message_dialog&;
      
      /// @brief Gets async dialog_result result after dialog box is closing.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      [[nodiscard]] auto dialog_result() const noexcept -> xtd::forms::dialog_result;
      
      /// @brief Gets the dialog appearance.
      /// @return One of the xtd::forms::dialog_appearance values. The default value is xtd::forms::dialog_appearance::standard.
      [[nodiscard]] auto dialog_appearance() const noexcept -> xtd::forms::dialog_appearance;
      /// @brief Sets the dialog appearance.
      /// @param value One of the xtd::forms::dialog_appearance values. The default value is xtd::forms::dialog_appearance::standard.
      /// @return Current message dialog.
      auto dialog_appearance(xtd::forms::dialog_appearance value) -> message_dialog&;
      
      /// @brief Gets icon to display in the message dialog.
      /// @return One of the xtd::forms::message_dialog_icon values that specifies which icon to display in the message dialog.
      [[nodiscard]] auto icon() const noexcept -> xtd::forms::message_dialog_icon;
      /// @brief Sets icon to display in the message dialog.
      /// @param value One of the xtd::forms::message_dialog_icon values that specifies which icon to display in the message dialog.
      /// @return Current message dialog.
      auto icon(xtd::forms::message_dialog_icon value) -> message_dialog&;
      
      /// @brief Gets options will be used for the message box.
      /// @return One of the xtd::forms::message_dialog_options values that specifies which display and association options will be used for the message box. You may pass in 0 if you wish to use the defaults.
      [[nodiscard]] auto options() const noexcept -> xtd::forms::message_dialog_options;
      /// @brief Sets options will be used for the message box.
      /// @param value One of the xtd::forms::message_dialog_options values that specifies which display and association options will be used for the message box. You may pass in 0 if you wish to use the defaults.
      /// @return Current message dialog.
      auto options(xtd::forms::message_dialog_options value) -> message_dialog&;
      
      /// @brief Gets the text message.
      /// @return The text message.
      [[nodiscard]] auto message() const noexcept -> xtd::string;
      /// @brief Sets the text message.
      /// @param value The text message.
      /// @return Current message_dialog instance.
      auto message(const xtd::string& value) -> message_dialog&;
      
      /// @brief Gets the dialog caption text.
      /// @return The current dialog caption text.
      [[nodiscard]] auto text() const noexcept -> xtd::string;
      /// @brief Sets the dialog caption text.
      /// @param value The new dialog caption text.
      /// @return Current message_dialog instance.
      auto text(const xtd::string& value) -> message_dialog&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Resets all properties to empty string.
      void reset();
      
      /// @brief Runs message dialog box.
      auto show_dialog() -> xtd::forms::dialog_result;
      /// @brief Runs message dialog box.
      auto show_dialog(const xtd::forms::iwin32_window& owner) -> xtd::forms::dialog_result;
      /// @brief Runs message dialog box.
      auto show_sheet(const iwin32_window& owner) -> void;
      /// @brief Runs message dialog box.
      auto show_sheet_dialog(const xtd::forms::iwin32_window& owner) -> xtd::forms::dialog_result;
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the user clicks the Help button on a common dialog box.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<message_dialog, xtd::forms::help_event_handler> help_request;
      
      /// @brief Occurs when the user close a message dialog box with dialog close button or other dialog buttons.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<message_dialog, xtd::forms::dialog_closed_event_handler> dialog_closed;
      /// @}
      
    private:
      /// @cond
      friend struct ::__xtd_forms_message_dialog_closed_caller__;
      /// @endcond
      
      /// @brief Raises the message_dialog::dialog_close event.
      /// @param e An message_dialog_close_event_args that provides the event data.
      /// @remarks This method is invoked when the message dialog box is closed.
      auto on_dialog_closed(const xtd::forms::dialog_closed_event_args& e) -> void;
      
      xtd::sptr<data> data_;
    };
  }
}

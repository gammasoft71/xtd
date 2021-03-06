#pragma once
#include <string>
#include <xtd/delegate.h>
#include "component.h"
#include "dialog_style.h"
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
    class message_dialog_closed_event_args final : public event_args {
    public:
      message_dialog_closed_event_args() = default;
      explicit message_dialog_closed_event_args(forms::dialog_result dialog_result) : dialog_result_(dialog_result) {};
      
      virtual forms::dialog_result dialog_result() const {return dialog_result_;}
      
    private:
      forms::dialog_result dialog_result_ = forms::dialog_result::none;
    };
    
    template<typename type_t>
    using message_dialog_closed_event_handler = delegate<void(type_t, const message_dialog_closed_event_args& e)>;
  
  /// @brief Represents a common dialog box that displays message box.
    /// @par Example
    /// The following code example demonstrate the use of message_dialog dialog.
    /// @include message_dialog.cpp
    class forms_export_ message_dialog final : public component {
    public:
      /// @brief Initializes a new instance of the message_dialog class.
      message_dialog() = default;

      xtd::forms::message_dialog_buttons buttons() const {return buttons_;}
      message_dialog& buttons(xtd::forms::message_dialog_buttons buttons) {
        if (buttons_ != buttons)
          buttons_ = buttons;
        return *this;
      }
      
      xtd::forms::message_dialog_default_button default_button() const {return default_button_;}
      message_dialog& default_button(xtd::forms::message_dialog_default_button default_button) {
        if (default_button_ != default_button)
          default_button_ = default_button;
        return *this;
      }
      
      bool display_help_button() const {return display_help_button_;}
      message_dialog& display_help_button(bool display_help_button) {
        if (display_help_button_ != display_help_button)
          display_help_button_ = display_help_button;
        return *this;
      }

      xtd::forms::dialog_style dialog_style() const {return dialog_style_;}
      message_dialog& dialog_style(xtd::forms::dialog_style dialog_style) {
        if (dialog_style_ != dialog_style)
          dialog_style_ = dialog_style;
        return *this;
      }
      
      xtd::forms::message_dialog_icon icon() const {return icon_;}
      message_dialog& icon(xtd::forms::message_dialog_icon icon) {
        if (icon_ != icon)
          icon_ = icon;
        return *this;
      }
      
      xtd::forms::message_dialog_options options() const {return options_;}
      message_dialog& options(xtd::forms::message_dialog_options options) {
        if (options_ != options)
          options_ = options;
        return *this;
      }
      
      /// @brief Gets the text message.
      /// @return The text message.
      std::string messsage() const {return message_;}
      /// @brief Sets the text message.
      /// @param message The text message.
      /// @return Current message_dialog instance.
      message_dialog& message(const std::string& message) {
        if (message_ != message)
          message_ = message;
        return *this;
      }
      
      /// @brief Gets the dialog caption text.
      /// @return The current dialog caption text.
      std::string text() const {return text_;}
      /// @brief Sets the dialog caption text.
      /// @param text The new dialog caption text.
      /// @return Current message_dialog instance.
      message_dialog& text(const std::string& text) {
        if (text_ != text)
          text_ = text;
        return *this;
      }

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

      /// @brief Occurs when the user clicks the Help button on a common dialog box.
      event<message_dialog, help_event_handler<message_dialog&>> help_request;
      
      event<message_dialog, message_dialog_closed_event_handler<message_dialog&>> message_dialog_closed;
      
    private:
      /// @cond
      friend struct ::__xtd_forms_message_dialog_closed_caller__;
      /// @endcond
      
      /// @brief Raises the close event.
      /// @param e An common_dialog_close_event_args that provides the event data.
      /// @remarks This method is invoked when the common dialog box is closed.
      virtual void on_message_dialog_closed(const message_dialog_closed_event_args& e) {
        dialog_result_ = e.dialog_result();
        message_dialog_closed(*this, e);
      }

      xtd::forms::message_dialog_buttons buttons_ = xtd::forms::message_dialog_buttons::ok;
      xtd::forms::message_dialog_default_button default_button_ = xtd::forms::message_dialog_default_button::button1;
      xtd::forms::dialog_result dialog_result_ = xtd::forms::dialog_result::none;
      xtd::forms::dialog_style dialog_style_ = xtd::forms::dialog_style::system;
      bool display_help_button_ = false;
      xtd::forms::message_dialog_icon icon_ = xtd::forms::message_dialog_icon::none;
      xtd::forms::message_dialog_options options_ = static_cast<xtd::forms::message_dialog_options>(0);
      std::string message_;
      std::string text_;
    };
  }
}

#pragma once
#include "common_dialog.h"

/// @cond
struct __xtd_forms_input_dialog_closed_caller__;
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class input_dialog_closed_event_args : public event_args {
    public:
      input_dialog_closed_event_args() = default;
      input_dialog_closed_event_args(forms::dialog_result dialog_result, const std::string& value) : dialog_result_(dialog_result), value_(value) {};
      
      /// @cond
      input_dialog_closed_event_args(const input_dialog_closed_event_args& form_closed_event_args) = default;
      input_dialog_closed_event_args& operator=(const input_dialog_closed_event_args& form_closed_event_args) = default;
      /// @endcond
      
      forms::dialog_result dialog_result() const {return dialog_result_;}
      std::string value() const {return value_;}

    private:
      forms::dialog_result dialog_result_ = forms::dialog_result::none;
      std::string value_;
    };

    template<typename type_t>
    using input_dialog_closed_event_handler = delegate<void(type_t, const input_dialog_closed_event_args& e)>;

  
    /// @brief Represents a common dialog box that displays input box.
    /// @par Example
    /// The following code example demonstrate the use of input_dialog dialog.
    /// @include input_dialog.cpp
    class input_dialog {
    public:
      /// @brief Initializes a new instance of the input_dialog class.
      input_dialog() = default;
      
      /// @brief Gets the caption.
      /// @return The product name.
      std::string caption() const {return text_;}
      /// @brief Sets the caption.
      /// @param caption The caption.
      /// @return Current input_dialog instance.
      input_dialog& caption(const std::string& caption) {
        caption_ = caption;
        return *this;
      }

      bool multiline() const {return multiline_;}
      void multiline(bool multiline) {multiline_ = multiline;}

      /// @brief Gets the text message.
      /// @return The text message.
      std::string text() const {return caption_;}
      /// @brief Sets the text message.
      /// @param text The text message.
      /// @return Current input_dialog instance.
      input_dialog& text(const std::string& text) {
        text_ = text;
        return *this;
      }
      
      bool use_system_password_char() const {return use_system_password_char_;}
      void use_system_password_char(bool use_system_password_char) {use_system_password_char_ = use_system_password_char;}
      
      /// @brief Gets the value.
      /// @return The value.
      std::string value() const {return value_;}
      /// @brief Sets thevalue.
      /// @param value The value.
      /// @return Current input_dialog instance.
      input_dialog& value(const std::string& value) {
        value_ = value;
        return *this;
      }

      event<input_dialog, input_dialog_closed_event_handler<input_dialog&>> input_dialog_closed;

      /// @brief Resets all properties to empty string.
      void reset();
      
      dialog_result show_dialog();
      dialog_result show_dialog(const iwin32_window& owner);
      void show_sheet_dialog(const iwin32_window& owner);

    protected:
      /// @cond
      friend struct ::__xtd_forms_input_dialog_closed_caller__;
      /// @endcond
      virtual void on_input_dialog_closed(const input_dialog_closed_event_args& e) {
        input_dialog_closed(*this, e);
      }

      std::string caption_;
      bool multiline_ = false;
      std::string text_;
      bool use_system_password_char_ = false;
      std::string value_;
    };
  }
}

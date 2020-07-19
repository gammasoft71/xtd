#pragma once
#include "common_dialog.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays input box.
    /// @par Example
    /// The following code example demonstrate the use of input_box dialog.
    /// @include input_box.cpp
    class input_box : public common_dialog {
    public:
      /// @brief Initializes a new instance of the input_box class.
      input_box() = default;
      
      /// @brief Gets the caption.
      /// @return The product name.
      std::string caption() const {return this->text_;}
      /// @brief Sets the caption.
      /// @param caption The caption.
      /// @return Current input_box instance.
      input_box& caption(const std::string& caption) {
        caption_ = caption;
        return *this;
      }

      bool multiline() const {return multiline_;}
      void multiline(bool multiline) {multiline_ = multiline;}

      /// @brief Gets the text message.
      /// @return The text message.
      std::string text() const {return this->caption_;}
      /// @brief Sets the text message.
      /// @param text The text message.
      /// @return Current input_box instance.
      input_box& text(const std::string& text) {
        text_ = text;
        return *this;
      }
      
      bool use_system_password_char() const {return use_system_password_char_;}
      void use_system_password_char(bool use_system_password_char) {use_system_password_char_ = use_system_password_char;}
      
      /// @brief Gets the value.
      /// @return The value.
      std::string value() const {return this->value_;}
      /// @brief Sets thevalue.
      /// @param value The value.
      /// @return Current input_box instance.
      input_box& value(const std::string& value) {
        value_ = value;
        return *this;
      }

      /// @brief Resets all properties to empty string.
      void reset() override;
      
    protected:
      /// @brief When overridden in a derived class, specifies a common dialog box.
      /// @param owner A value that represents the window handle of the owner window for the common dialog box.
      /// @return true if the dialog box was successfully run; otherwise, false.
      bool run_dialog(intptr_t owner) override;

      std::string caption_;
      bool multiline_ = false;
      std::string text_;
      bool use_system_password_char_ = false;
      std::string value_;
    };
  }
}

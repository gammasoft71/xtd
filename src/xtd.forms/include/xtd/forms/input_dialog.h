/// @file
/// @brief Contains xtd::forms::input_dialog dialog.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <string>
#include <xtd/delegate.h>
#include "dialog_style.h"
#include "character_casing.h"
#include "common_dialog.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays input box.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Examples
    /// The following code example demonstrate the use of input_dialog dialog.
    /// @include input_dialog.cpp
    /// @par Windows
    /// @image html input_dialog_w.png
    /// <br>
    /// @image html input_dialog_wd.png
    /// @par macOS
    /// @image html input_dialog_m.png
    /// <br>
    /// @image html input_dialog_md.png
    /// @par Gnome
    /// @image html input_dialog_g.png
    /// <br>
    /// @image html input_dialog_gd.png
    /// @par Examples
    /// The following code example demonstrate the use of input_dialog dialog with multiline.
    /// @include input_dialog_multiline.cpp
    /// @par Windows
    /// @image html input_dialog_multiline_w.png
    /// <br>
    /// @image html input_dialog_multiline_wd.png
    /// @par macOS
    /// @image html input_dialog_multiline_m.png
    /// <br>
    /// @image html input_dialog_multiline_md.png
    /// @par Gnome
    /// @image html input_dialog_multiline_g.png
    /// <br>
    /// @image html input_dialog_multiline_gd.png
    /// @par Examples
    /// The following code example demonstrate the use of input_dialog dialog with password.
    /// @include input_dialog_password.cpp
    /// @par Windows
    /// @image html input_dialog_password_w.png
    /// <br>
    /// @image html input_dialog_password_wd.png
    /// @par macOS
    /// @image html input_dialog_passwordpassword_m.png
    /// <br>
    /// @image html input_dialog_password_md.png
    /// @par Gnome
    /// @image html input_dialog_password_g.png
    /// <br>
    /// @image html input_dialog_multiline_gd.png
    class forms_export_ input_dialog : public common_dialog {
    public:
      /// @brief Initializes a new instance of the input_dialog class.
      input_dialog() = default;

      /// @brief Gets the character casing.
      /// @return One of the xtd::forms::character_casing values. The default value is xtd::forms::character_casing::normal.
      xtd::forms::character_casing character_casing() const {return character_casing_;}
      /// @brief Sets the character casing.
      /// @param dialog_style One of the xtd::forms::character_casing values. The default value is xtd::forms::character_casing::normal.
      /// @return Current input instance.
      input_dialog& character_casing(xtd::forms::character_casing character_casing) {
        if (character_casing_ != character_casing) {
          character_casing_ = character_casing;
          switch (character_casing_) {
            case xtd::forms::character_casing::upper: value_ = xtd::strings::to_upper(value_); break;
            case xtd::forms::character_casing::lower: value_ = xtd::strings::to_lower(value_); break;
            default: break;
          }
        }
        return *this;
      }
      
      /// @brief Gets the dialog style.
      /// @return One of the xtd::forms::dialog_style values. The default value is xtd::forms::dialog_style::standard.
      xtd::forms::dialog_style dialog_style() const {return dialog_style_;}
      /// @brief Sets the dialog style.
      /// @param dialog_style One of the xtd::forms::dialog_style values. The default value is xtd::forms::dialog_style::standard.
      /// @return Current input instance.
      input_dialog& dialog_style(xtd::forms::dialog_style dialog_style) {
        if (dialog_style_ != dialog_style)
          dialog_style_ = dialog_style;
        return *this;
      }
      
      /// @brief Gets multiline status.
      /// @return true if dialoog text box is multiline; otherwise false.
      /// @remarks The default value is false.
      bool multiline() const {return multiline_;}
      /// @brief Sets multiline status.
      /// @param multiline true if dialoog text box is multiline; otherwise false.
      /// @return Current input_dialog instance.
      /// @remarks The default value is false.
      input_dialog& multiline(bool multiline) {
        if (multiline_ != multiline)
          multiline_ = multiline;
        return *this;
      }

      /// @brief Gets the text message.
      /// @return The text message.
      std::string messsage() const {return message_;}
      /// @brief Sets the text message.
      /// @param message The text message.
      /// @return Current input_dialog instance.
      input_dialog& message(const std::string& message) {
        if (message_ != message)
          message_ = message;
        return *this;
      }
      
      /// @brief Gets the dialog caption text.
      /// @return The current dialog caption text.
      std::string text() const {return text_;}
      /// @brief Sets the dialog caption text.
      /// @param text The new dialog caption text.
      /// @return Current input_dialog instance.
      input_dialog& text(const std::string& text) {
        if (text_ != text)
          text_ = text;
        return *this;
      }

      /// @brief Gets use system password char status.
      /// @return true if dialoog text box use system password char status; otherwise false.
      /// @remarks The default value is false.
      bool use_system_password_char() const {return use_system_password_char_;}
      /// @brief Sets use system password char status.
      /// @param use_system_password_char true if dialoog text box use system password char status; otherwise false.
      /// @return Current input_dialog instance.
      /// @remarks The default value is false.
      input_dialog&  use_system_password_char(bool use_system_password_char) {
        use_system_password_char_ = use_system_password_char;
        return *this;
      }
      
      /// @brief Gets the value.
      /// @return The value.
      std::string value() const {return value_;}
      /// @brief Sets thevalue.
      /// @param value The value.
      /// @return Current input_dialog instance.
      input_dialog& value(const std::string& value) {
        if (value != value_) {
          switch (character_casing_) {
            case xtd::forms::character_casing::normal: value_ = value; break;
            case xtd::forms::character_casing::upper: value_ = xtd::strings::to_upper(value); break;
            case xtd::forms::character_casing::lower: value_ = xtd::strings::to_lower(value); break;
          }
        }
        return *this;
      }

      /// @brief Gets word wrap status.
      /// @return true if dialoog text box is word wrap; otherwise false.
      /// @remarks The default value is true.
      bool word_wrap() const {return word_wrap_;}
      /// @brief Sets word wrap status.
      /// @param word_wrap true if dialoog text box is word wrap; otherwise false.
      /// @return Current input_dialog instance.
      /// @remarks The default value is true.
      input_dialog& word_wrap(bool word_wrap) {
        if (word_wrap_ != word_wrap)
          word_wrap_ = word_wrap;
        return *this;
      }
      
      /// @brief Resets all properties to empty string.
      void reset() override;

    protected:
      bool run_dialog(intptr_t owner) override;
      void run_sheet(intptr_t owner) override;

      /// @cond
      xtd::forms::character_casing character_casing_ = xtd::forms::character_casing::normal;
      xtd::forms::dialog_style dialog_style_ = xtd::forms::dialog_style::standard;
      bool multiline_ = false;
      std::string message_;
      std::string text_;
      bool use_system_password_char_ = false;
      xtd::ustring value_;
      bool word_wrap_ = true;
      /// @endcond
    };
  }
}

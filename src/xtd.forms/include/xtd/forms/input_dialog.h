/// @file
/// @brief Contains xtd::forms::input_dialog dialog.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "dialog_appearance.h"
#include "character_casing.h"
#include "common_dialog.h"
#include <xtd/delegate>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays input dialog.
    /// @par Header
    /// @code #include <xtd/forms/input_dialog> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                  | macOS                                    | Gnome                                    |
    /// | ----- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- |
    /// | Light |  @image html dialog_input_dialog_w.png   |  @image html dialog_input_dialog_m.png   |  @image html dialog_input_dialog_g.png   |
    /// | Dark  |  @image html dialog_input_dialog_wd.png  |  @image html dialog_input_dialog_md.png  |  @image html dialog_input_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of input_dialog dialog.
    /// @include input_dialog.cpp
    /// @par Examples
    /// The following code example demonstrates the use of input_dialog dialog with multiline.
    /// @include input_dialog_multiline.cpp
    /// @par Examples
    /// The following code example demonstrates the use of input_dialog dialog with password.
    /// @include input_dialog_password.cpp
    class forms_export_ input_dialog : public common_dialog {
      struct data;
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the input_dialog class.
      input_dialog();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the character casing.
      /// @return One of the xtd::forms::character_casing values. The default value is xtd::forms::character_casing::normal.
      xtd::forms::character_casing character_casing() const noexcept;
      /// @brief Sets the character casing.
      /// @param dialog_appearance One of the xtd::forms::character_casing values. The default value is xtd::forms::character_casing::normal.
      /// @return Current input instance.
      input_dialog& character_casing(xtd::forms::character_casing character_casing);
      
      /// @brief Gets the dialog appearance.
      /// @return One of the xtd::forms::dialog_appearance values. The default value is xtd::forms::dialog_appearance::standard.
      xtd::forms::dialog_appearance dialog_appearance() const noexcept;
      /// @brief Sets the dialog appearance.
      /// @param dialog_appearance One of the xtd::forms::dialog_appearance values. The default value is xtd::forms::dialog_appearance::standard.
      /// @return Current input instance.
      input_dialog& dialog_appearance(xtd::forms::dialog_appearance dialog_appearance);
      
      /// @brief Gets multiline status.
      /// @return true if dialog text box is multiline; otherwise false.
      /// @remarks The default value is false.
      bool multiline() const noexcept;
      /// @brief Sets multiline status.
      /// @param multiline true if dialog text box is multiline; otherwise false.
      /// @return Current input_dialog instance.
      /// @remarks The default value is false.
      input_dialog& multiline(bool multiline);
      
      /// @brief Gets the text message.
      /// @return The text message.
      xtd::ustring message() const noexcept;
      /// @brief Sets the text message.
      /// @param message The text message.
      /// @return Current input_dialog instance.
      input_dialog& message(const xtd::ustring& message);
      
      /// @brief Gets the dialog caption text.
      /// @return The current dialog caption text.
      xtd::ustring text() const noexcept;
      /// @brief Sets the dialog caption text.
      /// @param text The new dialog caption text.
      /// @return Current input_dialog instance.
      input_dialog& text(const xtd::ustring& text);
      
      /// @brief Gets use system password char status.
      /// @return true if dialog text box use system password char status; otherwise false.
      /// @remarks The default value is false.
      bool use_system_password_char() const noexcept;
      /// @brief Sets use system password char status.
      /// @param use_system_password_char true if dialog text box use system password char status; otherwise false.
      /// @return Current input_dialog instance.
      /// @remarks The default value is false.
      input_dialog&  use_system_password_char(bool use_system_password_char);
      
      /// @brief Gets the value.
      /// @return The value.
      xtd::ustring value() const noexcept;
      /// @brief Sets the value.
      /// @param value The value.
      /// @return Current input_dialog instance.
      input_dialog& value(const xtd::ustring& value);
      
      /// @brief Gets word wrap status.
      /// @return true if dialog text box is word wrap; otherwise false.
      /// @remarks The default value is true.
      bool word_wrap() const noexcept;
      /// @brief Sets word wrap status.
      /// @param word_wrap true if dialog text box is word wrap; otherwise false.
      /// @return Current input_dialog instance.
      /// @remarks The default value is true.
      input_dialog& word_wrap(bool word_wrap);
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Resets all properties to empty string.
      void reset() noexcept override;
      /// @}
      
    protected:
      /// @name Protected Methods
      
      /// @{
      bool run_dialog(intptr owner) override;
      void run_sheet(intptr owner) override;
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}

/// @file
/// @brief Contains xtd::forms::input_dialog dialog.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
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
    /// @brief Represents a common dialog box that displays input dialog.
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
    ///     <td>@image html dialog_input_dialog_w.png</td>
    ///     <td>@image html dialog_input_dialog_m.png</td>
    ///     <td>@image html dialog_input_dialog_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <th>Dark</th>
    ///     <td>@image html dialog_input_dialog_wd.png</td>
    ///     <td>@image html dialog_input_dialog_md.png</td>
    ///     <td>@image html dialog_input_dialog_gd.png</td>
    ///   </tr>
    /// </table>
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
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the input_dialog class.
      input_dialog() = default;
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the character casing.
      /// @return One of the xtd::forms::character_casing values. The default value is xtd::forms::character_casing::normal.
      xtd::forms::character_casing character_casing() const noexcept;
      /// @brief Sets the character casing.
      /// @param dialog_style One of the xtd::forms::character_casing values. The default value is xtd::forms::character_casing::normal.
      /// @return Current input instance.
      input_dialog& character_casing(xtd::forms::character_casing character_casing);
      
      /// @brief Gets the dialog style.
      /// @return One of the xtd::forms::dialog_style values. The default value is xtd::forms::dialog_style::standard.
      xtd::forms::dialog_style dialog_style() const noexcept;
      /// @brief Sets the dialog style.
      /// @param dialog_style One of the xtd::forms::dialog_style values. The default value is xtd::forms::dialog_style::standard.
      /// @return Current input instance.
      input_dialog& dialog_style(xtd::forms::dialog_style dialog_style);
      
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
      
      /// @name Methods
      
      /// @{
      /// @brief Resets all properties to empty string.
      void reset() noexcept override;
      /// @}
      
    protected:
      /// @name Protected methods
      
      /// @{
      bool run_dialog(intptr owner) override;
      void run_sheet(intptr owner) override;
      /// @}
      
    private:
      struct data {
        xtd::forms::character_casing character_casing = xtd::forms::character_casing::normal;
        xtd::forms::dialog_style dialog_style = xtd::forms::dialog_style::standard;
        bool multiline = false;
        xtd::ustring message;
        xtd::ustring text;
        bool use_system_password_char = false;
        xtd::ustring value;
        bool word_wrap = true;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}

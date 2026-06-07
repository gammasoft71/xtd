/// @file
/// @brief Contains xtd::forms::input_dialog dialog.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "dialog_appearance.hpp"
#include "character_casing.hpp"
#include "common_dialog.hpp"
#include <xtd/delegate>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays input dialog.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/input_dialog>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                  | macOS                                    | Gnome                                    |
    /// | ----- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- |
    /// | Light |  @image html dialog_input_dialog_w.png   |  @image html dialog_input_dialog_m.png   |  @image html dialog_input_dialog_g.png   |
    /// | Dark  |  @image html dialog_input_dialog_wd.png  |  @image html dialog_input_dialog_md.png  |  @image html dialog_input_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of input_dialog dialog.
    /// @include input_dialog.cpp
    /// @par Examples
    /// The following code example demonstrates the use of input_dialog dialog with multiline.
    /// @include input_dialog_multiline.cpp
    /// @par Examples
    /// The following code example demonstrates the use of input_dialog dialog with password.
    /// @include input_dialog_password.cpp
    class forms_export_ input_dialog : public xtd::forms::common_dialog {
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
      [[nodiscard]] auto character_casing() const noexcept -> xtd::forms::character_casing;
      /// @brief Sets the character casing.
      /// @param value One of the xtd::forms::character_casing values. The default value is xtd::forms::character_casing::normal.
      /// @return Current input instance.
      auto character_casing(xtd::forms::character_casing value) -> input_dialog&;
      
      /// @brief Gets the dialog appearance.
      /// @return One of the xtd::forms::dialog_appearance values. The default value is xtd::forms::dialog_appearance::standard.
      [[nodiscard]] auto dialog_appearance() const noexcept -> xtd::forms::dialog_appearance;
      /// @brief Sets the dialog appearance.
      /// @param value One of the xtd::forms::dialog_appearance values. The default value is xtd::forms::dialog_appearance::standard.
      /// @return Current input instance.
      auto dialog_appearance(xtd::forms::dialog_appearance value) -> input_dialog&;
      
      /// @brief Gets multiline status.
      /// @return `true` if dialog text box is multiline; otherwise `false`.
      /// @remarks The default value is `false`.
      [[nodiscard]] auto multiline() const noexcept -> bool;
      /// @brief Sets multiline status.
      /// @param value `true` if dialog text box is multiline; otherwise `false`.
      /// @return Current input_dialog instance.
      /// @remarks The default value is `false`.
      auto multiline(bool value) -> input_dialog&;
      
      /// @brief Gets the text message.
      /// @return The text message.
      [[nodiscard]] auto message() const noexcept -> xtd::string;
      /// @brief Sets the text message.
      /// @param value The text message.
      /// @return Current input_dialog instance.
      auto message(const xtd::string& value) -> input_dialog&;
      
      /// @brief Gets the dialog caption text.
      /// @return The current dialog caption text.
      [[nodiscard]] auto text() const noexcept -> xtd::string;
      /// @brief Sets the dialog caption text.
      /// @param value The new dialog caption text.
      /// @return Current input_dialog instance.
      auto text(const xtd::string& value) -> input_dialog&;
      
      /// @brief Gets use system password char status.
      /// @return `true` if dialog text box use system password char status; otherwise `false`.
      /// @remarks The default value is `false`.
      [[nodiscard]] auto use_system_password_char() const noexcept -> bool;
      /// @brief Sets use system password char status.
      /// @param value `true` if dialog text box use system password char status; otherwise `false`.
      /// @return Current input_dialog instance.
      /// @remarks The default value is `false`.
      auto  use_system_password_char(bool value) -> input_dialog&;
      
      /// @brief Gets the value.
      /// @return The value.
      [[nodiscard]] auto value() const noexcept -> xtd::string;
      /// @brief Sets the value.
      /// @param value The value.
      /// @return Current input_dialog instance.
      auto value(const xtd::string& value) -> input_dialog&;
      
      /// @brief Gets word wrap status.
      /// @return `true` if dialog text box is word wrap; otherwise `false`.
      /// @remarks The default value is `true`.
      [[nodiscard]] auto word_wrap() const noexcept -> bool;
      /// @brief Sets word wrap status.
      /// @param value `true` if dialog text box is word wrap; otherwise `false`.
      /// @return Current input_dialog instance.
      /// @remarks The default value is `true`.
      auto word_wrap(bool value) -> input_dialog&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Resets all properties to empty string.
      auto reset() noexcept -> void override;
      /// @}
      
    protected:
      /// @name Protected Methods
      
      /// @{
      /// @brief When overridden in a derived class, specifies a common dialog box.
      /// @param owner A value that represents the window handle of the owner window for the common dialog box.
      /// @return `true` if the dialog box was successfully run; otherwise, `false`.
      auto run_dialog(xtd::intptr owner) -> bool override;
      
      /// @brief When overridden in a derived class, specifies a common dialog box.
      /// @param owner A value that represents the window handle of the owner window for the common dialog box.
      auto run_sheet(xtd::intptr owner) -> void override;
      /// @}
      
    private:
      xtd::sptr<data> data_;
    };
  }
}

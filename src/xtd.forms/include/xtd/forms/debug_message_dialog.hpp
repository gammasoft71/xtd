/// @file
/// @brief Contains xtd::forms::debug_message_dialog dialog.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "message_dialog.hpp"
#include <xtd/diagnostics/debug>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Displays a message window and write debug, which presents a debug message to the user.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/debug_message_dialog>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs debug
    /// @par Appearance
    /// |       | Windows                                       | macOS                                         | Gnome                                         |
    /// | ----- | --------------------------------------------- | --------------------------------------------- | --------------------------------------------- |
    /// | Light |  @image html dialog_debug_message_box_w.png   |  @image html dialog_debug_message_box_m.png   |  @image html dialog_debug_message_box_g.png   |
    /// | Dark  |  @image html dialog_debug_message_box_wd.png  |  @image html dialog_debug_message_box_md.png  |  @image html dialog_debug_message_box_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of debug_message_dialog dialog.
    /// @include debug_message_dialog.cpp
    class forms_export_ debug_message_dialog final : public xtd::forms::component {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the debug_message_dialog class.
      debug_message_dialog();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets async dialog_result result after dialog box is closing.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      [[nodiscard]] auto dialog_result() const noexcept -> xtd::forms::dialog_result;
      
      /// @brief Gets the text message.
      /// @return The text message.
      [[nodiscard]] auto message() const noexcept -> xtd::string;
      /// @brief Sets the text message.
      /// @param message The text message.
      /// @return Current debug_message_dialog instance.
      auto message(const xtd::string& message) -> debug_message_dialog& {
        #if DEBUG
        dialog_.message(message);
        #endif
        return *this;
      }
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Resets all properties to empty string.
      auto reset() -> void;
      
      /// @brief Runs message dialog box.
      auto show_dialog() -> xtd::forms::dialog_result {
        #if DEBUG
        xtd::diagnostics::debug::write_line(dialog_.message());
        return dialog_.show_dialog();
        #else
        return xtd::forms::dialog_result::none;
        #endif
      }
      /// @brief Runs message dialog box.
      auto show_dialog(const xtd::forms::iwin32_window& owner) -> xtd::forms::dialog_result {
        #if DEBUG
        xtd::diagnostics::debug::write_line(dialog_.message());
        return dialog_.show_dialog(owner);
        #else
        return xtd::forms::dialog_result::none;
        #endif
      }
      /// @brief Runs message dialog box.
      auto show_sheet(const xtd::forms::iwin32_window& owner) -> void {
        #if DEBUG
        xtd::diagnostics::debug::write_line(dialog_.message());
        dialog_.show_sheet(owner);
        #endif
      }
      /// @brief Runs message dialog box.
      auto show_sheet_dialog(const xtd::forms::iwin32_window& owner) -> xtd::forms::dialog_result {
        #if DEBUG
        xtd::diagnostics::debug::write_line(dialog_.message());
        return dialog_.show_sheet_dialog(owner);
        #else
        return xtd::forms::dialog_result::none;
        #endif
      }
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the user close a message dialog box with dialog close button or other dialog buttons.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<debug_message_dialog, xtd::forms::dialog_closed_event_handler> dialog_closed;
      /// @}
      
    private:
      auto on_dialog_closed(const xtd::forms::dialog_closed_event_args& e) -> void;
      
      message_dialog dialog_;
    };
  }
}
